#include "Character.h"
#include "Arrow.h"

Character::Character(const sf::Vector2u &position,
                     const Map *map,
                     const std::function<void(std::unique_ptr<MovingObject>)> &addMapObjectFunc) :
        MovingObject(sf::FloatRect(position.x, position.y, 32*2, 32*3), map),
        m_deltaPos(0, 0),
        m_speed(0, 0),
        m_isOnGround(false),
        m_addMapObjectFunc(addMapObjectFunc),
        m_is_space(false)
{

}

void Character::update(const sf::Time &deltaTime)
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
        m_isLeft =true;
        m_speed.x = -200;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_isLeft =false;
        m_speed.x = 200;
    }
    else
    {
        m_speed.x = 0;
    }
    bool space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    if (!m_is_space && space)
    {
        m_addMapObjectFunc(std::make_unique<Arrow>(sf::Vector2u(rect.left, rect.top), getMap(), m_isLeft));
    }
    m_is_space = space;
    

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
