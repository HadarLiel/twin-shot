#include "Design.h"
#include "Consts.h"
#include <unordered_map>
#include "Resources.h"

Design::Design() : m_indexCharcater(Resources::CHARCTER_START)
{
    // Constructor for the Design class
}

int Design::run()
{
    // Run the design mode of the game

    sf::RenderWindow window(sf::VideoMode(Window_Width, Window_Height), "Design");

    m_buttons.draw_design_buttons_types(window);

    create_princess_buttons();

    const sf::Texture& m_charTexture = Resources::instance().getTexture(Resources::CHARCTER_START);
    m_charSprite.setTexture(m_charTexture);
    m_charSprite.setPosition((window.getSize().x - m_charTexture.getSize().x) / 2,
        (window.getSize().y - m_charTexture.getSize().y) / 2);

    const sf::Texture& backgroundTexture = Resources::instance().getTexture(Resources::DESIGNBG_START);

    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(((float)Window_Width) / backgroundTexture.getSize().x,
        ((float)Window_Height) / backgroundTexture.getSize().y);

    sf::Vector2i mousePosition;
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
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mousePosition = sf::Mouse::getPosition(window);
                    worldMousePos = window.mapPixelToCoords(mousePosition);

                    const std::vector<sf::FloatRect>& buttonTypesBounds = m_buttons.getDesignButtonBounds();

                    for (size_t i = 0; i < buttonTypesBounds.size(); ++i)
                    {
                        if (buttonTypesBounds[i].contains(worldMousePos))
                        {
                            if (i == 0) // if "back"
                            {
                                window.close();
                            }
                        }
                    }

                    for (size_t j = 0; j <= Resources::CHARCTER_END - Resources::CHARCTER_START; ++j)
                    {
                        if (princessButtons[j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            m_indexCharcater = j;
                            m_charSprite.setTexture(Resources::instance().getTexture(j + Resources::CHARCTER_START));
                        }
                    }
                }
            }
        }

        window.clear();
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
    // Create the princess buttons for selecting character textures

    princessButtons.clear();
    princessTextures.clear();

    int NumOfButtons = Resources::CHARCTER_END - Resources::CHARCTER_START + 1;

    for (int i = 0; i < NumOfButtons; i++)
    {
        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::CHARCTER_START));
        m_sprite.setScale((princess_buttonWidth) / m_sprite.getLocalBounds().width, (princess_buttonHeight) / m_sprite.getLocalBounds().height);

        const float buttonX = Window_Width / buttonWidth;
        const float buttonY = (i + 1) * (buttonHeight + 50);

        m_sprite.setPosition(buttonX, buttonY);
        princessButtons.push_back(m_sprite);
    }
}
