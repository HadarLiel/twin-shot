#include "BlueBrick.h"
#include "Map.h"

BlueBrick::BlueBrick(sf::Vector2u pos,const Map* map):
    Brick(pos),
    m_map(map)
{
    
}

void BlueBrick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getBrickTexture(1));
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    target.draw(sprite, states);

   /* sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    target.draw(shape, states);*/
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

bool BlueBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}