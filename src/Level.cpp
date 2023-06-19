#include "Level.h"
#include "Arrow.h"
#include "Brick.h"
#include "BlueBrick.h"
#include "BlackBrick.h"
#include "YellowBrick.h"
#include "Consts.h"
#include "Resources.h"

//todo:get the correct index
Level::Level(const std::string &mapName, int index): m_indexCharacter(index)
{
    m_sound.setBuffer(Resources::instance().getMusic(Resources::SOUND_GAME_START + m_indexCharacter));
    m_sound.setLoop(true);
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
            if (mapImage.getPixel(i, j) == sf::Color::Yellow)
            {
                auto brick = new YellowBrick({ i,j }, &m_map);
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
                                            },
                                            m_indexCharacter
                                            );
            }

            else if (mapImage.getPixel(i, j) == sf::Color::Red)
            {
                Monsters *monster = new Monsters({ i * 32, j * 32 }, &m_map, m_indexCharacter);
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
    
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Twin Shot");
    m_sound.play();
    window.setFramerateLimit(60);
    sf::View view;
    view.setSize(800, 600);


    m_buttons.draw_help_buttons_types(window);

    sf::Clock clock;
    clock.restart();
    sf::Vector2i mousePosition;
    // Convert mouse position to world coordinates
    sf::Vector2f worldMousePos;

    sf::View buttonView;
    buttonView.setSize(window.getSize().x, window.getSize().y);


    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();////
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {

                // Update the code inside the event handling loop
                if (event.type == sf::Event::MouseButtonPressed)
                {

                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        
                        mousePosition = sf::Mouse::getPosition(window);
                        //worldMousePos = window.mapPixelToCoords(mousePosition);
                        worldMousePos = window.mapPixelToCoords(mousePosition, buttonView);

                        // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getGameButtonBounds();
                        std::cout << buttonTypesBounds.size()<<"\n";

                        // Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
                        {
                            if (buttonTypesBounds[i].contains(worldMousePos))
                            {
                                std::cout << "press button" << i << "\n";

                                if (i == 0) //if "back"
                                {
                                    std::cout << "back button\n";
                                    window.close();
                                }

                            }
                        }



                    }

                }

            }
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
                //todo:fix when he need to move to the next level
                sf::View v;
                window.setView(v);
                sf::CircleShape hod(100);
                hod.setFillColor(sf::Color::Blue);
                window.draw(hod);
                window.setView(view);
            }
        }

       
        // Switch to the button view
        window.setView(buttonView);

        // Draw the buttons
        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }

        // Switch back to the main game view
        window.setView(view);

        window.display();
    }
}
