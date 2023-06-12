#include "MovingObject.h"



MovingObject::MovingObject(const sf::FloatRect &boundingRect,
                           const sf::Vector2u &worldSize,
                           const Map* bricksList):
        Object(boundingRect),
        m_worldSize(worldSize),
        m_map(bricksList)
   
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


    //--------------------------------------

    //// Check if the new position collides with any bricks
    //if (!isValid(sf::Vector2f(rect.left, rect.top)))
    //{
    //    //todo: make him move down
    //    return;
    //}


    setBoundingRect(rect);
}

bool MovingObject::isValid(sf::Vector2f pos) const
{
    sf::FloatRect rect = getBoundingRect();
    rect.left = pos.x;
    rect.top = pos.y;

    for (auto &brick : m_map->getBricks())
    {
        if (brick->getBoundingRect().intersects(rect))
        {
            
            //// Exclude the top intersection check
            //if (brick->getBoundingRect().top  == rect.top + rect.height)
            //{
            //    return true;
            //}

            return false;
        }

       
    }
    
    return true;
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
    
    // todo: change isCollide to maxNotCollide
    if(!m_map->isCollide(getBoundingRect(), delta))
    {
        setBoundingRect(rect);
        return true;
    }
    return false;
}


