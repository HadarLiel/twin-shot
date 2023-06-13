#include "MovingObject.h"
#include <iostream>



MovingObject::MovingObject(const sf::FloatRect &boundingRect,
                           const Map* bricksList):
        Object(boundingRect),
        m_map(bricksList)
   
{

}

bool MovingObject::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}

sf::Vector2<bool> MovingObject::tryMove(sf::Vector2f delta)
{
    
    sf::Vector2f deltaNew = m_map->maxMove(getBoundingRect(), delta);
    
    sf::FloatRect rect = getBoundingRect();
//    std::cout << "deltaNew: " << (deltaNew.x == delta.x) << " " << (deltaNew.y == delta.y) << std::endl;
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

