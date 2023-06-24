#include "SelectLevel.h"
#include "SelectLevel.h"

SelectLevel::SelectLevel() : m_showTimeLose(sf::Time::Zero), m_showTimeWin(sf::Time::Zero), m_levelsOpen(0)
{
    // Constructor for the SelectLevel class

    // Create a rectangle shape for the buttons
    sf::RectangleShape rectangle(sf::Vector2f(150, 50));

    // Set the fill color of the rectangle shape to white with transparency
    sf::Color whiteColor(255, 255, 255, 200);
    rectangle.setFillColor(whiteColor);

    // Calculate the distance between buttons in the X and Y directions
    float disX = (float)Window_Width / (4 * 2); // 4 is the number of buttons I want to put in one line
    float disY = (float)Window_Height / (3 * 2); // 3 is the number of buttons I want to put in one column

    // Set the origin of the rectangle shape to its center
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    // Create the button rectangles for each level
    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        // Calculate the position of the button based on the button index and the distance between buttons
        rectangle.setPosition(disX + (i % 4) * disX * 2, disY + (i / 4) * disY * 2);

        // Set the fill color of the button rectangle based on the level's availability
        if (i > m_levelsOpen)
        {
            rectangle.setFillColor(sf::Color::Black);
        }

        // Add the button rectangle to the vector of button rectangles
        m_rectTexture.push_back(rectangle);
    }
}

void SelectLevel::run(int index, MusicStruct musicStruct)
{
    // Run function for the SelectLevel object

    // Set the index of the character and the music structure for the SelectLevel object
    m_indexCharacter = index;
    m_musicStruct = musicStruct;

    // Create the SFML window for the level selection screen
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Select Level");

    // Draw the background and buttons on the window
    m_buttons.draw_back_buttons_types(window);

    // Load the background texture
    sf::Texture texture;
    texture = Resources::instance().getTexture(Resources::MENUBG_MENU_BACKGROUND);

    // Create the background sprite and scale it to fit the window size
    sf::Sprite selectSprite(texture);
    selectSprite.setScale(((float)Window_Width) / texture.getSize().x, ((float)Window_Height) / texture.getSize().y);

    // Variables for handling mouse position and time
    sf::Vector2i mousePosition;
    sf::Vector2f worldMousePos;
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Calculate the delta time for frame rate independence
        sf::Time dTime = clock.restart();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Check if the window should be closed
            if (event.type == sf::Event::Closed)
            {
                window.close();
                m_showTimeLose = sf::Time::Zero;
                m_showTimeWin = sf::Time::Zero;
            }
            // Check if a mouse button was pressed
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the left mouse button was pressed
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get the mouse position and convert it to world coordinates
                    mousePosition = sf::Mouse::getPosition(window);
                    worldMousePos = window.mapPixelToCoords(mousePosition);

                    // Access the button bounds
                    const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getGameButtonBounds();

                    // Iterate over each button bounds to check if the mouse position is within any of them
                    for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
                    {
                        if (buttonTypesBounds[i].contains(worldMousePos))
                        {
                            if (i == 0) // If "back" button is pressed
                            {
                                window.close();
                            }
                        }
                    }

                    // Check if any of the level buttons were pressed
                    for (int i = 0; i < m_rectTexture.size(); i++)
                    {
                        if (m_rectTexture[i].getGlobalBounds().contains(worldMousePos))
                        {
                            // Check if the level is locked
                            if (i > m_levelsOpen)
                            {
                                break;
                            }

                            // Create a Level object with the selected level, character index, and music structure
                            Level level(i, m_indexCharacter, m_musicStruct);

                            // Run the level until it is completed or the player loses
                            while (level.run())
                            {
                                i++;

                                // Check if all levels have been completed
                                if (i >= NUM_OF_LEVELS)
                                {
                                    m_showTimeWin = sf::seconds(5);
                                    m_showTimeLose = sf::Time::Zero;
                                    break;
                                }

                                // Set the next level and increment the number of opened levels
                                level.setLevel(i);
                                m_levelsOpen++;

                                // Set the fill color of the completed level button to white
                                sf::Color whiteColor(255, 255, 255, 200);
                                m_rectTexture[i].setFillColor(whiteColor);
                            }

                            // Restart the clock to reset the time counters
                            clock.restart();

                            // Check if the player lost the level
                            if (m_showTimeWin < sf::seconds(5))
                            {
                                m_showTimeLose = sf::seconds(5);
                                m_showTimeWin = sf::Time::Zero;
                            }
                        }
                    }
                }
            }
        }

        // Update the time counters
        m_showTimeLose -= dTime;
        m_showTimeWin -= dTime;

        // Clear the window
        window.clear();

        // Draw the appropriate screen based on the time counters
        if (m_showTimeLose > sf::Time::Zero)
        {
            sf::Sprite loseSprite(Resources::instance().getTexture(Resources::LOSE_BACKGROUND));

            loseSprite.setScale(((float)Window_Width) / loseSprite.getTexture()->getSize().x,
                ((float)Window_Height) / loseSprite.getTexture()->getSize().y);

            window.draw(loseSprite);
        }
        else if (m_showTimeWin > sf::Time::Zero)
        {
            sf::Sprite winSprite(Resources::instance().getTexture(Resources::WIN_BACKGROUND));

            winSprite.setScale(((float)Window_Width) / winSprite.getTexture()->getSize().x,
                ((float)Window_Height) / winSprite.getTexture()->getSize().y);

            window.draw(winSprite);
        }
        else
        {
            // Draw the level selection screen
            window.draw(selectSprite);
            drawLevelsNumbers(window);

            // Draw the help buttons
            for (const auto& button : m_buttons.getHelpButtons())
            {
                window.draw(button);
            }
        }

        // Display the window
        window.display();
    }
}

void SelectLevel::drawLevelsNumbers(sf::RenderWindow& window) const
{
    // Draw the level numbers on the level selection screen

    // Load the font
    sf::Font font;
    font = Resources::instance().getFont();

    // Calculate the distance between buttons in the X and Y directions
    float disX = (float)Window_Width / (4 * 2); // 4 is the number of buttons I want to put in one line
    float disY = (float)Window_Height / (3 * 2); // 3 is the number of buttons I want to put in one column

    // Draw the level numbers for each level
    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        // Create a text object for the level number
        sf::Text levelIndex("Level: " + std::to_string(i + 1), font);

        // Set the origin of the text to its center
        sf::FloatRect textBounds = levelIndex.getLocalBounds();
        levelIndex.setOrigin(textBounds.width / 2, textBounds.height / 2);

        // Set the fill color of the level number text to blue
        levelIndex.setFillColor(sf::Color::Blue);

        // Calculate the position of the level number based on the level index and the distance between buttons
        levelIndex.setPosition(disX + (i % 4) * disX * 2, disY + (i / 4) * disY * 2);

        // Draw the level button rectangle and the level number text
        window.draw(m_rectTexture[i]);
        window.draw(levelIndex);
    }
}
