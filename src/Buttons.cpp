#include "Buttons.h"
#include "Resources.h"

Buttons::Buttons()
{
}


void Buttons::drawMenuButtons(sf::RenderWindow& window)
{
    int numOfButtons = Resources::BUTTONS_MENU_END - Resources::BUTTONS_MENU_START + 1;
    float totalButtonHeight = buttonHeight * numOfButtons + 50 * (numOfButtons - 1);
    float startY = (Window_Height - totalButtonHeight + 30) / 2.0f; // Center vertically
    
    for (int i = 0; i < numOfButtons; i++)
    {
        sf::Sprite m_sprite;
        
        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_MENU_START));
        
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        float posX = (Window_Width - m_sprite.getGlobalBounds().width) / 2.0f; // Center horizontally
        float posY = startY + i * (buttonHeight + 50);

        m_sprite.setPosition(posX, posY);//(posX, posY);
        buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        buttonBounds.push_back(bounds);

    }

    
}

void Buttons::draw_design_buttons_types(sf::RenderWindow& window)
{
    design_buttons_Buttons.clear();

    int numOfButtons = Resources::BUTTONS_DESIGN_END - Resources::BUTTONS_DESIGN_START + 1;
    // Load the textures for buttons
    for (int i = 0; i < numOfButtons; i++)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_DESIGN_START));

        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(50 + i * (Window_Width / (numOfButtons *2)), 50);
        design_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        designButtonBounds.push_back(bounds);
    }

}


void Buttons::draw_help_buttons_types(sf::RenderWindow& window)
{
    game_buttons_Buttons.clear();

    int NumOfButtons = Resources::BUTTONS_GAME_END - Resources::BUTTONS_GAME_START + 1;

    for (int i = 0; i < NumOfButtons; i++)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_GAME_START));

        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(i * (Window_Width / (NumOfButtons * 2)), Window_Height- buttonHeight);
        game_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        gameButtonBounds.push_back(bounds);

    }

}

void Buttons::draw_settings_buttons_types(sf::RenderWindow& window)
{
    settings_buttons_Buttons.clear();

    int NumOfButtons = Resources::BUTTONS_MUSIC_END - Resources::BUTTONS_MUSIC_START + 1;
    float totalButtonHeight = buttonHeight * NumOfButtons + 50 * (NumOfButtons - 1);
    float startY = (Window_Height - totalButtonHeight + 30) / 2.0f; // Center vertically


    for (int i = 0; i < NumOfButtons; i++)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_MUSIC_START));

        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);
       
        float posX = (Window_Width - m_sprite.getGlobalBounds().width) / 2.0f; // Center horizontally
        float posY = startY + i * (buttonHeight + 50);

        m_sprite.setPosition(posX, posY);//(posX, posY);

        settings_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        settingsButtonBounds.push_back(bounds);

    }
}



//------------------------
const std::vector<sf::Sprite>& Buttons::getButtons() const
{
    return buttons_Buttons;
}

const std::vector<sf::Sprite>& Buttons::getDesignButtons() const
{
    return design_buttons_Buttons;
}

const std::vector<sf::Sprite>& Buttons::getHelpButtons() const
{
    return game_buttons_Buttons;
}


const std::vector<sf::FloatRect>& Buttons::getButtonBounds() const
{
    return buttonBounds;
}

const std::vector<sf::FloatRect>& Buttons::getDesignButtonBounds() const
{
    return designButtonBounds;
}


const std::vector<sf::FloatRect>& Buttons::getGameButtonBounds() const
{
    return gameButtonBounds;
}

const std::vector<sf::Sprite>& Buttons::getSettingsButtons() const
{
    return settings_buttons_Buttons;
}

const std::vector<sf::FloatRect>& Buttons::getSettingsButtonBounds() const
{
   
    return settingsButtonBounds;
}

const std::vector<sf::Sprite>& Buttons::getTypes() const
{
    return design_buttons_Buttons;
}