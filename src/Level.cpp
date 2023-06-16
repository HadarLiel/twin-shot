#include "Level.h"
#include "Arrow.h"
#include "Brick.h"
#include "PassBrick.h"
#include "BlockBrick.h"
#include "FallBrick.h"

Level::Level(const std::string &mapName)
{
    sf::Image mapImage;
    mapImage.loadFromFile(mapName);
    m_map.restart(mapImage.getSize());
    for (unsigned int i = 0; i < mapImage.getSize().x; ++i)
    {
        for (unsigned int j = 0; j < mapImage.getSize().y; ++j)
        {
            if (mapImage.getPixel(i, j) == sf::Color::Black)
            {
                auto brick = new BlockBrick({ i,j });
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            if (mapImage.getPixel(i, j) == sf::Color::Blue)
            {
                auto brick = new PassBrick({ i,j }, &m_map);
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            if (mapImage.getPixel(i, j) == sf::Color::Yellow)
            {
                auto brick = new FallBrick({ i,j }, &m_map);
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }

            else if(mapImage.getPixel(i, j) == sf::Color::Green)
            {
                m_character = new Character({i*32, j*32}, 
                                            &m_map,
                                            [&](std::unique_ptr<Arrow> &&m)
                                            {
                                                m_map.addArrow(m.get());
                                                m_objects.push_back(std::move(m));
                                            }
                                            );
            }

            else if (mapImage.getPixel(i, j) == sf::Color::Red)
            {
                Monsters *monster = new Monsters({ i * 32, j * 32 }, &m_map);
                m_monsterList.push_back(monster);
                m_objects.push_back(std::unique_ptr<Monsters>(monster));
            }
        }
    }
    // push back at the end because character is the last to draw
    m_objects.push_back(std::unique_ptr<Object>(m_character));
}

void Level::run()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Twin Shot");
    window.setFramerateLimit(60);
    sf::View view;
    view.setSize(800, 600);

    sf::Clock clock;
    clock.restart();
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::erase_if(m_monsterList, [](Monsters* m) { return !m->isAlive(); });

    
        for(int i = 0; i < m_objects.size(); ++i)
        {
            m_objects[i]->update(deltaTime);
            if(!m_objects[i]->isAlive())
            {
                // todo: fix this
                m_map.removveArrow((Arrow*)(m_objects[i].get()));
                m_objects.erase(m_objects.begin() + i);
            }
        }

        for (int i = 0; i < m_objects.size(); i++)
        {
            for (int j = i+1; j < m_objects.size(); j++)
            {
                m_objects[i]->collide(*(m_objects[j]));

            }
        }

        view.setCenter(m_character->getCenter());
        window.setView(view);

        window.clear(sf::Color::White);
        
        
        for (auto &object : m_objects)
        {
            window.draw(*object);
            if (m_monsterList.empty())
            {
                //todo:fix when he need to mob=ve to the next level
                sf::View v;
                window.setView(v);
                sf::CircleShape hod(100);
                hod.setFillColor(sf::Color::Blue);
                window.draw(hod);
                window.setView(view);
            }
        }

        window.display();
    }
}
