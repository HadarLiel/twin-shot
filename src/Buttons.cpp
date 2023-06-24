#include "Buttons.h"
#include "Resources.h"

Buttons::Buttons()
{
    // Default constructor for the Buttons class
}

void Buttons::drawMenuButtons(sf::RenderWindow& window)
{
    // Draws the menu buttons on the window

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

        m_sprite.setPosition(posX, posY);
        buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        buttonBounds.push_back(bounds);
    }
}

void Buttons::draw_design_buttons_types(sf::RenderWindow& window)
{
    // Draws the design buttons on the window

    design_buttons_Buttons.clear();

    int numOfButtons = Resources::BUTTONS_DESIGN_END - Resources::BUTTONS_DESIGN_START + 1;

    for (int i = 0; i < numOfButtons; i++)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_DESIGN_START));

        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(50 + i * (Window_Width / (numOfButtons * 2)), 50);
        design_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        designButtonBounds.push_back(bounds);
    }
}

void Buttons::draw_back_buttons_types(sf::RenderWindow& window)
{
    // Draws the game buttons on the window

    game_buttons_Buttons.clear();

    int NumOfButtons = Resources::BUTTONS_GAME_END - Resources::BUTTONS_GAME_START + 1;

    for (int i = 0; i < NumOfButtons; i++)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getTexture(i + Resources::BUTTONS_GAME_START));

        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(i * (Window_Width / (NumOfButtons * 2)), Window_Height - buttonHeight);
        game_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        gameButtonBounds.push_back(bounds);
    }
}

void Buttons::draw_settings_buttons_types(sf::RenderWindow& window)
{
    // Draws the settings buttons on the window

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

        m_sprite.setPosition(posX, posY);
        settings_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        settingsButtonBounds.push_back(bounds);
    }
}

const std::vector<sf::Sprite>& Buttons::getButtons() const
{
    // Returns the menu buttons
    return buttons_Buttons;
}

const std::vector<sf::Sprite>& Buttons::getDesignButtons() const
{
    // Returns the design buttons
    return design_buttons_Buttons;
}

const std::vector<sf::Sprite>& Buttons::getHelpButtons() const
{
    // Returns the game buttons
    return game_buttons_Buttons;
}

const std::vector<sf::FloatRect>& Buttons::getButtonBounds() const
{
    // Returns the bounds of the menu buttons
    return buttonBounds;
}

const std::vector<sf::FloatRect>& Buttons::getDesignButtonBounds() const
{
    // Returns the bounds of the design buttons
    return designButtonBounds;
}

const std::vector<sf::FloatRect>& Buttons::getGameButtonBounds() const
{
    // Returns the bounds of the game buttons
    return gameButtonBounds;
}

const std::vector<sf::Sprite>& Buttons::getSettingsButtons() const
{
    // Returns the settings buttons
    return settings_buttons_Buttons;
}

const std::vector<sf::FloatRect>& Buttons::getSettingsButtonBounds() const
{
    // Returns the bounds of the settings buttons
    return settingsButtonBounds;
}

const std::vector<sf::Sprite>& Buttons::getTypes() const
{
    // Returns the design buttons (used by `draw_design_buttons_types`)
    return design_buttons_Buttons;
}
