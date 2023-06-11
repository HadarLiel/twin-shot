#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Consts.h"

class Buttons
{
public:
	Buttons();

	const std::vector<sf::Sprite>& getButtons() const;
	const std::vector<sf::Sprite>& getDesignButtons() const;

	const std::vector<sf::FloatRect>& getButtonBounds() const;
	const std::vector<sf::FloatRect>& getDesignButtonBounds() const;

	const std::vector<sf::Sprite>& getHelpButtons() const;
	const std::vector<sf::FloatRect>& getHelpButtonBounds() const;

	const std::vector<sf::Sprite>& getTypes() const;

	void draw_buttons_types(sf::RenderWindow& window);
	void draw_design_buttons_types(sf::RenderWindow& window);
	void draw_help_buttons_types(sf::RenderWindow& window);

private:
	
	std::vector<sf::Texture> buttons_Textures;
	std::vector<sf::Sprite> buttons_Buttons;
	std::vector<sf::FloatRect> buttonBounds;

	std::vector<sf::Texture> design_buttons_Textures;
	std::vector<sf::Sprite> design_buttons_Buttons;
	std::vector<sf::FloatRect> designButtonBounds;

	std::vector<sf::Texture> help_buttons_Textures;
	std::vector<sf::Sprite> help_buttons_Buttons;
	std::vector<sf::FloatRect> helpButtonBounds;
};

