#pragma once

#include "MovingObject.h"
#include <functional>

class Monsters : public MovingObject
{
public:
    explicit Monsters(const sf::Vector2u& position,
        const Map* map);

    void update(const sf::Time& deltaTime) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool collideDD1(Object* other_object) override;


private:
    sf::Vector2f m_deltaPos;
    sf::Vector2f m_speed;
    bool m_isOnGround;
    bool m_isLeft;
};