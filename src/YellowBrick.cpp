#include "YellowBrick.h"
#include "Map.h"
#include "Character.h"
#include <iostream>

YellowBrick::YellowBrick(sf::Vector2u pos, const Map* map) :
    Brick(pos),
    m_map(map) //,
    //m_showTime(sf::seconds(5))
{

}

void YellowBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getTexture(Resources::BRICK_FALL_BRICK));
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    target.draw(sprite, states);

    /*sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);*/


   /* sf::RectangleShape collide_shape;
    collide_shape.setSize(sf::Vector2f(getBoundingRect().width, 1));
    collide_shape.setFillColor(sf::Color::Red);
    collide_shape.setPosition(shape.getPosition().x, shape.getPosition().y);*/

    

    /*target.draw(shape, states);
    target.draw(collide_shape, states);*/
}

// collide make stop
bool YellowBrick::isBlock(const sf::Vector2f& deltaMove) const
{
    if (deltaMove.x < 0 && (*m_map)[{getPosition().x + 1, getPosition().y}] == nullptr)
    {
        return true;
    }
    else if (deltaMove.x > 0 && (*m_map)[{getPosition().x - 1, getPosition().y}] == nullptr)
    {
        return true;
    }

    //if (deltaMove.y < 0)
    //{
    //    return false;
    //}

    //else
    //{
    //    std::cout << "need to fall after 5 seconds\n";
    //    if (m_showTime > sf::seconds(5))
    //    {
    //        m_needChangeTime = true;
    //    }

    //    return true;
    //    //we want to let him stop but fall

    //}

    return deltaMove.y > 0;
}

bool YellowBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}

bool YellowBrick::collideDD2(Character& other_object)
{
    
    return true;
}

