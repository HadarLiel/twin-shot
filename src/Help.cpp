#include "Help.h"
#include "Consts.h"
#include <unordered_map>

Help::Help()
{

}

void Help::run()
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Help");

    m_buttons.draw_back_buttons_types(window);


    sf::Texture texture;
    texture = Resources::instance().getTexture(Resources::HELPBG_BACKGROUND);
    // Create the background sprite
    sf::Sprite helpSprite(texture);

    helpSprite.setScale(((float)Window_Width) / texture.getSize().x,
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
                        const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getGameButtonBounds();

                        // Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
                        {
                            if (buttonTypesBounds[i].contains(worldMousePos))
                            {

                                if (i == 0) //if "back"
                                {
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

        window.draw(helpSprite);

       
        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }


        window.display();
    }


}



