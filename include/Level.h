#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Object.h"
#include "Brick.h"
#include "Character.h"

class Level
{
public:
    explicit Level(const std::string &mapPath);
    void run();

private:
    std::vector<std::unique_ptr<Object>> m_objects;
    Character *m_character;
};