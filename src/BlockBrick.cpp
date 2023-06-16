#include "BlockBrick.h"
#include <iostream>

BlockBrick::BlockBrick(sf::Vector2u pos) :
        Brick(pos)
{

}

bool BlockBrick::isBlock(const sf::Vector2f &deltaMove) const
{
    return true;   
}

void BlockBrick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    target.draw(shape, states);
}

bool BlockBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}

