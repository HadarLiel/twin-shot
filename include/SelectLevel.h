#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"
#include "Resources.h"
#include "Consts.h"
#include "Level.h"
#include "MusicStruct.h"

class SelectLevel
{
public:
	SelectLevel();
	void run(int index, MusicStruct musicStruct);
	void drawLevelsNumbers(sf::RenderWindow& window) const;

private:

	sf::Texture m_selectLevelTexture;
	sf::Sprite m_selectLevelSprite;


	std::vector<sf::RectangleShape> m_rectTexture;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	sf::Time m_showTimeLose;
	sf::Time m_showTimeWin;


	int m_indexCharacter;

	MusicStruct m_musicStruct;

	//sf::RenderWindow m_window;
};


