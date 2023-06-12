#include "BlueBrick.h"
#include "Map.h"

BlueBrick::BlueBrick(sf::Vector2u pos,const Map* map):
    Brick(pos),
    m_map(map)
{
    
}

void BlueBrick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    target.draw(shape, states);
}

// collide make stop
bool BlueBrick::isBlock(const sf::Vector2f &deltaMove) const
{
    if(deltaMove.x < 0 && (*m_map)[{getPosition().x + 1, getPosition().y}] == nullptr)
    {
        return true;
    }
    else if(deltaMove.x > 0 && (*m_map)[{getPosition().x - 1, getPosition().y}] == nullptr)
    {
        return true;
    }
    return deltaMove.y > 0; 
}