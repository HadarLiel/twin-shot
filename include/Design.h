#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"

class Design
{
public:
	Design();
	int run();
	void create_princess_buttons();


private:
	
	int m_indexCharcater;
	sf::Sprite m_charSprite;

	sf::Texture m_saveChar;

	//sf::RectangleShape* selectedButton = nullptr;  // Variable to store the selected button


	std::vector<sf::Texture> princessTextures;
	std::vector<sf::Sprite> princessButtons;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	//sf::RenderWindow m_window;
};


