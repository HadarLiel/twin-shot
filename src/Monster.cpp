#include "Monster.h"
#include "Arrow.h"

Monster::Monster(const sf::Vector2u& position,
    const Map* map,
    const int indexMonster,
    bool isProtected) :
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
    // Constructor for the Monster class

    // Initialize member variables with provided values

    // Set the initial position and size of the Monster object
    // The position is adjusted to align the monster properly on the ground
    // The size is based on a factor of the tile size (32)

    // Initialize other member variables
}

void Monster::update(const sf::Time& deltaTime)
{
    // Update function for the Monster object

    // Increase the time since last fall by deltaTime
    m_sinceLastFall += deltaTime;

    // Set the value for gravity
    int gravity = 600;

    // Apply gravity to the speed of the Monster object
    m_speed += {0, gravity* deltaTime.asSeconds()};

    if (m_isFalling)
    {
        // If the monster is falling, set the horizontal speed to 0

        // If enough time has passed since the last fall, start moving in the opposite direction
        if (m_sinceLastFall > sf::seconds(5))
        {
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
        // If not falling, set the horizontal speed to a constant value

        // Set the horizontal speed based on the direction the monster is facing
        m_speed.x = 100;
        if (m_isLeft)
        {
            m_speed.x = -100;
        }
    }

    // Calculate the change in position based on the speed and deltaTime
    m_deltaPos = { m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds() };

    // Reset the flag for being on the ground
    m_isOnGround = false;

    // Attempt to move the monster by m_deltaPos and check for successful movement
    sf::Vector2<bool> success = tryMove(m_deltaPos);

    if (!success.x)
    {
        // If unsuccessful horizontal movement, change the direction the monster is facing
        m_isLeft = !m_isLeft;
    }

    if (!success.y)
    {
        // If unsuccessful vertical movement, update flags and speed
        m_isFalling = false;
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
    else
    {
        // If successful vertical movement, set the falling flag
        m_isFalling = true;
    }
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Draw the Monster object on the render target

    // Create a sprite for the Monster object
    sf::Sprite sprite;

    // Set the texture of the sprite based on whether the monster is protected or not
    if (m_isProtected)
    {
        sprite.setTexture(Resources::instance().getTexture(Resources::MONSTER_PROTECTED));
    }
    else
    {
        sprite.setTexture(Resources::instance().getTexture(m_indexMonster + Resources::MONSTER_START));
    }

    // Scale the sprite to match the size of the Monster object's bounding rectangle
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);

    // Set the position of the sprite to match the Monster object's bounding rectangle
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    if (!m_isLeft)
    {
        // If facing right, flip the sprite horizontally
        sprite.scale(-1.f, 1.f);
        sprite.setPosition(getBoundingRect().left + getBoundingRect().width, getBoundingRect().top);
    }

    // Draw the sprite on the render target
    target.draw(sprite, states);
}

bool Monster::collideDD1(Object& other_object)
{
    // Handle collision with another object of type DD1

    // Call the collideDD2 function of the other object with this Monster object
    return other_object.collideDD2(*this);
}

bool Monster::collideDD2(Arrow& other_object)
{
    // Handle collision with an Arrow object (DD2)

    if (other_object.isDamage())
    {
        if (!m_isProtected)
        {
            // If the monster is not protected, it dies
            die();
        }
        else
        {
            // If the monster is protected, toggle the protection state
            m_isProtected = !m_isProtected;
        }

        // The arrow also dies
        other_object.die();
    }

    return true;
}

void Monster::setTextureIndex(int index)
{
    // Set the index of the texture for the Monster object
    m_indexMonster = index;
}
