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

//const sf::Texture& Resources::getButtonDesignTexture(int index_type) const
//{
//	return m_buttonsDesign[index_type];
//}
//
//const sf::Texture& Resources::getButtonGameTexture(int index_type) const
//{
//	return m_buttonsGame[index_type];
//}
//
//const sf::Texture& Resources::getButtonMenuTexture(int index_type) const
//{
//	return m_buttonsMenu[index_type];
//}
//
//const sf::Texture& Resources::getCharacterTexture(int index_type) const
//{
//	return m_character[index_type];
//}
//
//const sf::Texture& Resources::getMonsterTexture(int index_type) const
//{
//	return m_monster[index_type];
//}
//
//const sf::Texture& Resources::getBrickTexture(int index_type) const
//{
//	return m_brick[index_type];
//}
//
//const sf::Texture& Resources::getMenuTexture(int index_type) const
//{
//	return m_menu[index_type];
//}

const sf::Font& Resources::getFont() const
{
	return m_font;
}

const sf::Texture& Resources::getTexture(int index_type) const
{
	return m_objects[index_type];
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
	//todo: add image og arrow

	m_objects.resize(Objects::Total);

	m_objects[Objects::CHARCTER_BELLE].loadFromFile("resources/Belle/belle.png");
	m_objects[Objects::CHARCTER_CINDERELLA].loadFromFile("resources/Cinder/cinderella.png");
	m_objects[Objects::CHARCTER_JASMIN].loadFromFile("resources/Jasmin/jasmin.png");
	m_objects[Objects::CHARCTER_PETER_PAN].loadFromFile("resources/PeterPen/peterPen.png");
	m_objects[Objects::CHARCTER_SNOW_WHITE].loadFromFile("resources/SnowWhite/snow.png");

	m_objects[Objects::MONSTER_BEAST].loadFromFile("resources/Belle/Beast.png");
	m_objects[Objects::MONSTER_EVIL_CINDERELLA].loadFromFile("resources/Cinder/EvilCinder.png");
	m_objects[Objects::MONSTER_JAFAR].loadFromFile("resources/Jasmin/Jafar.png");
	m_objects[Objects::MONSTER_CAPTAIN_HOOK].loadFromFile("resources/PeterPen/CaptainHook.png");
	m_objects[Objects::MONSTER_EVIL_QWEEN].loadFromFile("resources/SnowWhite/EvilQween.png");
	
	m_objects[Objects::ARROW_ARROW].loadFromFile("resources/Arrow.png");


	m_objects[Objects::BUTTONS_DESIGN_BACK].loadFromFile("resources/ButtonsDesign/back_button.png");
	m_objects[Objects::BUTTONS_DESIGN_SAVE].loadFromFile("resources/ButtonsDesign/save_button.png");

	m_objects[Objects::BUTTONS_MENU_NEW_GAME].loadFromFile("resources/ButtonsMenu/New_Game_button.png");
	m_objects[Objects::BUTTONS_MENU_DESIGN].loadFromFile("resources/ButtonsMenu/Design_button.png");
	m_objects[Objects::BUTTONS_MENU_HELP].loadFromFile("resources/ButtonsMenu/Help_button.png");
	m_objects[Objects::BUTTONS_MENU_SETTINGS].loadFromFile("resources/ButtonsMenu/Settings_button.png");
	m_objects[Objects::BUTTONS_MENU_EXIT].loadFromFile("resources/ButtonsMenu/Exit_button.png");

	m_objects[Objects::BUTTONS_GAME_BACK].loadFromFile("resources/ButtonsGame/back_button.png");

	m_objects[Objects::MENUBG_MENU_BACKGROUND].loadFromFile("resources/menu_background.png");

	m_objects[Objects::DESIGNBG_DESIGN_BACKGROUND].loadFromFile("resources/design_background.png");

	m_objects[Objects::BRICK_BLOCK_BRICK].loadFromFile("resources/Bricks/blockBrick.png");
	m_objects[Objects::BRICK_FALL_BRICK].loadFromFile("resources/Bricks/fallBrick.png");
	m_objects[Objects::BRICK_REGULAR_BRICK].loadFromFile("resources/Bricks/regularBrick.png");


	/*m_character.resize(Objects::c_Total);
	m_character[Objects::c_Belle].loadFromFile("resources/Belle/belle.png");
	m_character[Objects::c_Cinder].loadFromFile("resources/Cinder/cinderella.png");
	m_character[Objects::c_Jasmin].loadFromFile("resources/Jasmin/jasmin.png");
	m_character[Objects::c_PeterPen].loadFromFile("resources/PeterPen/peterPen.png");
	m_character[Objects::c_SnowWhite].loadFromFile("resources/SnowWhite/snow.png");
	
	m_monster.resize(Objects::m_Total);
	m_monster[Objects::m_Beast].loadFromFile("resources/Belle/Beast.png");
	m_monster[Objects::m_EvilCinder].loadFromFile("resources/Cinder/EvilCinder.png");
	m_monster[Objects::m_Jafar].loadFromFile("resources/Jasmin/Jafar.png");
	m_monster[Objects::m_CaptainHook].loadFromFile("resources/PeterPen/CaptainHook.png");
	m_monster[Objects::m_EvilQween].loadFromFile("resources/SnowWhite/EvilQween.png");

	m_buttonsDesign.resize(Objects::bd_Total);
	m_buttonsDesign[Objects::bd_back_button].loadFromFile("resources/ButtonsDesign/back_button.png");
	m_buttonsDesign[Objects::bd_save_button].loadFromFile("resources/ButtonsDesign/save_button.png");

	m_buttonsMenu.resize(Objects::bm_Total);
	m_buttonsMenu[Objects::bm_New_Game_button].loadFromFile("resources/ButtonsMenu/New_Game_button.png");
	m_buttonsMenu[Objects::bm_Design_button].loadFromFile("resources/ButtonsMenu/Design_button.png");
	m_buttonsMenu[Objects::bm_Help_button].loadFromFile("resources/ButtonsMenu/Help_button.png");
	m_buttonsMenu[Objects::bm_Settings_button].loadFromFile("resources/ButtonsMenu/Settings_button.png");
	m_buttonsMenu[Objects::bm_Exit_button].loadFromFile("resources/ButtonsMenu/Exit_button.png");

	m_buttonsGame.resize(Objects::bg_Total);
	m_buttonsGame[Objects::bg_back_button].loadFromFile("resources/ButtonsGame/back_button.png");

	m_menu.resize(Objects::mb_Total);
	m_menu[Objects::mb_MenuBackground].loadFromFile("resources/menu_background.png");

	m_brick.resize(Objects::b_Total);
	m_brick[Objects::b_blockBrick].loadFromFile("resources/Bricks/blockBrick.png");
	m_brick[Objects::b_fallBrick].loadFromFile("resources/Bricks/fallBrick.png");
	m_brick[Objects::b_regularBrick].loadFromFile("resources/Bricks/regularBrick.png");*/

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

