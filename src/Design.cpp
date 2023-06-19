#include "Design.h"
#include "Consts.h"
#include <unordered_map>
#include "Resources.h"

Design::Design(): m_indexCharcater(Resources::CHARCTER_START)
{

}

int Design::run()
{
   
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Design");

    m_buttons.draw_design_buttons_types(window);
    
    create_princess_buttons();
    const sf::Texture &m_charTexture = Resources::instance().getTexture(Resources::CHARCTER_START);

    m_charSprite.setTexture(m_charTexture);
   
    //todo:change position
    m_charSprite.setPosition((window.getSize().x - m_charTexture.getSize().x) / 2,
        (window.getSize().y - m_charTexture.getSize().y) / 2);
    
 
    // Load the game background image
    const sf::Texture & backgroundTexture = Resources::instance().getTexture(Resources::DESIGNBG_START);
    

    // Create the background sprite
    sf::Sprite backgroundSprite(backgroundTexture);

    backgroundSprite.setScale(((float)Window_Width) / backgroundTexture.getSize().x,
        ((float)Window_Height) / backgroundTexture.getSize().y
    );

    //todo:delete save button
    
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
                        const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getDesignButtonBounds();

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

                        //press on princess
                        for (size_t j = 0; j <= Resources::CHARCTER_END - Resources::CHARCTER_START; ++j)
                        {
                            if (princessButtons[j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                std::cout << "hi\n";
                                m_indexCharcater = j;
                                m_charSprite.setTexture(Resources::instance().getTexture(j + Resources::CHARCTER_START));


                            }
                        }


                        // Access the button bounds
                        const std::vector<sf::FloatRect>& buttonBounds = m_buttons.getButtonBounds();

                        

                    }


                }

            }
        }

        //---------------


        window.clear(); // Clear the window

        window.draw(backgroundSprite);
        window.draw(m_charSprite);

        for (const auto& button : princessButtons)
        {
            window.draw(button);
        }

        for (const auto& button : m_buttons.getDesignButtons())
        {
            window.draw(button);
        }

        
        window.display();
    }

    

    return m_indexCharcater;

}




void Design::create_princess_buttons()
{

    princessButtons.clear(); // Clear the previous buttons
    princessTextures.clear(); // Clear the previous textures

    // Load the textures for color buttons
    int NumOfButtons = Resources::CHARCTER_END - Resources::CHARCTER_START +1;

    for (int i = 0; i < NumOfButtons; i++)
    {
        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::CHARCTER_START));

        m_sprite.setScale((princess_buttonWidth) / m_sprite.getLocalBounds().width, (princess_buttonHeight) / m_sprite.getLocalBounds().height);

        // Calculate the position of the button

        const float buttonX = Window_Width / buttonWidth; // Left side of the screen
        const float buttonY = (i + 1) * (buttonHeight + 50);

        m_sprite.setPosition(buttonX, buttonY);
        princessButtons.push_back(m_sprite);

    }

}

