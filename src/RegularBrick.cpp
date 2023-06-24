#include "RegularBrick.h"
#include "Map.h"

RegularBrick::RegularBrick(sf::Vector2u pos,const Map* map):
    Brick(pos),
    m_map(map)
{
    
}

void RegularBrick::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    sf::Sprite sprite;
    sprite.setTexture(Resources::instance().getTexture(Resources::BRICK_REGULAR_BRICK));
    sprite.setScale(getBoundingRect().width / sprite.getTexture()->getSize().x,
        getBoundingRect().height / sprite.getTexture()->getSize().y);
    sprite.setPosition(getBoundingRect().left, getBoundingRect().top);

    target.draw(sprite, states);

}

// collide make stop
bool RegularBrick::isBlock(const sf::Vector2f &deltaMove) const
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

bool RegularBrick::collideDD1(Object& other_object)
{
    return other_object.collideDD2(*this);
}