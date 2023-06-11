#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"

class Help
{
public:
	Help();
	void run();


private:

	//????
	sf::Texture m_helpTexture;
	sf::Sprite m_helpSprite;

	sf::RectangleShape* selectedButton = nullptr;  // Variable to store the selected button

	
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	//sf::RenderWindow m_window;
};


