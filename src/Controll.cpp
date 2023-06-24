#include "Controll.h"
#include "Consts.h"
#include <unordered_map>
#include "Resources.h"

// Constructor
Controll::Controll() : m_window(sf::VideoMode(Window_Width, Window_Height), "twin-shot", sf::Style::Close | sf::Style::Titlebar),
m_indexCharacter(0)
{
    // Load and configure the music
    m_music.setBuffer(Resources::instance().getMusic(Resources::SOUND_MENU_MENU));
    m_music.setLoop(true);
    m_music.setVolume(100);
}

// Main game loop
void Controll::run()
{
    // Play the music if the flag is set
    if (m_musicStruct._turnOnMenu)
    {
        m_music.play();
    }

    // Draw the menu buttons
    m_buttons.drawMenuButtons(m_window);

    // Load the menu background texture
    sf::Texture texture;
    texture = Resources::instance().getTexture(Resources::MENUBG_MENU_BACKGROUND);

    // Create the background sprite and scale it to fit the window size
    sf::Sprite backgroundSprite(texture);
    backgroundSprite.setScale(((float)Window_Width) / texture.getSize().x,
        ((float)Window_Height) / texture.getSize().y);

    // Variables for mouse input handling
    sf::Vector2i mousePosition;
    sf::Vector2f worldMousePos;

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Update the code inside the event handling loop
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Get the mouse position in window coordinates and convert it to world coordinates
                        mousePosition = sf::Mouse::getPosition(m_window);
                        worldMousePos = m_window.mapPixelToCoords(mousePosition);

                        // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonBounds = m_buttons.getButtonBounds();

                        // Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonBounds.size(); ++i)
                        {
                            if (buttonBounds[i].contains(worldMousePos))
                            {
                                if (i == 0) // If "New Game" button is clicked
                                {
                                    // Stop the music and run the selectLevel function
                                    m_music.stop();
                                    selectLevel.run(m_indexCharacter, m_musicStruct);

                                    // Play the music again if the flag is set
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                }
                                else if (i == 1) // If "Design" button is clicked
                                {
                                    // Stop the music and run the design function
                                    m_music.stop();
                                    m_indexCharacter = m_design.run();

                                    // Play the music again if the flag is set
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                }
                                else if (i == 2) // If "Settings" button is clicked
                                {
                                    // Stop the music and run the settings function
                                    m_music.stop();
                                    m_settings.run(m_musicStruct);

                                    // Play the music again if the flag is set
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                }
                                else if (i == 3) // If "Help" button is clicked
                                {
                                    // Stop the music and run the help function
                                    m_music.stop();
                                    m_help.run();

                                    // Play the music again if the flag is set
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                }
                                else // If any other button is clicked, close the window
                                {
                                    m_window.close();
                                }
                            }
                        }
                    }
                }
            }
        }

        // Clear the window
        m_window.clear();

        // Draw the background image
        m_window.draw(backgroundSprite);

        // Draw the menu buttons
        for (const auto& button : m_buttons.getButtons())
        {
            m_window.draw(button);
        }

        // Display the updated window
        m_window.display();
    }
}

// Getter for the indexCharacter variable
int Controll::getIndexCharcter()
{
    return m_indexCharacter;
}
