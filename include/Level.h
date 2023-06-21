#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Object.h"
#include "Brick.h"
#include "Character.h"
#include "Monsters.h"
#include "Buttons.h"
#include "Settings.h"

class Level
{
public:
    explicit Level(int levelIndex/*const std::string& mapName*/, int index, MusicStruct musicStruct);
    bool run();

private:
    std::vector<std::unique_ptr<Object>> m_objects;
    sf::Sound m_sound;
    Map m_map;
    Character *m_character;
    std::vector<Monsters*> m_monsterList;

    Buttons m_buttons;
    
    Settings m_settings;

    int m_indexCharacter;

    int m_levelIndex;
    MusicStruct m_musicStruct;

    bool m_isProtected;
};