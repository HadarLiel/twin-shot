#include "Object.h"
#include "MovingObject.h"
#include "Character.h"
#include "Brick.h"

Object::Object(const sf::FloatRect &boundingRect):
        m_boundingRect(boundingRect)
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

bool Object::collideDD2(Object &other)
{
    return false;
}

// by default
bool Object::collideDD2(MovingObject &other)
{
    return collideDD2(static_cast<Object &>(other));
}

bool Object::collideDD2(Character &other)
{
    return collideDD2(static_cast<MovingObject &>(other));
}

bool Object::collideDD2(Brick &other)
{
    return collideDD2(static_cast<Object &>(other));
}

bool Object::collideDD(Object *other_object)
{
    return other_object->collideDD2(*this);
}

void Object::collide(Object &other)
{
    if (getBoundingRect().intersects(other.getBoundingRect()))
    {
        if(!collideDD(&other))
        {
            other.collideDD(this);
        }
    }
}