#include "Help.h"
#include "Consts.h"
#include <unordered_map>

Help::Help()// :m_window(sf::VideoMode(Window_Width, Window_Height), "Design", sf::Style::Close | sf::Style::Titlebar)
{

}

void Help::run()
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Help");

    m_buttons.draw_help_buttons_types(window);




    // Load the game background image
    sf::Texture helpTexture;
    if (!helpTexture.loadFromFile("resources/help.png"))
    {
        std::cout << "Failed to load help image." << std::endl;
        // Handle the error
    }

    // Create the background sprite
    sf::Sprite helpSprite(helpTexture);

    helpSprite.setScale(((float)Window_Width) / helpTexture.getSize().x,
        ((float)Window_Height) / helpTexture.getSize().y
    );


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
                        const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getHelpButtonBounds();

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



