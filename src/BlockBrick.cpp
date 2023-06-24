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
    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getTexture(Resources::BRICK_BLOCK_BRICK));
    sprite.setScale(getBoundingRect().width/ sprite.getTexture()->getSize().x,
                    getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    target.draw (sprite, states);

}

bool BlockBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}

