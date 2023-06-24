#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"
#include "Resources.h"
#include "MusicStruct.h"
#include "Resources.h"

class Settings
{
public:
	Settings();
	void run(MusicStruct &musicStruct);

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

	bool m_menuOn;
	bool m_gameOn;

	sf::Sprite spriteMenu;
	sf::Sprite spriteGame;
};


