#include "MovingObject.h"



MovingObject::MovingObject(const sf::FloatRect &boundingRect,
                           const sf::Vector2u &worldSize,
                           const Map* bricksList):
        Object(boundingRect),
        m_worldSize(worldSize),
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
        rect.left = ((int)(rect.left / 32)) * 32;
    }
    else if (delta.x < 0)
    {
        rect.left = ((int)(rect.left / 32) + 1) * 32;
    }
    if(delta.y > 0)
    {
        rect.top = ((int)(rect.top / 32)) * 32;
    }
    else if (delta.y < 0)
    {
        rect.top = ((int)(rect.top / 32) + 1) * 32;
    }
    setBoundingRect(rect);
    
    return false;
}


