#include "SelectLevel.h"
#include "SelectLevel.h"

SelectLevel::SelectLevel(): m_showTimeLose(sf::Time::Zero), m_showTimeWin(sf::Time::Zero)
{
    // Create a rectangle shape
    sf::RectangleShape rectangle(sf::Vector2f(150, 50));

    sf::Color whiteColor(255, 255, 255, 200);
    rectangle.setFillColor(whiteColor);
    float disX = (float)Window_Width / (3 * 2); //3 is the number of cuttons i want to put in one line
    float disY = (float)Window_Height / (2 * 2); //2 is the number of cuttons i want to put in one col


    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);


    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        rectangle.setPosition(disX + (i % 3) * disX * 2, disY + (i / 3) * disY * 2);

        if (i > m_levelsOpen)
        {
            rectangle.setFillColor(sf::Color::Black);
        }
        m_rectTexture.push_back(rectangle);
    }
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
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time dTime = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                m_showTimeLose = sf::Time::Zero;
                m_showTimeWin = sf::Time::Zero;

            }
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

                        for (int i = 0; i < m_rectTexture.size(); i++)
                        {
                            if (m_rectTexture[i].getGlobalBounds().contains(worldMousePos))
                            {
                                if (i > m_levelsOpen)
                                {
                                    std::cout << "cant press\n";
                                    break;
                                }

                                Level level(i, m_indexCharacter, m_musicStruct);

                                while (level.run())
                                {
                                    i++;
                                    if (i >= NUM_OF_LEVELS)
                                    {
                                        m_showTimeWin = sf::seconds(5);
                                        m_showTimeLose = sf::Time::Zero;
                                        break;
                                    }
                                    level.setLevel(i);
                                    m_levelsOpen++;

                                    sf::Color whiteColor(255, 255, 255, 200);
                                    m_rectTexture[i].setFillColor(whiteColor);
                                   
                                }
                                clock.restart();

                                //if we lose
                                if (m_showTimeWin < sf::seconds(5))
                                {
                                    m_showTimeLose = sf::seconds(5);
                                    m_showTimeWin = sf::Time::Zero;
                                }
                                
                            }
                        }

                        
                    }
                        
                    

                }

            }
        }

        m_showTimeLose -= dTime;

        m_showTimeWin -= dTime;
        //---------------


        window.clear(); // Clear the window
        if (m_showTimeLose > sf::Time::Zero)
        {
            sf::Sprite loseSprite(Resources::instance().getTexture(Resources::LOSE_BACKGROUND));

            loseSprite.setScale(((float)Window_Width) / loseSprite.getTexture()->getSize().x,
                ((float)Window_Height) / loseSprite.getTexture()->getSize().y);

            window.draw(loseSprite);

        }

        else if (m_showTimeWin > sf::Time::Zero)
        {
            sf::Sprite winSprite(Resources::instance().getTexture(Resources::WIN_BACKGROUND));

            winSprite.setScale(((float)Window_Width) / winSprite.getTexture()->getSize().x,
                ((float)Window_Height) / winSprite.getTexture()->getSize().y);

            window.draw(winSprite);

        }

        else
        {
            window.draw(selectSprite);
            drawLevelsNumbers(window);

            for (const auto& button : m_buttons.getHelpButtons())
            {
                window.draw(button);
            }
        }
       

        
        

       

        window.display();
    }
}

void SelectLevel::drawLevelsNumbers(sf::RenderWindow& window) const
{

    sf::Font font;
    font = Resources::instance().getFont();

    
    float disX = (float)Window_Width / (3 * 2); //3 is the number of cuttons i want to put in one line
    float disY = (float)Window_Height / (2 * 2); //2 is the number of cuttons i want to put in one col

    for (int i = 0; i < NUM_OF_LEVELS; i++)
    {
        
        sf::Text levelIndex("Level: " + std::to_string(i), font);

        // Set the origin of the text to its center
        sf::FloatRect textBounds = levelIndex.getLocalBounds();
        levelIndex.setOrigin(textBounds.width / 2, textBounds.height / 2);
        levelIndex.setFillColor(sf::Color::Blue);
        levelIndex.setPosition(disX + (i%3) * disX * 2 , disY + (i/3) * disY * 2);
        
        window.draw(m_rectTexture[i]);
        window.draw(levelIndex);
       
    } 

}
