#include "SelectLevel.h"
#include "SelectLevel.h"

SelectLevel::SelectLevel()
{
}

void SelectLevel::run()
{
    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Select Level");

    

    //TODO:CHANGE NAME TO THIS FUNCTION TO DRAW_BACK_BUTTON
    m_buttons.draw_help_buttons_types(window);

    sf::Texture texture;
    texture = Resources::instance().getTexture(Resources::MENUBG_MENU_BACKGROUND);
    // Create the background sprite
    sf::Sprite selectSprite(texture);

    selectSprite.setScale(((float)Window_Width) / texture.getSize().x,
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

        window.draw(selectSprite);

        drawLevelsNumbers(window);

        for (const auto& button : m_buttons.getHelpButtons())
        {
            window.draw(button);
        }


        window.display();
    }
}

void SelectLevel::drawLevelsNumbers(sf::RenderWindow& window)
{

    sf::Font font;
    font = Resources::instance().getFont();

    float totalButtonHeight = buttonHeight * NUM_OF_LEVELS + 50 * (NUM_OF_LEVELS - 1);
    float startY = (Window_Height - totalButtonHeight + 30) / 2.0f; // Center vertically

    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        
        float disX = (float) Window_Width / (3 * 2); //3 is the number of cuttons i want to put in one line
        float disY = (float) Window_Height / (2 * 2); //2 is the number of cuttons i want to put in one col

        sf::Text levelIndex("Level: " + std::to_string(i), font);

        levelIndex.setFillColor(sf::Color::Blue);
        levelIndex.setPosition(disX + (i%3) * disX * 2 , disY + (i/3) * disY * 2);
        window.draw(levelIndex);
    } 

}
