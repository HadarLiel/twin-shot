#include "Arrow.h"

Arrow::Arrow(const sf::Vector2u &position,
                     const Map *map,
                     const bool& isLeft) :
        MovingObject(sf::FloatRect(position.x, position.y, 32*2, 32*0.25), map),
        m_deltaPos(0, 0),
        m_speed(100, 0),
        m_isOnGround(false),
        m_canUpdatePos(true),
        m_leftTime(sf::seconds(5)),
        m_isLeft(isLeft)
{

}

void Arrow::update(const sf::Time &deltaTime)
{
    
    m_leftTime -= deltaTime;
    if(m_leftTime <= sf::Time::Zero)
    {
        die();
    }
    if(!m_canUpdatePos)
    {
        return;
    }
    int gravity = 100;

    m_speed += {0, gravity * deltaTime.asSeconds()}; //20=m/s^2

    if (!m_isLeft)
    {
        m_speed.x = 400;
    }
    else
    {
        m_speed.x = -400;
    }
    
    sf::FloatRect rect = getBoundingRect();
    
    if(!tryMove({0,m_deltaPos.y}))
    {
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
    if(!tryMove({m_deltaPos.x,0}))
    {
        m_canUpdatePos = false;
        m_speed.x = 0;
    }
    


    //the new gravity
    //physics formula to find position by speed and axeleration (�����)
    //posT = pos0 + speed0 * T

    m_deltaPos = {m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds()};

    m_isOnGround = false;
    
}


void Arrow::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape rect(
            sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    rect.setPosition(getBoundingRect().left, getBoundingRect().top);
    rect.setFillColor(sf::Color::Magenta);
    target.draw(rect, states);
}

bool Arrow::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}