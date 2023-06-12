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
    shape.setFillColor(sf::Color::Blue);
    target.draw(shape, states);
}

bool Brick::collideDD1(Object *other_object)
{
    return other_object->collideDD2(*this);
}

bool Brick::collideDD2(Character &character)
{
    sf::Vector2f resetPos = character.getDeltaPosition();
    sf::FloatRect rect = getBoundingRect();
    sf::FloatRect charPrevRect = character.getBoundingRect(); //before the collision

    charPrevRect.top -= character.getDeltaPosition().y;

    if (!charPrevRect.intersects(rect)) //if we are not in collision, we want to change the y
    {

        resetPos.y = 0;
    }

    charPrevRect.top += character.getDeltaPosition().y;
    charPrevRect.left -= character.getDeltaPosition().x;

    if (!charPrevRect.intersects(rect)) //if we are not in collision, we want to change the x
    {
        resetPos.x = 0;
    }

    character.resetDeltaPosition(resetPos);


    return true;
}



