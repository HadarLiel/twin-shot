#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Consts.h"


class Resources 
{
public:

	enum Objects
	{
		//Charcter
		CHARCTER_START,
		CHARCTER_BELLE = CHARCTER_START,
		CHARCTER_CINDERELLA,
		CHARCTER_JASMIN,
		CHARCTER_PETER_PAN,
		CHARCTER_SNOW_WHITE,
		CHARCTER_END = CHARCTER_SNOW_WHITE,

		//Monster
		MONSTER_START,
		MONSTER_BEAST = MONSTER_START,
		MONSTER_EVIL_CINDERELLA,
		MONSTER_JAFAR,
		MONSTER_CAPTAIN_HOOK,
		MONSTER_EVIL_QWEEN,
		MONSTER_PROTECTED,
		MONSTER_END = MONSTER_PROTECTED,

		ARROW_START,
		ARROW_ARROW = ARROW_START,
		ARROW_END = ARROW_ARROW,

		//Brick
		BRICK_START,
		BRICK_BLOCK_BRICK = BRICK_START,
		BRICK_FALL_BRICK,
		BRICK_BROKEN_BRICK,
		BRICK_REGULAR_BRICK,
		BRICK_END = BRICK_REGULAR_BRICK,

		//todo:change start to end because we dont need
		//MenuBackground
		MENUBG_START,
		MENUBG_MENU_BACKGROUND = MENUBG_START,
		MENUBG_END = MENUBG_MENU_BACKGROUND,

		//DesignBackground
		DESIGNBG_START,
		DESIGNBG_DESIGN_BACKGROUND = DESIGNBG_START,
		DESIGNBG_END = DESIGNBG_DESIGN_BACKGROUND,

		//HelpBackground
		HELPBG_BACKGROUND,

		//win
		WIN_BACKGROUND,

		//lose
		LOSE_BACKGROUND,

		//ButtonsMenu
		BUTTONS_MENU_START,
		BUTTONS_MENU_NEW_GAME = BUTTONS_MENU_START,
		BUTTONS_MENU_DESIGN,
		BUTTONS_MENU_SETTINGS,
		BUTTONS_MENU_HELP,
		BUTTONS_MENU_EXIT,
		BUTTONS_MENU_END = BUTTONS_MENU_EXIT,

		//ButtonsDesign
		BUTTONS_DESIGN_START,
		BUTTONS_DESIGN_BACK = BUTTONS_DESIGN_START,
		BUTTONS_DESIGN_END = BUTTONS_DESIGN_BACK,
		
		//ButtonsGame
		BUTTONS_GAME_START,
		BUTTONS_GAME_BACK = BUTTONS_GAME_START,
		BUTTONS_GAME_END = BUTTONS_GAME_BACK,

		//ButtonsMusic
		BUTTONS_MUSIC_START,
		BUTTONS_MUSIC_MENU_ON = BUTTONS_MUSIC_START,
		BUTTONS_MUSIC_MENU_OFF,
		BUTTONS_MUSIC_GAME_ON,
		BUTTONS_MUSIC_GAME_OFF,
		BUTTONS_MUSIC_END = BUTTONS_MUSIC_GAME_OFF,
		
		Total //todo:ask hod why

	};
	

	enum MusicGame
	{
		SOUND_GAME_START,
		SOUND_GAME_BELLE = SOUND_GAME_START,
		SOUND_GAME_CINDERELLA,
		SOUND_GAME_JASMIN,
		SOUND_GAME_PETER_PAN,
		SOUND_GAME_SNOW_WHITE,
		SOUND_GAME_END = SOUND_GAME_SNOW_WHITE,

		SOUND_MENU_START,
		SOUND_MENU_MENU = SOUND_MENU_START,
		SOUND_MENU_END = SOUND_MENU_MENU,

		SOUND_TOTAL
		
	};



	~Resources() = default;

	static Resources& instance();
	const sf::Font& getFont() const;
	const sf::Texture& getTexture(unsigned int index) const;
	const sf::Image& getLevel(unsigned int index) const;

	/*const sf::Texture& getButtonDesignTexture(int index_type) const;

	const sf::Texture& getButtonGameTexture(int index_type) const;

	const sf::Texture& getButtonMenuTexture(int index_type) const;

	const sf::Texture& getCharacterTexture(int index_type) const;

	const sf::Texture& getMonsterTexture(int index_type) const;

	const sf::Texture& getBrickTexture(int index_type) const;

	const sf::Texture& getMenuTexture(int index_type) const;*/

	const sf::SoundBuffer& getMusic(int index) const;


private:
	Resources();
	
	Resources(const Resources&) = delete;//we need this becaue of the instance, that no one can create one including me
	Resources& operator= (const Resources&) = delete;//copy ^^^^^^ 

	void loadtexture();
	void loadMusic();
	void loadLevels();



	std::vector <sf::Texture> m_objects;
	std::vector <sf::Image> m_levels;

	/*std::vector <sf::Texture> m_character;
	std::vector <sf::Texture> m_monster;
	std::vector <sf::Texture> m_brick;
	std::vector <sf::Texture> m_menu;
	std::vector <sf::Texture> m_buttonsDesign;
	std::vector <sf::Texture> m_buttonsGame;
	std::vector <sf::Texture> m_buttonsMenu;*/
	std::vector <sf::SoundBuffer > m_SoundsBuffer;
	/*std::vector <sf::Sound > m_sounds;*/

	sf::Font m_font;
	//sf::Music music;

};


