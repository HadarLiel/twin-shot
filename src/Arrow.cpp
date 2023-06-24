#include "Arrow.h"
#include <iostream>

Arrow::Arrow(const sf::Vector2u& position, const Map* map, const bool& isLeft)
    : MovingObject(sf::FloatRect(position.x, position.y, 32 * 2, 32 * 0.25), map),
    m_deltaPos(0, 0),
    m_speed(100, 0),
    m_isOnGround(false),
    m_canUpdatePos(true),
    m_leftTime(sf::seconds(5)),
    m_isLeft(isLeft),
    m_sinceLastBlock(sf::seconds(3))
{
    // Constructor initializes the arrow object with the given position, map, and direction (isLeft).
    // It sets the size of the arrow's bounding rectangle, initializes member variables, and sets a timer for the arrow's lifetime.
}

void Arrow::update(const sf::Time& deltaTime)
{
    // The update function is called to update the arrow's state based on the elapsed time (deltaTime).
    // It decreases the remaining lifetime of the arrow and checks if it should be destroyed.
    m_leftTime -= deltaTime;
    if (m_leftTime <= sf::Time::Zero)
    {
        die();
    }

    // The arrow's movement and collision logic is updated only if it can update its position.
    if (!m_canUpdatePos)
    {
        return;
    }

    // Gravity is applied to the arrow's speed.
    int gravity = 100;
    m_speed += {0, gravity* deltaTime.asSeconds()};

    // Set the horizontal speed based on the arrow's direction (m_isLeft).
    if (!m_isLeft)
    {
        m_speed.x = 400;
    }
    else
    {
        m_speed.x = -400;
    }

    // Calculate the change in position (deltaPos) based on the speed and deltaTime.
    m_deltaPos = { m_speed.x * deltaTime.asSeconds(), m_speed.y * deltaTime.asSeconds() };

    // Try to move the arrow using the deltaPos and check for collision.
    sf::FloatRect rect = getBoundingRect();
    sf::Vector2<bool> successMove = tryMove(m_deltaPos);

    // If the arrow cannot move horizontally, reset its position, stop updating its position, and set its horizontal speed to zero.
    if (!successMove.x)
    {
        m_leftTime = sf::seconds(5);
        m_canUpdatePos = false;
        m_speed.x = 0;
    }

    // If the arrow cannot move vertically, determine if it is on the ground and stop its vertical speed.
    if (!successMove.y)
    {
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }

    m_isOnGround = false;
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // The draw function is responsible for rendering the arrow object on the game screen.
    // It draws the arrow sprite based on its position, scale, and remaining lifetime.

    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getTexture(Resources::ARROW_ARROW));

    // Scale the sprite to match the size of the arrow's bounding rectangle.
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    // If the remaining lifetime is less than 1 second, animate the arrow by flipping it horizontally.
    if (m_leftTime < sf::seconds(1))
    {
        sf::Int64 sec = m_leftTime.asMicroseconds();
        sec %= sf::seconds(0.1 * 2).asMicroseconds();
        if (sec > sf::seconds(0.1).asMicroseconds())
        {
            if (m_isLeft)
            {
                sprite.scale(-1.f, 1.f);
                sprite.setPosition(getBoundingRect().left + getBoundingRect().width, getBoundingRect().top);
            }
            target.draw(sprite, states);
        }
    }
    else
    {
        if (m_isLeft)
        {
            sprite.scale(-1.f, 1.f);
            sprite.setPosition(getBoundingRect().left + getBoundingRect().width, getBoundingRect().top);
        }
        target.draw(sprite, states);
    }
}

bool Arrow::collideDD1(Object& other_object)
{
    // The collideDD1 function checks if the arrow collides with another object.
    // It calls the collideDD2 function of the other object to handle the collision.
    return other_object.collideDD2(*this);
}

bool Arrow::isDamage()
{
    // The isDamage function determines if the arrow can cause damage.
    // It returns true if the arrow is not on the ground and can update its position.
    return !m_isOnGround && m_canUpdatePos;
}

