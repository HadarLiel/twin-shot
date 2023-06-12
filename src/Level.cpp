#include "Level.h"
#include "Brick.h"
#include "BlueBrick.h"
#include "BlackBrick.h"

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
                auto brick = new BlackBrick({ i,j });
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            if (mapImage.getPixel(i, j) == sf::Color::Blue)
            {
                auto brick = new BlueBrick({ i,j }, &m_map);
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            else if(mapImage.getPixel(i, j) == sf::Color::Red)
            {
                m_character = new Character({i*32, j*32}, mapImage.getSize(), &m_map);
            }
        }
    }
    // push back at end because character is the last to draw
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
