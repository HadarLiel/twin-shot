#include "Object.h"
#include "MovingObject.h"
#include "Character.h"
#include "Brick.h"

Object::Object(const sf::FloatRect &boundingRect):
        m_boundingRect(boundingRect),
        m_isAlive(true)
{

}

const sf::FloatRect &Object::getBoundingRect() const
{
    return m_boundingRect;
}

void Object::setBoundingRect(const sf::FloatRect &rect)
{
    m_boundingRect = rect;
}

sf::Vector2f Object::getCenter() const
{
    
    return sf::Vector2f(m_boundingRect.left + m_boundingRect.width / 2,
                        m_boundingRect.top + m_boundingRect.height / 2);
}

bool Object::collideDD2(Monsters& other)
{
    return false;
}

bool Object::collideDD2(Arrow& other)
{
    return false;
}

bool Object::collideDD2(PassBrick& other)
{
    return false;
}

bool Object::collideDD2(FallBrick& other)
{
    return false;
}

bool Object::collideDD2(BlockBrick& other)
{
    return false;
}
bool Object::collideDD2(Character& other)
{
    return false;
}

//regular
void Object::collide(Object &other)
{
    if (getBoundingRect().intersects(other.getBoundingRect()))
    {
        if(!collideDD1(other))
        {
            other.collideDD1(*this);
        }
    }
}

void Object::die()
{
    m_isAlive = false;
}

bool Object::isAlive() const
{
    return m_isAlive;
}
