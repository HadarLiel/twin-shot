#include "FallBrick.h"
#include "Map.h"
#include <iostream>

FallBrick::FallBrick(sf::Vector2u pos, const Map* map) :
    Brick(pos),
    m_map(map) //,
    //m_showTime(sf::seconds(5))
{

}

void FallBrick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);


    sf::RectangleShape collide_shape;
    collide_shape.setSize(sf::Vector2f(getBoundingRect().width, 1));
    collide_shape.setFillColor(sf::Color::Red);
    collide_shape.setPosition(shape.getPosition().x, shape.getPosition().y);

    //todo: add to m_object

   
    /*if (m_showTime < sf::seconds(5))
    {
        sf::Int64 sec = m_showTime.asMicroseconds();
        sec %= sf::seconds(0.1 * 2).asMicroseconds();
        if (sec > sf::seconds(0.1).asMicroseconds())
        {
            target.draw(shape, states);
            target.draw(collide_shape, states);
        }
    }
    else
    {
        target.draw(shape, states);
        target.draw(collide_shape, states);
    }*/

    target.draw(shape, states);
    target.draw(collide_shape, states);
}

// collide make stop
bool FallBrick::isBlock(const sf::Vector2f& deltaMove) const
{
    if (deltaMove.x < 0 && (*m_map)[{getPosition().x + 1, getPosition().y}] == nullptr)
    {
        return true;
    }
    else if (deltaMove.x > 0 && (*m_map)[{getPosition().x - 1, getPosition().y}] == nullptr)
    {
        return true;
    }

    if (deltaMove.y < 0)
    {
        return false;
    }

    else
    {
        std::cout << "need to fall after 5 seconds\n";
        

        
        return true;
        //we want to let him stop but fall

    }

    //return deltaMove.y > 0;
}

bool FallBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}


