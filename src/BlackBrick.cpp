#include "BlackBrick.h"
#include <iostream>

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
    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getBrickTexture(0));
    sprite.setScale(getBoundingRect().width/ sprite.getTexture()->getSize().x,
                    getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    target.draw (sprite, states);

    /*sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(getBoundingRect().left, getBoundingRect().top);
    target.draw(shape, states);*/
}

bool BlackBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}

