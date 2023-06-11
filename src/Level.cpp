#include "Level.h"
#include "Brick.h"

Level::Level(const std::string &mapName)
{
    sf::Image map;
    map.loadFromFile(mapName);
    for (unsigned int i = 0; i < map.getSize().x; ++i)
    {
        for (unsigned int j = 0; j < map.getSize().y; ++j)
        {
            if (map.getPixel(i, j) == sf::Color::Black)
            {
                Brick* brick = new Brick({ i,j });
                m_bricksList.addBrick(brick);

                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            else if(map.getPixel(i, j) == sf::Color::Red)
            {
                m_character = new Character({i, j}, map.getSize(), &m_bricksList);

            }
        }
    }
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

        m_character->update(deltaTime);
        
        for (auto& object : m_objects)
        {
            m_character->collide(*object);
        }

        view.setCenter(m_character->getCenter());
        window.setView(view);

        window.clear(sf::Color::White);
        
        
        for (auto &object : m_objects)
        {
            window.draw(*object);
        }

        window.display();
    }
}
