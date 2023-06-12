#include "BlueBrick.h"

BlueBrick::BlueBrick(sf::Vector2u pos):
    Brick(pos)
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

bool BlueBrick::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}

// collide make stop
bool BlueBrick::isCollideable(const sf::Vector2f &deltaMove) const
{
    return deltaMove.y > 0; 
}