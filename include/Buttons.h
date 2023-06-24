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
	const std::vector<sf::FloatRect>& getGameButtonBounds() const;

	const std::vector<sf::Sprite>& getSettingsButtons() const;
	const std::vector<sf::FloatRect>& getSettingsButtonBounds() const;

	const std::vector<sf::Sprite>& getTypes() const;

	void drawMenuButtons(sf::RenderWindow& window);
	void draw_design_buttons_types(sf::RenderWindow& window);
	void draw_back_buttons_types(sf::RenderWindow& window);
	void draw_settings_buttons_types(sf::RenderWindow& window);

private:
	
	std::vector<sf::Sprite> buttons_Buttons;
	std::vector<sf::FloatRect> buttonBounds;

	std::vector<sf::Sprite> design_buttons_Buttons;
	std::vector<sf::FloatRect> designButtonBounds;

	std::vector<sf::Sprite> game_buttons_Buttons;
	std::vector<sf::FloatRect> gameButtonBounds;

	std::vector<sf::Sprite> settings_buttons_Buttons;
	std::vector<sf::FloatRect> settingsButtonBounds;
};

