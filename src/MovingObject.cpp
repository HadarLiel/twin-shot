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

bool MovingObject::tryMove(sf::Vector2f delta)
{
    sf::Vector2f position = getCenter();
    position += delta;
    position = m_map->fixPosition(position);
    
    sf::FloatRect rect = getBoundingRect();
    rect.left = position.x - rect.width / 2;
    rect.top = position.y - rect.height / 2;
    
    if(!m_map->isCollide(getBoundingRect(), delta))
    {
        setBoundingRect(rect);
        return true;
    }
    if(delta.x > 0)
    {
        float right = rect.left + rect.width;
        right = ((int)(right / 32)) * 32;
        rect.left = right - rect.width;
    }
    else if (delta.x < 0)
    {
        rect.left = ((int)(rect.left / 32) + 1) * 32;
    }
    if(delta.y > 0)
    {
        float bottom = rect.top + rect.height;
        bottom = ((int)(bottom / 32)) * 32;
        rect.top = bottom - rect.height;
    }
    else if (delta.y < 0)
    {
        rect.top = ((int)(rect.top / 32) + 1) * 32;
    }
    setBoundingRect(rect);
    
    return false;
}

const Map *MovingObject::getMap() const
{
    return m_map;
}

