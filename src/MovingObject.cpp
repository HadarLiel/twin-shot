#include "MovingObject.h"



MovingObject::MovingObject(const sf::FloatRect &boundingRect,
                           const sf::Vector2u &worldSize):
Object(boundingRect),
m_worldSize(worldSize)
{

}

void MovingObject::FixModulu()
{
    sf::Vector2f position = getCenter();
    position.x = fmod(position.x, m_worldSize.x*32);
    position.y = fmod(position.y, m_worldSize.y*32);
    if (position.x < 0)
    {
        position.x += m_worldSize.x*32;
    }
    if (position.y < 0)
    {
        position.y += m_worldSize.y*32;
    }
    sf::FloatRect rect = getBoundingRect();
    rect.left = position.x - rect.width / 2;
    rect.top = position.y - rect.height / 2;
    setBoundingRect(rect);
}

bool MovingObject::collideDD(Object *other_object)
{
    return other_object->collideDD2(*this);
}
