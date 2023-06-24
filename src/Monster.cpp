#include "Monster.h"
#include "Monster.h"
#include "Arrow.h"

Monster::Monster(const sf::Vector2u& position,
    const Map* map,
    const int indexMonster,
    bool isProtected):
    MovingObject(sf::FloatRect(position.x, position.y - 32 * 2.9 + 32 - 0.0001, 32 * 1.9, 32 * 2.9), map),
    m_deltaPos(0, 0),
    m_speed(0, 0),
    m_isOnGround(false),
    m_isLeft(false),
    m_isFalling(false),
    m_indexMonster(indexMonster),
    m_sinceLastFall(sf::seconds(5)),
    m_isProtected(isProtected),
    m_hitProtects(false)
{

}

void Monster::update(const sf::Time& deltaTime)
{
    m_sinceLastFall += deltaTime;

    int gravity = 600;

    m_speed += {0, gravity* deltaTime.asSeconds()}; //20=m/s^2

    
    
    if (m_isFalling)
    {
        m_speed.x = 0;

        if (m_sinceLastFall > sf::seconds(5))
        {
            //m_sinceLastFall = sf::Time::Zero;
            if (m_isLeft)
            {
                m_speed.x = -100;
            }
            else
            {
                m_speed.x = 100;
            }
        } 
    }
    else
    {
        m_speed.x = 100;
        if (m_isLeft)
        {
            m_speed.x = -100;
        }
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
        m_isFalling = false;
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
    else
    {
        m_isFalling = true;
    }

    
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite sprite;
    if (m_isProtected)
    {
        sprite.setTexture(Resources::instance().getTexture(Resources::MONSTER_PROTECTED));
    }
    
    else
    {
        sprite.setTexture(Resources::instance().getTexture(m_indexMonster + Resources::MONSTER_START));
    }
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    if (!m_isLeft)
    {
        sprite.scale(-1.f, 1.f);
        sprite.setPosition(getBoundingRect().left + getBoundingRect().width, getBoundingRect().top);

    }
    
    target.draw(sprite, states);
}

bool Monster::collideDD1(Object &other_object)
{
    return other_object.collideDD2(*this);
}

bool Monster::collideDD2(Arrow& other_object)
{
    if (other_object.isDamage())
    {
        if (!m_isProtected)
        {
            die();
            
        }
        else
        {
            //protected monster
            m_isProtected = !m_isProtected;
        }

        other_object.die();
        
    }

    
    return true;
}


void Monster::setTextureIndex(int index)
{
    m_indexMonster = index;
}
