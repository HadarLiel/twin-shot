#include "Resources.h"

Resources::Resources()
{
	loadtexture();
	loadGameMusic();
	loadMenuMusic();
	m_font.loadFromFile("resources/arial.ttf");
}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

const sf::Texture& Resources::getButtonDesignTexture(int index_type) const
{
	return m_buttonsDesign[index_type];
}

const sf::Texture& Resources::getButtonGameTexture(int index_type) const
{
	return m_buttonsGame[index_type];
}

const sf::Texture& Resources::getButtonMenuTexture(int index_type) const
{
	return m_buttonsMenu[index_type];
}

const sf::Texture& Resources::getCharacterTexture(int index_type) const
{
	return m_character[index_type];
}

const sf::Texture& Resources::getMonsterTexture(int index_type) const
{
	return m_monster[index_type];
}

const sf::Texture& Resources::getMenuTexture(int index_type) const
{
	return m_menu[index_type];
}

const sf::Font& Resources::getFont() const
{
	return m_font;
}


const sf::SoundBuffer& Resources::getGameMusic(int index) const
{
	return m_GameSoundsBuffer[index];
}

const sf::SoundBuffer& Resources::getMenuMusic(int index) const
{
	return m_MenuSoundsBuffer[index];
}


void Resources::loadtexture()
{
	m_character.resize(Character::c_Total);
	m_character[Character::c_Belle].loadFromFile("resources/Belle/belle.png");
	m_character[Character::c_Cinder].loadFromFile("resources/Cinder/cinderella.png");
	m_character[Character::c_Jasmin].loadFromFile("resources/Jasmin/jasmin.png");
	m_character[Character::c_PeterPen].loadFromFile("resources/PeterPen/peterPen.png");
	m_character[Character::c_SnowWhite].loadFromFile("resources/SnowWhite/snow.png");
	
	m_monster.resize(Monster::m_Total);
	m_monster[Monster::m_Beast].loadFromFile("resources/Belle/Beast.png");
	m_monster[Monster::m_EvilCinder].loadFromFile("resources/Cinder/EvilCinder.png");
	m_monster[Monster::m_Jafar].loadFromFile("resources/Jasmin/Jafar.png");
	m_monster[Monster::m_CaptainHook].loadFromFile("resources/PeterPen/CaptainHook.png");
	m_monster[Monster::m_EvilQween].loadFromFile("resources/SnowWhite/EvilQween.png");

	m_buttonsDesign.resize(ButtonsDesign::bd_Total);
	m_buttonsDesign[ButtonsDesign::bd_back_button].loadFromFile("resources/ButtonsDesign/back_button.png");
	m_buttonsDesign[ButtonsDesign::bd_save_button].loadFromFile("resources/ButtonsDesign/save_button.png");

	m_buttonsMenu.resize(ButtonsMenu::bm_Total);
	m_buttonsMenu[ButtonsMenu::bm_New_Game_button].loadFromFile("resources/ButtonsMenu/New_Game_button.png");
	m_buttonsMenu[ButtonsMenu::bm_Design_button].loadFromFile("resources/ButtonsMenu/Design_button.png");
	m_buttonsMenu[ButtonsMenu::bm_Help_button].loadFromFile("resources/ButtonsMenu/Help_button.png");
	m_buttonsMenu[ButtonsMenu::bm_Settings_button].loadFromFile("resources/ButtonsMenu/Settings_button.png");
	m_buttonsMenu[ButtonsMenu::bm_Exit_button].loadFromFile("resources/ButtonsMenu/Exit_button.png");

	m_buttonsGame.resize(ButtonsGame::bg_Total);
	m_buttonsGame[ButtonsGame::bg_back_button].loadFromFile("resources/ButtonsGame/back_button.png");

	m_menu.resize(MenuBackground::mb_Total);
	m_menu[MenuBackground::mb_MenuBackground].loadFromFile("resources/menu_background.png");

}

void Resources::loadGameMusic()
{
	m_GameSoundsBuffer.resize(MusicGame::sg_Total);
	m_GameSoundsBuffer[MusicGame::sg_BelleMusic].loadFromFile("resources/Belle/BelleMusic.ogg");
	m_GameSoundsBuffer[MusicGame::sg_CinderMusic].loadFromFile("resources/Cinder/CinderMusic.ogg");
	m_GameSoundsBuffer[MusicGame::sg_JasminMusic].loadFromFile("resources/Jasmin/JasminMusic.ogg");
	m_GameSoundsBuffer[MusicGame::sg_PeterPenMusic].loadFromFile("resources/PeterPen/PeterPenMusic.ogg");
	m_GameSoundsBuffer[MusicGame::sg_SnowWhiteMusic].loadFromFile("resources/SnowWhite/SnowWhiteMusic.ogg");

}

void Resources::loadMenuMusic()
{
	m_MenuSoundsBuffer.resize(musicMenu::sm_Total);
	m_MenuSoundsBuffer[musicMenu::sm_MenuMusic].loadFromFile("resources/MenuMusic.ogg");
}

