#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"

class Design
{
public:
	Design();
	sf::Texture run();
	void create_princess_buttons();


private:
	
	//????
	sf::Texture m_charTexture;
	sf::Sprite m_charSprite;

	sf::Texture m_saveChar;

	sf::RectangleShape* selectedButton = nullptr;  // Variable to store the selected button

	// Define the names of the colors and car pictures
	std::vector<std::string> princess = {
		"belle", "snow", "jasmin", "piterPen", "cinderella"
		//beast, evilQween, jafar, captainHook, evilCinder
	};

	std::vector<sf::Texture> princessTextures;
	std::vector<sf::Sprite> princessButtons;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	//sf::RenderWindow m_window;
};


