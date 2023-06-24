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

const sf::FloatRect& Object::getCollisionRect() const
{
    return getBoundingRect();
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

bool Object::collideDD2(Monster& other)
{
    return false;
}

bool Object::collideDD2(Arrow& other)
{
    return false;
}

bool Object::collideDD2(BlueBrick& other)
{
    return false;
}

bool Object::collideDD2(YellowBrick& other)
{
    return false;
}

bool Object::collideDD2(BlackBrick& other)
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
    if (getCollisionRect().intersects(other.getCollisionRect()))
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
