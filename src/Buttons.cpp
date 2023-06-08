#include "Buttons.h"


Buttons::Buttons()
{
}


void Buttons::draw_buttons_types(sf::RenderWindow& window)
{
    // Load the textures for color buttons

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

    // Create sprites for color buttons

    for (size_t i = 0; i < buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;


        m_sprite.setTexture(buttons_Textures[i]);
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(20 + i * (Window_Width / (buttons_types.size() + buttons_Textures.size())), 20);
        buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        buttonBounds.push_back(bounds);
    }
}

const std::vector<sf::Sprite>& Buttons::getButtons() const
{
    return buttons_Buttons;
}



const std::vector<sf::FloatRect>& Buttons::getButtonBounds() const
{
    return buttonBounds;
}