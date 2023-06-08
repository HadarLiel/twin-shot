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

	const std::vector<sf::FloatRect>& getButtonBounds() const;

	void draw_buttons_types(sf::RenderWindow& window);

private:
	
	std::vector<sf::Texture> buttons_Textures;
	std::vector<sf::Sprite> buttons_Buttons;
	std::vector<sf::FloatRect> buttonBounds;
};

