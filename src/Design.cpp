#include "Design.h"
#include "Consts.h"
#include <unordered_map>

Design::Design()// :m_window(sf::VideoMode(Window_Width, Window_Height), "Design", sf::Style::Close | sf::Style::Titlebar)
{

}

sf::Texture Design::run()
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Design");

    m_buttons.draw_design_buttons_types(window);
    
    create_princess_buttons();

    //m_buttons.draw_buttons_types(m_window);


    m_charTexture.loadFromFile("resources/belle.png");
    m_charSprite.setTexture(m_charTexture);

    m_charSprite.setPosition((window.getSize().x - m_charTexture.getSize().x) / 2,
        (window.getSize().y - m_charTexture.getSize().y) / 2);

    

    // Load the game background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("resources/design_background.png"))
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

                                else
                                {
                                    m_saveChar = m_charTexture;
                                    std::cout << "need to save\n";
                                    return m_saveChar;

                                }
                                
                            }
                        }

                        //v

                        //press on princess
                        for (size_t j = 0; j < princessButtons.size(); ++j)
                        {
                            if (princessButtons[j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                std::cout << "hi\n";
                                // Change the car color by loading a different image
                                m_charTexture.loadFromFile("resources/" + princess[j] + ".png");
                                m_charSprite.setTexture(m_charTexture);

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

    

    return m_saveChar;

}




void Design::create_princess_buttons()
{
    // Load the textures for color buttons

    for (const std::string& princess_char : princess)
    {
        std::string filename = "resources/" + princess_char + ".png";
        if (!m_texture.loadFromFile(filename))
        {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            // Handle the error accordingly
        }
        princessTextures.push_back(m_texture);
    }

    // Create sprites for princess buttons

    for (size_t i = 0; i < princessTextures.size(); ++i)
    {
        m_sprite.setTexture(princessTextures[i]);
        m_sprite.setScale((buttonWidth+ princess_buttonWidth) / m_sprite.getLocalBounds().width, (buttonHeight+ princess_buttonHeight) / m_sprite.getLocalBounds().height);

        // Calculate the position of the button
        const float buttonX = 5.0f; // Left side of the screen
        const float buttonY = 20.0f + (i + 1) * (buttonHeight + 50); // Vertical spacing of 60 units between buttons

        m_sprite.setPosition(buttonX, buttonY);
        princessButtons.push_back(m_sprite);

    }
}
