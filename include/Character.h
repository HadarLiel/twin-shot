#pragma once

#include "MovingObject.h"

class Character : public MovingObject
{
public:
    explicit Character(const sf::Vector2u &position,
                       const sf::Vector2u &worldSize,
                       const Map *bricksList);

    void update(sf::Time deltaTime) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool collideDD1(Object *other_object) override;

    const sf::Vector2f &getDeltaPosition() const;

    void resetDeltaPosition(const sf::Vector2f &newDelta);

private:
    sf::Vector2f m_deltaPos;

    sf::Vector2f m_speed;
};