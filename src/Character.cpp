#include "Character.h"

Character::Character(const sf::Vector2u &position,
                     const sf::Vector2u &worldSize,
                     const Map *bricksList) :
        MovingObject(sf::FloatRect(position.x, position.y, 64, 96),
                     worldSize, bricksList),
        m_deltaPos(0, 0),
        m_speed(0, 0),
        m_isOnGround(false)
{

}

void Character::update(sf::Time deltaTime)
{

    int gravity = 600;

    m_speed += {0, gravity * deltaTime.asSeconds()}; //20=m/s^2

    sf::FloatRect rect = getBoundingRect();
    if (m_isOnGround)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            m_speed.y = -600;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_speed.x = -200;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_speed.x = 200;
    }
    else
    {
        m_speed.x = 0;
    }
    

    //the new gravity
    //physics formula to find position by speed and axeleration (�����)
    //posT = pos0 + speed0 * T

    m_deltaPos = {m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds()};

    m_isOnGround = false;
    if(!tryMove({0,m_deltaPos.y}))
    {
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
    if(!tryMove({m_deltaPos.x,0}))
    {
        m_speed.x = 0;
    }
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape rect(
            sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    rect.setPosition(getBoundingRect().left, getBoundingRect().top);
    rect.setFillColor(sf::Color::Green);
    target.draw(rect, states);
}

bool Character::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}