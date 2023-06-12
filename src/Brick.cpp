#include "Brick.h"
#include "Character.h"
#include <iostream>

Brick::Brick(const sf::Vector2u &pos) :
        Object(sf::FloatRect(pos.x * 32, pos.y * 32, 32, 32))
{

}

void Brick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape shape(sf::Vector2f(32, 32));
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    shape.setFillColor(sf::Color::Black);
    target.draw(shape, states);
}

bool Brick::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}

// collide make stop
bool Brick::isCollideable(const sf::Vector2f &deltaMove) const
{
    return true;
}
