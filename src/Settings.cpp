#include "Settings.h"
#include "Consts.h"


Settings::Settings(): m_menuOn(true), m_gameOn(true)
{
    spriteMenu.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_MENU_ON));
    spriteGame.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_GAME_ON));
}

void Settings::run(MusicStruct& musicStruct)
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Settings");

    
        m_buttons.draw_settings_buttons_types(window);
        m_buttons.draw_help_buttons_types(window);

        sf::Texture texture;
        texture = Resources::instance().getTexture(Resources::MENUBG_MENU_BACKGROUND);
        // Create the background sprite
        sf::Sprite backgroundSprite(texture);

        backgroundSprite.setScale(((float)Window_Width) / texture.getSize().x,
            ((float)Window_Height) / texture.getSize().y);



        sf::Vector2i mousePosition;
        // Convert mouse position to world coordinates
        sf::Vector2f worldMousePos;


        while (window.isOpen())
        {
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
                            worldMousePos = window.mapPixelToCoords(mousePosition);



                            // Access the button bounds
                            const std::vector<sf::FloatRect>& buttonBounds = m_buttons.getSettingsButtonBounds();

                            //// Iterate over each button bounds to check if the mouse position is within any of them
                            for (size_t i = 0; i < buttonBounds.size(); ++i)
                            {

                                if (buttonBounds[i].contains(worldMousePos))
                                {
                                    //todo: do it like this?
                                    if (i == 0) //if "New Game"
                                    {
                                        std::cout << "menu button\n";
                                        m_menuOn = !m_menuOn;
                                        musicStruct._turnOnMenu = !musicStruct._turnOnMenu;

                                        if (m_menuOn)
                                        {
                                            spriteMenu.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_MENU_ON));
                                        }

                                        else
                                        {
                                            spriteMenu.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_MENU_OFF));
                                        }
                                    }

                                    else if (i == 1)
                                    {
                                        
                                        std::cout << "game\n";
                                        m_gameOn = !m_gameOn;
                                        musicStruct._turnOnGame = !musicStruct._turnOnGame;

                                        if (m_gameOn)
                                        {
                                            spriteGame.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_GAME_ON));
                                        }

                                        else
                                        {
                                            spriteGame.setTexture(Resources::instance().getTexture(Resources::BUTTONS_MUSIC_GAME_OFF));
                                        }
                                        
                                    }

                                    

                                }


                            }

                            // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonTypesBoundsBack = m_buttons.getGameButtonBounds();

                        // Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonTypesBoundsBack.size(); ++i)
                        {
                            if (buttonTypesBoundsBack[i].contains(worldMousePos))
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

        //---------------


        window.clear(); // Clear the window

        window.draw(backgroundSprite);

       
        // Access the button bounds
        const std::vector<sf::FloatRect>& buttonBounds = m_buttons.getSettingsButtonBounds();


        int NumOfButtons = Resources::BUTTONS_MUSIC_END - Resources::BUTTONS_MUSIC_START + 1;
        float totalButtonHeight = buttonHeight * NumOfButtons + 50 * (NumOfButtons - 1);
        float startY = (Window_Height - totalButtonHeight + 30) / 2.0f; // Center vertically

        for (int i = 0; i < NumOfButtons; i++)
        {
            float posX = (Window_Width - spriteMenu.getGlobalBounds().width) / 2.0f; // Center horizontally
            float posY = startY + i * (buttonHeight + 50) -400;

            //todo:change?
            spriteMenu.setPosition(posX, posY);//(posX, posY);

            spriteGame.setPosition(posX, posY +140);//(posX, posY);
        }


        window.draw(spriteMenu);
        window.draw(spriteGame);

        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }


        window.display();
    }

}
