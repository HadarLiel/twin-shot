#pragma once
#include "Object.h"
class Brick: public Object
{
public:
    Brick(const sf::Vector2u &pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool collideDD(Object *other_object) override;
    
    bool collideDD2(Character &other_object) override;
    
private:

};