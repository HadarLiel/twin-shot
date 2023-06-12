#pragma once
#include "Object.h"
class Brick: public Object
{
public:
    explicit Brick(const sf::Vector2u &pos);
    [[nodiscard]] virtual bool isBlock(const sf::Vector2f &deltaMove) const = 0;
    [[nodiscard]] const sf::Vector2u &getPosition() const;
    
private:
    sf::Vector2u m_position;
};