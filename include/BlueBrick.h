#pragma once

#include "Brick.h"

class BlueBrick : public Brick
{
public:
    BlueBrick(sf::Vector2u pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool collideDD1(Object *other_object) override;
    [[nodiscard]] bool isCollideable(const sf::Vector2f &deltaMove) const override;
    

private:

};