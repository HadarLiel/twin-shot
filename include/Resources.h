#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


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
		MONSTER_END = MONSTER_EVIL_QWEEN,

		ARROW_START,
		ARROW_ARROW = ARROW_START,
		ARROW_END = ARROW_ARROW,

		//Brick
		BRICK_START,
		BRICK_BLOCK_BRICK = BRICK_START,
		BRICK_FALL_BRICK,
		BRICK_REGULAR_BRICK,
		BRICK_END = BRICK_REGULAR_BRICK,

		//MenuBackground
		MENUBG_START,
		MENUBG_MENU_BACKGROUND = MENUBG_START,
		MENUBG_END = MENUBG_MENU_BACKGROUND,

		//DesignBackground
		DESIGNBG_START,
		DESIGNBG_DESIGN_BACKGROUND = DESIGNBG_START,
		DESIGNBG_END = DESIGNBG_DESIGN_BACKGROUND,

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
		BUTTONS_DESIGN_SAVE,
		BUTTONS_DESIGN_END = BUTTONS_DESIGN_SAVE,
		
		//ButtonsGame
		BUTTONS_GAME_START,
		BUTTONS_GAME_BACK = BUTTONS_GAME_START,
		BUTTONS_GAME_END = BUTTONS_GAME_BACK,
		
		Total //todo:ask hod why

	};
	

	enum MusicGame
	{
		sg_BelleMusic,
		sg_CinderMusic,
		sg_JasminMusic,
		sg_PeterPenMusic,
		sg_SnowWhiteMusic,
		sg_Total
	};

	enum musicMenu
	{
		sm_MenuMusic,
		sm_Total
	};



	~Resources() = default;
	static Resources& instance();
	const sf::Font& getFont() const;

	const sf::Texture& getTexture(int index_type) const;

	/*const sf::Texture& getButtonDesignTexture(int index_type) const;

	const sf::Texture& getButtonGameTexture(int index_type) const;

	const sf::Texture& getButtonMenuTexture(int index_type) const;

	const sf::Texture& getCharacterTexture(int index_type) const;

	const sf::Texture& getMonsterTexture(int index_type) const;

	const sf::Texture& getBrickTexture(int index_type) const;

	const sf::Texture& getMenuTexture(int index_type) const;*/

	const sf::SoundBuffer& getGameMusic(int index) const;
	const sf::SoundBuffer& getMenuMusic(int index) const;

private:
	Resources();
	//todo: ask hod if we need this
	Resources(const Resources&);//copy 
	Resources& operator= (const Resources&) = default;//copy 

	void loadtexture();
	void loadGameMusic();
	void loadMenuMusic();



	std::vector <sf::Texture> m_objects;

	/*std::vector <sf::Texture> m_character;
	std::vector <sf::Texture> m_monster;
	std::vector <sf::Texture> m_brick;
	std::vector <sf::Texture> m_menu;
	std::vector <sf::Texture> m_buttonsDesign;
	std::vector <sf::Texture> m_buttonsGame;
	std::vector <sf::Texture> m_buttonsMenu;*/
	std::vector <sf::SoundBuffer > m_GameSoundsBuffer;
	std::vector <sf::SoundBuffer > m_MenuSoundsBuffer;
	/*std::vector <sf::Sound > m_sounds;*/

	sf::Font m_font;
	//sf::Music music;

};


