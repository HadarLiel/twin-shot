#include "Controll.h"
#include "Consts.h"
#include <unordered_map>

Controll::Controll() :m_window(sf::VideoMode(Window_Width, Window_Height), "twin-shot", sf::Style::Close | sf::Style::Titlebar), 
                        m_level("resources/hadar_map.png")
{

}


void Controll::run()
{

    m_buttons.draw_buttons_types(m_window);

    // Load the game background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("resources/background_design.png"))
    {
        std::cout << "Failed to load background image." << std::endl;
        // Handle the error
    }

    // Create the background sprite
    sf::Sprite backgroundSprite(backgroundTexture);

    backgroundSprite.setScale(((float)Window_Width) / backgroundTexture.getSize().x,
        ((float)Window_Height) / backgroundTexture.getSize().y
    );

    
    sf::Vector2i mousePosition;
    // Convert mouse position to world coordinates
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
                        mousePosition = sf::Mouse::getPosition(m_window);
                        worldMousePos = m_window.mapPixelToCoords(mousePosition);

                        

                        // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonBounds = m_buttons.getButtonBounds();

                        //// Iterate over each button bounds to check if the mouse position is within any of them
                        for (size_t i = 0; i < buttonBounds.size(); ++i)
                        {

                            if (buttonBounds[i].contains(worldMousePos))
                            {
                                if (i == 0) //if "New Game"
                                {
                                    std::cout << "new game\n";
                                    m_level.run();
                                }

                                else if (i ==1)
                                {
                                    std::cout << "press button" << i << "\n";

                                }

                                else
                                {
                                    std::cout << "exit button" << i << "\n";
                                    m_window.close();
                                }

                           }



                        }

                    }


               }

            }
        }

        //---------------


        m_window.clear(); // Clear the window

        // Draw the background image
        m_window.draw(backgroundSprite);



        for (const auto& button : m_buttons.getButtons())
        {
            m_window.draw(button);
        }


        m_window.display();
    }

}



//void Controll::color_car(int i, sf::Event::&eve)
//{
//    
//    for (size_t i = 0; i < colorButtons.size(); ++i)
//    {
//        if (colorButtons[i].getGlobalBounds().contains(eve.mouseButton.x, eve.mouseButton.y))
//        {
//            // Change the car color by loading a different image
//            m_carTexture.loadFromFile(m_buttons.buttons_types[i] + colors[i] + ".png");
//            m_carSprite.setTexture(m_carTexture);
//            break;
//        }
//    }
//}
