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
#include "Settings.h"

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

	Design m_design;

	Settings m_settings;

	Help m_help;

	sf::Sound m_music;

	int m_indexCharacter;

	std::vector <Level*> m_levelsList; //

	bool m_TurnOn;

	MusicStruct m_musicStruct;

	int m_level;
};

