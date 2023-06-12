#pragma once

#include "MovingObject.h"
#include <functional>

class Character : public MovingObject
{
public:
    explicit Character(const sf::Vector2u &position,
                       const Map *map,
                       const std::function<void(std::unique_ptr<MovingObject>)> &addMapObjectFunc);

    void update(const sf::Time &deltaTime) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool collideDD1(Object *other_object) override;
    
private:
    sf::Vector2f m_deltaPos;
    sf::Vector2f m_speed;
    bool m_isOnGround;
    bool m_is_space;
    std::function<void(std::unique_ptr<MovingObject>)> m_addMapObjectFunc;
};