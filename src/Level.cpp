#include "Level.h"
#include "Arrow.h"
#include "Brick.h"
#include "BlueBrick.h"
#include "BlackBrick.h"
#include "YellowBrick.h"
#include "Consts.h"
#include "Resources.h"

// Constructor
Level::Level(int levelIndex, int index, MusicStruct musicStruct) : m_indexCharacter(index), m_musicStruct(musicStruct)
{
    // Load and configure the sound for the game start based on the character index
    m_sound.setBuffer(Resources::instance().getMusic(Resources::SOUND_GAME_START + m_indexCharacter));
    m_sound.setLoop(true);
    m_sound.setVolume(100);

    // Set the level based on the level index
    setLevel(levelIndex);
}

// Run the game level
bool Level::run()
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Twin Shot");

    // Play the game sound if the flag is set
    if (m_musicStruct._turnOnGame)
    {
        m_sound.play();
    }

    window.setFramerateLimit(60);
    sf::View view;
    view.setSize(800, 600);

    // Draw the back buttons types
    m_buttons.draw_back_buttons_types(window);

    sf::Clock clock;
    clock.restart();
    sf::Vector2i mousePosition;
    sf::Vector2f worldMousePos;

    sf::View buttonView;
    buttonView.setSize(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
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
                        worldMousePos = window.mapPixelToCoords(mousePosition, buttonView);

                        // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getGameButtonBounds();

                        // Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
                        {
                            if (buttonTypesBounds[i].contains(worldMousePos))
                            {
                                if (i == 0) // If "back" button is clicked, close the window
                                {
                                    window.close();
                                }
                            }
                        }
                    }
                }
            }
        }

        // Remove non-alive monsters from the monster list
        std::erase_if(m_monsterList, [](Monster* m) { return !m->isAlive(); });

        // Check if all monsters are defeated
        if (m_monsterList.empty())
        {
            return true;
        }

        // Update and check the status of all objects
        for (int i = 0; i < m_objects.size(); ++i)
        {
            m_objects[i]->update(deltaTime);
            if (!m_objects[i]->isAlive())
            {
                m_map.removveArrow((Arrow*)(m_objects[i].get()));
                m_objects.erase(m_objects.begin() + i);
            }
        }

        // Perform collision checks between objects
        for (int i = 0; i < m_objects.size(); i++)
        {
            for (int j = i + 1; j < m_objects.size(); j++)
            {
                m_objects[i]->collide(*(m_objects[j]));
            }
        }

        // Check if the character is out of lives
        if (m_character->getLives() == 0)
        {
            return false;
        }

        // Update the view center to follow the character's position
        view.setCenter(m_character->getCenter());
        window.setView(view);

        // Clear the window
        window.clear(sf::Color::White);

        // Draw all objects in the level
        for (auto& object : m_objects)
        {
            window.draw(*object);
        }

        // Switch to the button view
        window.setView(buttonView);

        // Draw the buttons for help
        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }

        // Switch back to the main game view
        window.setView(view);

        // Display the updated window
        window.display();
    }

    return false;
}

// Set the level based on the provided index
void Level::setLevel(int index)
{
    m_levelIndex = index;
    m_monsterList.clear();
    m_objects.clear();

    // Load the map image for the level
    const sf::Image& mapImage = Resources::instance().getLevel(index);

    // Restart the game map and add bricks, characters, and monsters based on the pixel colors in the map image
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
            else if (mapImage.getPixel(i, j) == sf::Color::Blue)
            {
                auto brick = new BlueBrick({ i,j }, &m_map);
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            else if (mapImage.getPixel(i, j) == sf::Color::Yellow)
            {
                auto brick = new YellowBrick({ i,j }, &m_map);
                m_map.addBrick(brick);
                m_objects.push_back(std::unique_ptr<Object>(brick));
            }
            else if (mapImage.getPixel(i, j) == sf::Color::Green)
            {
                m_character = new Character({ i * 32, j * 32 },
                    &m_map,
                    [&](std::unique_ptr<Arrow>&& m)
                    {
                        m_map.addArrow(m.get());
                m_objects.push_back(std::move(m));
                    },
                    m_indexCharacter);
            }
            else if (mapImage.getPixel(i, j) == sf::Color::Red)
            {
                Monster* monster = new Monster({ i * 32, j * 32 }, &m_map, m_indexCharacter, false);
                m_monsterList.push_back(monster);
            }
            else if (mapImage.getPixel(i, j) == sf::Color::Magenta)
            {
                Monster* monster = new Monster({ i * 32, j * 32 }, &m_map, m_indexCharacter, true);
                m_monsterList.push_back(monster);
            }
        }
    }

    // Add the character and monsters to the objects list
    m_objects.push_back(std::unique_ptr<Object>(m_character));
    for (auto* monster : m_monsterList)
    {
        m_objects.emplace_back(monster);
    }
}
