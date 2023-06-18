#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


class Resources 
{
public:
	enum Character
	{
		c_Start,
		c_Belle,
		c_Cinder,
		c_Jasmin,
		c_PeterPen,
		c_SnowWhite,
		c_Total
	};
	

	enum Monster
	{
		m_Start,
		m_Beast,
		m_EvilCinder,
		m_Jafar,
		m_CaptainHook,
		m_EvilQween,
		m_Total
	};

	enum Brick
	{
		b_blockBrick ,
		b_fallBrick,
		b_regularBrick,
		b_Total
	};

	enum MenuBackground
	{
		mb_MenuBackground,
		mb_Total
	};

	enum ButtonsMenu
	{
		bm_Start,
		bm_New_Game_button,
		bm_Design_button,
		bm_Settings_button,
		bm_Help_button,
		bm_Exit_button,
		bm_Total
	};

	enum ButtonsDesign
	{
		bd_Start,
		bd_back_button,
		bd_save_button,
		bd_Total
	};

	enum ButtonsGame
	{
		bg_Start,
		bg_back_button,
		bg_Total
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
	//const sf::Texture& getTexture(int index_type) const;
	const sf::Font& getFont() const;
	/*sf::SoundBuffer& getMusic(int index);
	sf::SoundBuffer& getMenuMusic(int index);*/

	const sf::Texture& getButtonDesignTexture(int index_type) const;

	const sf::Texture& getButtonGameTexture(int index_type) const;

	const sf::Texture& getButtonMenuTexture(int index_type) const;

	const sf::Texture& getCharacterTexture(int index_type) const;

	const sf::Texture& getMonsterTexture(int index_type) const;

	const sf::Texture& getBrickTexture(int index_type) const;

	const sf::Texture& getMenuTexture(int index_type) const;

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



	/*int getSoundSize();*/

	

	std::vector <sf::Texture> m_character;
	std::vector <sf::Texture> m_monster;
	std::vector <sf::Texture> m_brick;
	std::vector <sf::Texture> m_menu;
	std::vector <sf::Texture> m_buttonsDesign;
	std::vector <sf::Texture> m_buttonsGame;
	std::vector <sf::Texture> m_buttonsMenu;
	std::vector <sf::SoundBuffer > m_GameSoundsBuffer;
	std::vector <sf::SoundBuffer > m_MenuSoundsBuffer;
	/*std::vector <sf::Sound > m_sounds;*/

	sf::Font m_font;
	//sf::Music music;

};


