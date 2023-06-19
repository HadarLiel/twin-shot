#include "YellowBrick.h"
#include "Map.h"
#include "Character.h"
#include <iostream>

YellowBrick::YellowBrick(sf::Vector2u pos, const Map* map) :
    Brick(pos),
    m_map(map),
    m_showTime(sf::seconds(5))
{
    m_collisionRect = getBoundingRect();
    m_collisionRect.height = 1;
    m_collisionRect.top -= 1;
}

void YellowBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_showTime >= sf::seconds(5) || m_showTime <= sf::seconds(2))
    {
        sf::Sprite sprite;
        sprite.setTexture(Resources::instance().getTexture(Resources::BRICK_FALL_BRICK));
        sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
            getBoundingRect().height / sprite.getTexture()->getSize().y);
        sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

        target.draw(sprite, states);
    }
    
}

// collide make stop
bool YellowBrick::isBlock(const sf::Vector2f& deltaMove) const
{
    if (m_showTime < sf::seconds(5) && m_showTime > sf::seconds(2))
    {
        return false;
    }

    if (deltaMove.x < 0 && (*m_map)[{getPosition().x + 1, getPosition().y}] == nullptr)
    {
        return true;
    }
    else if (deltaMove.x > 0 && (*m_map)[{getPosition().x - 1, getPosition().y}] == nullptr)
    {
        return true;
    }

    

    return deltaMove.y > 0;
}

bool YellowBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}

bool YellowBrick::collideDD2(Character& other_object)
{
    if (other_object.getCollisionRect().intersects(getBoundingRect()))
    {
        return true;
    }
    if (m_showTime > sf::seconds(5))
    {
        m_showTime = sf::Time::Zero;
    }
    return true;
}

const sf::FloatRect& YellowBrick::getCollisionRect() const
{
    return m_collisionRect;
}

void YellowBrick::update(const sf::Time& deltaTime)
{
    m_showTime += deltaTime;
}

