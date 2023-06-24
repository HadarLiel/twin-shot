#pragma once

#include "MovingObject.h"
#include <functional>


class Monster : public MovingObject
{
public:
    explicit Monster(const sf::Vector2u& position,
        const Map* map,
        const int indexMonster,
        bool isProtected);

    void update(const sf::Time& deltaTime) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool collideDD1(Object& other_object);

    bool collideDD2(Arrow& other_object);

    void setTextureIndex(int index);


private:
    sf::Vector2f m_deltaPos;
    sf::Vector2f m_speed;
    bool m_isOnGround;
    bool m_isLeft;

    bool m_isFalling;

    int m_indexMonster;
    
    sf::Time m_sinceLastFall;

    bool m_isProtected;

    bool m_hitProtects;
};