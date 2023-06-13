#include "BlackBrick.h"

BlackBrick::BlackBrick(sf::Vector2u pos) :
        Brick(pos)
{

}

bool BlackBrick::isBlock(const sf::Vector2f &deltaMove) const
{
    return true;
}

void BlackBrick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    target.draw(shape, states);
}

