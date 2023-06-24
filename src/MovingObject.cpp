#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject(const sf::FloatRect &boundingRect,
                           const Map* bricksList):
        Object(boundingRect),
        m_map(bricksList)
   
{

}

sf::Vector2<bool> MovingObject::tryMove(const sf::Vector2f &delta)
{
    
    sf::Vector2f deltaNew = m_map->maxMove(getBoundingRect(), delta);
    
    sf::FloatRect rect = getBoundingRect();
    sf::Vector2f fixPos = m_map->fixPosition(getCenter() + deltaNew);
    rect.left = fixPos.x - rect.width / 2;
    rect.top = fixPos.y - rect.height / 2;
    
    setBoundingRect(rect);
    return {deltaNew.x == delta.x, deltaNew.y == delta.y};
}

const Map *MovingObject::getMap() const
{
    return m_map;
}

