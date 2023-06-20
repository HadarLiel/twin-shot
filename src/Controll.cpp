#include "Controll.h"
#include "Consts.h"
#include <unordered_map>
#include "Resources.h"

Controll::Controll() :m_window(sf::VideoMode(Window_Width, Window_Height), "twin-shot", sf::Style::Close | sf::Style::Titlebar), 
                      m_indexCharacter(0)
{
    m_music.setBuffer(Resources::instance().getMusic(Resources::SOUND_MENU_MENU));
    m_music.setLoop(true);
    m_music.setVolume(100);
}


void Controll::run()
{
   
    if (m_musicStruct._turnOnMenu)
    {
        m_music.play();
    }
    m_buttons.drawMenuButtons(m_window);

    sf::Texture texture;
    texture = Resources::instance().getTexture(Resources::MENUBG_MENU_BACKGROUND);
    // Create the background sprite
    sf::Sprite backgroundSprite(texture);

    backgroundSprite.setScale(((float)Window_Width) / texture.getSize().x,
                             ((float)Window_Height) / texture.getSize().y);
   

    
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
                                //todo: do it like this?
                                if (i == 0) //if "New Game"
                                {
                                    
                                    std::cout << "new game\n";
                                    //todo:send number level
                                    m_music.stop();

                                    Level level("resources/Levels/level6.png", m_indexCharacter, m_musicStruct);
                                    //todo:change the 1 to the level we choose
                                    //Level level(1, m_indexCharacter, m_musicStruct);

                                    if (level.run())
                                    {
                                        //m_level++;
                                        std::cout << "move to the next level\n";
                                    }
                                    

                                    
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }

                                }

                                else if (i ==1)
                                {
                                    std::cout << "design button" << i << "\n";

                                    m_music.stop();
                                    m_indexCharacter = m_design.run();

                                  
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                    
                                    std::cout << m_indexCharacter <<"\n";
                                    //chracterSprite.setTexture(saveChar);
                                    
                                    //std::cout << "the princess now is: \n" ;
                                }

                                else if (i == 2)
                                {
                                    m_music.stop();
                                    std::cout << "setting button" << i << "\n";
                                    m_settings.run(m_musicStruct);

                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                    
                                }

                                else if (i == 3)
                                {
                                    //todo:change help
                                    m_music.stop();
                                    m_help.run();
                                   
                                    if (m_musicStruct._turnOnMenu)
                                    {
                                        m_music.play();
                                    }
                                    
                                    std::cout << "help button" << i << "\n";
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

int Controll::getIndexCharcter()
{
    return m_indexCharacter;
}