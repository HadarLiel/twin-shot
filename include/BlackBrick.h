#pragma once

#include "Brick.h"
class BlackBrick : public Brick
{
public:
    BlackBrick(sf::Vector2u pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    [[nodiscard]] bool isBlock(const sf::Vector2f &deltaMove) const override;

private:

};