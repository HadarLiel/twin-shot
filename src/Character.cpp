#include "Character.h"
#include "Arrow.h"
#include <iostream>
#include "Consts.h"

Character::Character(const sf::Vector2u &position,
                     const Map *map,
                     const std::function<void(std::unique_ptr<Arrow>)> &addArrowFunc):
        MovingObject(sf::FloatRect(position.x, position.y, 32*1.9, 32*2.9), map),
        m_deltaPos(0, 0),
        m_speed(0, 0),
        m_isOnGround(false),
        m_addArrowFunc(addArrowFunc),
        m_is_space(false),
        m_lives(3)
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
        m_addArrowFunc(std::make_unique<Arrow>(sf::Vector2u(rect.left + rect.width/2, rect.top + rect.height/2), getMap(), m_isLeft));
    }
    m_is_space = space;
    

    //the new gravity
    //physics formula to find position by speed and axeleration (�����)
    //posT = pos0 + speed0 * T

    m_deltaPos = {m_speed.x * deltaTime.asSeconds(),
                  m_speed.y * deltaTime.asSeconds()};

    m_isOnGround = false;
    sf::Vector2<bool> success = tryMove(m_deltaPos);
    
    if(!success.x)
    {
        m_speed.x = 0;
    }
    if(!success.y)
    {
        m_isOnGround = m_deltaPos.y > 0;
        m_speed.y = 0;
    }
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape rect(
        sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    rect.setPosition(getBoundingRect().left, getBoundingRect().top);
    rect.setFillColor(sf::Color::Green);
    target.draw(rect, states);

    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf"))
    {
        // Handle font loading error
        std::cout << "not load text\n";
    }

    sf::Text textlives("Lives: " + std::to_string(m_lives), font);
    textlives.setFillColor(sf::Color::Black);
    textlives.setPosition(Window_Width / buttonWidth, Window_Height / buttonHeight);
    sf::View oldview = target.getView();
    sf::View newView(sf::FloatRect(0.0f, 0.0f , target.getSize().x, target.getSize().y));
    target.setView(newView);
    target.draw(textlives);
    target.setView(oldview);
}

bool Character::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}

