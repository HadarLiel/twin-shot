#include "Buttons.h"


Buttons::Buttons()
{
}


void Buttons::draw_buttons_types(sf::RenderWindow& window)
{
    
    for (const std::string& button : buttons_types)
    {
        sf::Texture m_texture;
        std::string filename = "resources/" + button + "_button.png";
        if (!m_texture.loadFromFile(filename))
        {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            // Handle the error accordingly
        }
        buttons_Textures.push_back(m_texture);
    }


    float totalButtonHeight = buttonHeight * buttons_Textures.size() + 50 * (buttons_Textures.size() - 1);
    float startY = (Window_Height - totalButtonHeight +30) / 2.0f; // Center vertically


    for (size_t i = 0; i < buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;


        m_sprite.setTexture(buttons_Textures[i]);
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
    // Load the textures for buttons

    for (const std::string& button : design_buttons_types)
    {
        sf::Texture m_texture;
        std::string filename = "resources/" + button + "_button.png";
        if (!m_texture.loadFromFile(filename))
        {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            // Handle the error accordingly
        }
        design_buttons_Textures.push_back(m_texture);
    }

    // Create sprites for buttons

    for (size_t i = 0; i < design_buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;


        m_sprite.setTexture(design_buttons_Textures[i]);
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(50 + i * (Window_Width / (design_buttons_types.size() + design_buttons_Textures.size())), 50);
        design_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        designButtonBounds.push_back(bounds);
    }



}


void Buttons::draw_help_buttons_types(sf::RenderWindow& window)
{
    // Load the textures for buttons

    for (const std::string& button : help_buttons_types)
    {
        sf::Texture m_texture;
        std::string filename = "resources/" + button + "_button.png";
        if (!m_texture.loadFromFile(filename))
        {
            std::cerr << "Failed to load texture: " << filename << std::endl;
            // Handle the error accordingly
        }
        help_buttons_Textures.push_back(m_texture);
    }

    // Create sprites for buttons

    for (size_t i = 0; i < help_buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;


        m_sprite.setTexture(help_buttons_Textures[i]);
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(50 + i * (Window_Width / (help_buttons_types.size() + help_buttons_Textures.size())), 300);
        help_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        helpButtonBounds.push_back(bounds);
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
    return help_buttons_Buttons;
}


const std::vector<sf::FloatRect>& Buttons::getButtonBounds() const
{
    return buttonBounds;
}

const std::vector<sf::FloatRect>& Buttons::getDesignButtonBounds() const
{
    return designButtonBounds;
}


const std::vector<sf::FloatRect>& Buttons::getHelpButtonBounds() const
{
    return helpButtonBounds;
}

const std::vector<sf::Sprite>& Buttons::getTypes() const
{
    return design_buttons_Buttons;
}