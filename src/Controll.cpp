#include "Controll.h"
#include "Consts.h"
#include <unordered_map>
#include "Resources.h"

Controll::Controll() :m_window(sf::VideoMode(Window_Width, Window_Height), "twin-shot", sf::Style::Close | sf::Style::Titlebar), 
                      m_level("resources/Levels/Level1.png")//m_level("resources/hadar_map.png"),
                      
{
    //todo:put it here?
    ///in order to load the music
    for (int index = 0; index < Resources::sm_Total; index++)
    {
        m_menuMusic[index].setBuffer(Resources::instance().getMenuMusic(index));
    }
}


void Controll::run()
{

    m_buttons.drawMenuButtons(m_window);


   //todo: change zero for other name that describe first place
    sf::Texture texture;
    texture = Resources::instance().getMenuTexture(0);
    // Create the background sprite
    sf::Sprite backgroundSprite(texture);

    backgroundSprite.setScale(((float)Window_Width) / texture.getSize().x,
                             ((float)Window_Height) / texture.getSize().y);
   

    
    sf::Vector2i mousePosition;
    // Convert mouse position to world coordinates
    sf::Vector2f worldMousePos;

    m_menuMusic[Resources::sm_MenuMusic].play();
    m_menuMusic[Resources::sm_MenuMusic].setLoop(true);

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
                                    m_menuMusic[Resources::sm_MenuMusic].stop();
                                    std::cout << "new game\n";
                                    //todo: start new game every time we press new game

                                    m_level.run();

                                }

                                else if (i ==1)
                                {
                                    m_menuMusic[Resources::sm_MenuMusic].stop();
                                    std::cout << "design button" << i << "\n";
                                    
                                    sf::Texture saveChar = m_design.run();
                                    //chracterSprite.setTexture(saveChar);
                                    
                                    //std::cout << "the princess now is: \n" ;
                                }

                                else if (i == 2)
                                {
                                    m_menuMusic[Resources::sm_MenuMusic].stop();
                                    std::cout << "setting button" << i << "\n";
                                }

                                else if (i == 3)
                                {
                                    //todo:change help
                                    m_menuMusic[Resources::sm_MenuMusic].stop();
                                    m_help.run();
                                    std::cout << "help button" << i << "\n";
                                }

                                else
                                {
                                    m_menuMusic[Resources::sm_MenuMusic].stop();
                                    std::cout << "exit button" << i << "\n";
                                    m_window.close();
                                }
                           }


                        }

                        m_menuMusic[Resources::sm_MenuMusic].play();
                        m_menuMusic[Resources::sm_MenuMusic].setLoop(true);
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
