#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Object.h"
#include "Brick.h"
#include "Character.h"
#include "Monsters.h"
#include "Buttons.h"

class Level
{
public:
    explicit Level(const std::string &mapPath);
    void run(const int& indexCharacter);

private:
    std::vector<std::unique_ptr<Object>> m_objects;

    Map m_map;
    Character *m_character;
    std::vector<Monsters*> m_monsterList;

    Buttons m_buttons;
    
    int m_indexCharacter;
};