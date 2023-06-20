#include "Settings.h"


Settings::Settings()
{
}

void Settings::run(MusicStruct& musicStruct)
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Settings");

    //m_buttons.draw_settings_buttons_types(window);
    //m_buttons.draw_help_buttons_types(window);

    //// Load the game background image
    //const sf::Texture& backgroundTexture = Resources::instance().getTexture(Resources::DESIGNBG_START);

    //// Create the background sprite
    //sf::Sprite backgroundSprite(backgroundTexture);

    //backgroundSprite.setScale(((float)Window_Width) / backgroundTexture.getSize().x,
    //    ((float)Window_Height) / backgroundTexture.getSize().y
    //);

    //sf::Vector2i mousePosition;
    //// Convert mouse position to world coordinates
    //sf::Vector2f worldMousePos;

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //        else if (event.type == sf::Event::MouseButtonPressed)
    //        {

    //            // Update the code inside the event handling loop
    //            if (event.type == sf::Event::MouseButtonPressed)
    //            {

    //                if (event.mouseButton.button == sf::Mouse::Left)
    //                {
    //                    mousePosition = sf::Mouse::getPosition(window);
    //                    worldMousePos = window.mapPixelToCoords(mousePosition);

    //                    // Access the button bounds
    //                    const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getSettingsButtonBounds();

    //                    // Iterate over each button bounds to check if the mouse position is within any of them
    //                    for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
    //                    {
    //                        if (buttonTypesBounds[i].contains(worldMousePos))
    //                        {
    //                            std::cout << "press button" << i << "\n";

    //                            //toso:leave enum?
    //                            if (i == 0) //if "menu"
    //                            {
    //                                std::cout << "menu button\n";
    //                                musicStruct._turnOnMenu = !musicStruct._turnOnMenu;
    //                            }

    //                            if (i == 1)
    //                            {
    //                                std::cout << "game\n";
    //                                musicStruct._turnOnGame = !musicStruct._turnOnGame;
    //                            }

    //                        }
    //                    }

    //                    // Access the button bounds
    //                    const std::vector<sf::FloatRect>& buttonTypesBoundsBack = m_buttons.getGameButtonBounds();

    //                    // Iterate over each button bounds to check if the mouse position is within any of them
    //                    for (size_t i = 0; i < buttonTypesBoundsBack.size(); ++i)
    //                    {
    //                        if (buttonTypesBoundsBack[i].contains(worldMousePos))
    //                        {
    //                            std::cout << "press button" << i << "\n";

    //                            if (i == 0) //if "back"
    //                            {
    //                                std::cout << "back button\n";
    //                                window.close();
    //                            }

    //                        }
    //                    }

    //                  
    //                }


    //            }

    //        }
    //    }

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
                                        musicStruct._turnOnMenu = !musicStruct._turnOnMenu;

                                    }

                                    else if (i == 1)
                                    {
                                        
                                        std::cout << "game\n";
                                        musicStruct._turnOnGame = !musicStruct._turnOnGame;
                                        
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

        

        for (const auto& button : m_buttons.getSettingsButtons())
        {
            window.draw(button);
        }

        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }

        window.display();
    }

}
