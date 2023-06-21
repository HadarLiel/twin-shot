#include "SelectLevel.h"
#include "SelectLevel.h"

SelectLevel::SelectLevel()
{
}

void SelectLevel::run(int index, MusicStruct musicStruct)
{

    m_indexCharacter = index;
    m_musicStruct = musicStruct ;

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

    // Create a rectangle shape
    sf::RectangleShape rectangle(sf::Vector2f(150, 50));

    sf::Color whiteColor(255, 255, 255, 200);
    rectangle.setFillColor(whiteColor);

    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        
        float disX = (float) Window_Width / (3 * 2); //3 is the number of cuttons i want to put in one line
        float disY = (float) Window_Height / (2 * 2); //2 is the number of cuttons i want to put in one col

        sf::Text levelIndex("Level: " + std::to_string(i), font);

        // Set the origin of the text to its center
        sf::FloatRect textBounds = levelIndex.getLocalBounds();
        levelIndex.setOrigin(textBounds.width / 2, textBounds.height / 2);
        rectangle.setOrigin(rectangle.getSize().x/ 2 , rectangle.getSize().y / 2);

        levelIndex.setFillColor(sf::Color::Blue);
        levelIndex.setPosition(disX + (i%3) * disX * 2 , disY + (i/3) * disY * 2);

        rectangle.setPosition(disX + (i % 3) * disX * 2, disY + (i / 3) * disY * 2);
        window.draw(rectangle);
        window.draw(levelIndex);


        // Check if the rectangle is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f worldMousePos = window.mapPixelToCoords(mousePosition);

            if (rectangle.getGlobalBounds().contains(worldMousePos))
            {
                
                Level level(i, m_indexCharacter, m_musicStruct);

                while (level.run())
                {
                    level = Level (i+1, m_indexCharacter, m_musicStruct);
                    //todo:move
                    std::cout << "move to the next level\n";
                }

                //if(!level.run())
                //
                ////    sf::Texture texture;
                ////    texture = Resources::instance().getTexture(Resources::LOSE_BACKGROUND);
                ////    // Create the background sprite
                ////    sf::Sprite loseSprite(texture);

                ////    loseSprite.setScale(((float)Window_Width) / texture.getSize().x,
                ////        ((float)Window_Height) / texture.getSize().y);

                ////    window.draw(loseSprite);

                //    std::cout << "fail\n";
                //    break;
                //}
                // Perform the desired action for the pressed rectangle
            }
        }
    } 

}
