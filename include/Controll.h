#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Consts.h"
#include "Buttons.h"
#include "Level.h"
#include "Design.h"
#include "Help.h"
#include "Resources.h"

class Controll
{
public:
	Controll();
	void run();
	int getIndexCharcter();

private:
	sf::RenderWindow m_window;

	sf::Texture m_buttonTexture[num_Menu_Buttons];
	sf::Sprite m_buttonSprite[num_Menu_Buttons];

	sf::RectangleShape* selectedButton = nullptr;  // Variable to store the selected button

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	Level m_level;

	Design m_design;

	Help m_help;

	sf::Sound m_menuMusic[Resources::sm_Total];

	int m_indexCharacter;
};

