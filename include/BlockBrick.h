#pragma once

#include "Brick.h"

class BlockBrick : public Brick
{
public:
    BlockBrick(sf::Vector2u pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    [[nodiscard]] bool isBlock(const sf::Vector2f &deltaMove) const override;
    bool collideDD1(Object& other_object);

private:
};