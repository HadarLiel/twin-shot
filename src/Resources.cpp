#include "Resources.h"
#include <format>

Resources::Resources()
{
	loadtexture();
	loadMusic();
	loadLevels();
	m_font.loadFromFile("resources/arial.ttf");
}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

const sf::Font& Resources::getFont() const
{
	return m_font;
}

const sf::Image& Resources::getLevel(unsigned int index) const
{
	return m_levels[index];
}

const sf::Texture& Resources::getTexture(unsigned int index) const
{
	return m_objects[index];
}


const sf::SoundBuffer& Resources::getMusic(int index) const
{
	return m_SoundsBuffer[index];
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


	m_objects[Objects::MONSTER_PROTECTED].loadFromFile("resources/protectedMonster.png");
	
	m_objects[Objects::ARROW_ARROW].loadFromFile("resources/Arrow.png");

	m_objects[Objects::BUTTONS_DESIGN_BACK].loadFromFile("resources/ButtonsDesign/back_button.png");
	
	m_objects[Objects::BUTTONS_MENU_NEW_GAME].loadFromFile("resources/ButtonsMenu/New_Game_button.png");
	m_objects[Objects::BUTTONS_MENU_DESIGN].loadFromFile("resources/ButtonsMenu/Design_button.png");
	m_objects[Objects::BUTTONS_MENU_HELP].loadFromFile("resources/ButtonsMenu/Help_button.png");
	m_objects[Objects::BUTTONS_MENU_SETTINGS].loadFromFile("resources/ButtonsMenu/Settings_button.png");
	m_objects[Objects::BUTTONS_MENU_EXIT].loadFromFile("resources/ButtonsMenu/Exit_button.png");

	m_objects[Objects::BUTTONS_GAME_BACK].loadFromFile("resources/ButtonsGame/back_button.png");

	m_objects[Objects::BUTTONS_MUSIC_MENU].loadFromFile("resources/MusicMenu_button.png");
	m_objects[Objects::BUTTONS_MUSIC_GAME].loadFromFile("resources/MusicGame_button.png");

	m_objects[Objects::MENUBG_MENU_BACKGROUND].loadFromFile("resources/menu_background.png");

	m_objects[Objects::DESIGNBG_DESIGN_BACKGROUND].loadFromFile("resources/design_background.png");

	m_objects[Objects::BRICK_BLOCK_BRICK].loadFromFile("resources/Bricks/blockBrick.png");
	m_objects[Objects::BRICK_FALL_BRICK].loadFromFile("resources/Bricks/fallBrick.png");
	m_objects[Objects::BRICK_BROKEN_BRICK].loadFromFile("resources/Bricks/brokenBrick.png");
	m_objects[Objects::BRICK_REGULAR_BRICK].loadFromFile("resources/Bricks/regularBrick.png");


}

void Resources::loadMusic()
{
	m_SoundsBuffer.resize(MusicGame::SOUND_TOTAL);
	m_SoundsBuffer[MusicGame::SOUND_GAME_BELLE].loadFromFile("resources/Belle/BelleMusic.ogg");
	m_SoundsBuffer[MusicGame::SOUND_GAME_CINDERELLA].loadFromFile("resources/Cinder/CinderMusic.ogg");
	m_SoundsBuffer[MusicGame::SOUND_GAME_JASMIN].loadFromFile("resources/Jasmin/JasminMusic.ogg");
	m_SoundsBuffer[MusicGame::SOUND_GAME_PETER_PAN].loadFromFile("resources/PeterPen/PeterPenMusic.ogg");
	m_SoundsBuffer[MusicGame::SOUND_GAME_SNOW_WHITE].loadFromFile("resources/SnowWhite/SnowWhiteMusic.ogg");
	m_SoundsBuffer[MusicGame::SOUND_MENU_MENU].loadFromFile("resources/MenuMusic.ogg");

}

void Resources::loadLevels()
{
	m_levels.resize(NUM_OF_LEVELS);
	for (size_t i = 0; i < NUM_OF_LEVELS; i++)
	{
		m_levels[i].loadFromFile(std::format("resources/Levels/level{}.png", i+1));
	}
}


