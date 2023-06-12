#include "Brick.h"
#include "Character.h"
#include "Consts.h"
#include <iostream>

Brick::Brick(const sf::Vector2u &pos) :
        Object(sf::FloatRect(pos.x * pixel, pos.y * pixel, pixel, pixel)),
        m_position(pos)
{

}

const sf::Vector2u &Brick::getPosition() const
{
    return m_position;
}
