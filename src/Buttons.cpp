#include "Buttons.h"
#include "Resources.h"

Buttons::Buttons()
{
}


void Buttons::drawMenuButtons(sf::RenderWindow& window)
{
    
    for (int i = 0; i < Resources::bm_Total-1; i++)
    {
        sf::Texture texture;
        texture = Resources::instance().getButtonMenuTexture((i + 1) + Resources::ButtonsMenu::bm_Start);
        buttons_Textures.push_back(texture);

    }

    float totalButtonHeight = buttonHeight * buttons_Textures.size() + 50 * (buttons_Textures.size() - 1);
    float startY = (Window_Height - totalButtonHeight +30) / 2.0f; // Center vertically


    for (size_t i = 0; i < buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getButtonMenuTexture((i + 1) + Resources::ButtonsMenu::bm_Start));
        //m_sprite.setTexture(buttons_Textures[i]);
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
    design_buttons_Textures.clear();
    design_buttons_Buttons.clear();


    // Load the textures for buttons

    for (int i = 0; i < Resources::bd_Total-1; i++)
    {
        sf::Texture texture;
        texture = Resources::instance().getButtonDesignTexture((i + 1) + Resources::ButtonsDesign::bd_Start);
        design_buttons_Textures.push_back(texture);
    }

    // Create sprites for buttons

    for (size_t i = 0; i < design_buttons_Textures.size(); ++i)
    {

        sf::Sprite m_sprite;
        m_sprite.setTexture(Resources::instance().getButtonDesignTexture((i + 1) + Resources::ButtonsDesign::bd_Start));

        /*sf::Sprite m_sprite;


        m_sprite.setTexture(design_buttons_Textures[i]);*/
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        m_sprite.setPosition(50 + i * (Window_Width / (design_buttons_Textures.size() + design_buttons_Textures.size())), 50);
        design_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        designButtonBounds.push_back(bounds);
    }



}


void Buttons::draw_help_buttons_types(sf::RenderWindow& window)
{
    game_buttons_Textures.clear();
    game_buttons_Buttons.clear();

    // Load the textures for buttons

    //for (const std::string& button : help_buttons_types)
    //{
    //    sf::Texture m_texture;
    //    std::string filename = "resources/Buttons/" + button + "_button.png";
    //    if (!m_texture.loadFromFile(filename))
    //    {
    //        std::cerr << "Failed to load texture: " << filename << std::endl;
    //        // Handle the error accordingly
    //    }
    //    help_buttons_Textures.push_back(m_texture);
    //}

    for (int i = 0; i < Resources::bg_Total-1; i++)
    {
        sf::Texture texture;
        texture = Resources::instance().getButtonGameTexture((i + 1) + Resources::ButtonsGame::bg_Start);
        game_buttons_Textures.push_back(texture);
    }

    // Create sprites for buttons

    for (size_t i = 0; i < game_buttons_Textures.size(); ++i)
    {
        sf::Sprite m_sprite;

        m_sprite.setTexture(Resources::instance().getButtonGameTexture((i + 1) + Resources::ButtonsGame::bg_Start));

        //m_sprite.setTexture(game_buttons_Textures[i]);
        m_sprite.setScale(buttonWidth / m_sprite.getLocalBounds().width, buttonHeight / m_sprite.getLocalBounds().height);

        //m_sprite.setPosition(50 + i * (Window_Width / (help_buttons_types.size() + game_buttons_Textures.size())), 300);

        m_sprite.setPosition( i * (Window_Width / (help_buttons_types.size() + game_buttons_Textures.size())), 200);
        game_buttons_Buttons.push_back(m_sprite);

        // Store the global bounds of the sprite
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        gameButtonBounds.push_back(bounds);
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

const std::vector<sf::Sprite>& Buttons::getTypes() const
{
    return design_buttons_Buttons;
}