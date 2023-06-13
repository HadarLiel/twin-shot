#pragma once
#include "MovingObject.h"
#include "Character.h"

class Arrow :public MovingObject
{
public:
    explicit Arrow(const sf::Vector2u &position,
                       const Map *bricksList,
                        const bool &m_isLeft);

    void update(const sf::Time &deltaTime) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool collideDD1(Object *other_object) override;

    
private:
    sf::Vector2f m_deltaPos;
    sf::Vector2f m_speed;
    bool m_isOnGround;
    bool m_canUpdatePos;
    sf::Time m_leftTime;
    bool m_isLeft;

};