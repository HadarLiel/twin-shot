#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Buttons.h"
#include "Resources.h"
#include "Consts.h"

class SelectLevel
{
public:
	SelectLevel();
	void run();
	void drawLevelsNumbers(sf::RenderWindow& window);

private:

	sf::Texture m_selectLevelTexture;
	sf::Sprite m_selectLevelSprite;

	
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Buttons m_buttons;

	//sf::RenderWindow m_window;
};


