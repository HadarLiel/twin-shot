#pragma once
#include "MovingObject.h"

class Character : public MovingObject
{
public:
    explicit Character(const sf::Vector2u &position, const sf::Vector2u &worldSize);
    void update(sf::Time deltaTime) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool collideDD(Object *other_object) override;
    
    sf::Vector2f getDeltaPosition(sf::Time deltaTime);
private:
    
};