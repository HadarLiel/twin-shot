#include "Monsters.h"
#include "Monsters.h"
#include "Arrow.h"

Monsters::Monsters(const sf::Vector2u& position,
    const Map* map):
    MovingObject(sf::FloatRect(position.x, position.y, 32 * 1.9, 32 * 2.9), map),
    m_deltaPos(0, 0),
    m_speed(0, 0),
    m_isOnGround(false),
    m_isLeft(false)
{

}

void Monsters::update(const sf::Time& deltaTime)
{

    int gravity = 600;

    m_speed += {0, gravity* deltaTime.asSeconds()}; //20=m/s^2

    m_speed.x = 100;
    if (m_isLeft)
    {
        m_speed.x = -100;
    }


    m_deltaPos = { m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds() };

    m_isOnGround = false;



    sf::Vector2<bool> success = tryMove(m_deltaPos);
    if (!success.x)
    {
        m_isLeft = !m_isLeft;
    }
    if (!success.y)
    {
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
}

void Monsters::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape rect(
        sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    rect.setPosition(getBoundingRect().left, getBoundingRect().top);
    rect.setFillColor(sf::Color::Red);
    target.draw(rect, states);
}

bool Monsters::collideDD1(Object &other_object)
{
    return other_object.collideDD2(*this);
}

bool Monsters::collideDD2(Arrow& other_object)
{
    if (other_object.isDamage())
    {
        die();
        other_object.die();        
    }
    return true;
}
