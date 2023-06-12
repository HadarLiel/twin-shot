#include "Character.h"

Character::Character(const sf::Vector2u &position,
                     const sf::Vector2u &worldSize,
                     const Map *bricksList) :
        MovingObject(sf::FloatRect(position.x, position.y, 64, 96),
                     worldSize, bricksList),
        m_deltaPos(0, 0),
        m_speed(0, 0)
{

}

void Character::update(sf::Time deltaTime)
{

    int gravity = 200;

    m_speed += {0, gravity * deltaTime.asSeconds()}; //20=m/s^2

    sf::FloatRect rect = getBoundingRect();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_speed.y = -100;
    }

    //the new gravity
    //physics formula to find position by speed and axeleration (�����)
    //posT = pos0 + speed0 * T

    m_deltaPos = {m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds()};

    if(!tryMove({0,m_deltaPos.y}))
    {
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

const sf::Vector2f &Character::getDeltaPosition() const
{
    return m_deltaPos;
}

void Character::resetDeltaPosition(const sf::Vector2f &newDelta)
{
    sf::FloatRect rect = getBoundingRect();
    rect.left -= m_deltaPos.x - newDelta.x; //���� ��� ����� �� ���� �����
    rect.top -= m_deltaPos.y - newDelta.y;

    setBoundingRect(rect);
    FixModulu();
    m_deltaPos = newDelta;
}