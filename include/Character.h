#pragma once

#include "MovingObject.h"
#include <functional>
#include <SFML/Graphics.hpp>

class Character : public MovingObject
{
public:
    explicit Character(const sf::Vector2u &position,
                       const Map *map,
                       const std::function<void(std::unique_ptr<Arrow>)> &addArrow,
                       const int indexCharcter);

    void update(const sf::Time &deltaTime) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool collideDD1(Object& other_object);

    bool collideDD2(Monster& other_object);

    void setTextureIndex(int index);

    int getLives();


private:
    sf::Vector2f m_deltaPos;
    sf::Vector2f m_speed;
    bool m_isOnGround;
    bool m_is_space;
    std::function<void(std::unique_ptr<Arrow>)> m_addArrowFunc;
    bool m_isLeft; //to check the direction to throw arrow
    sf::Time m_sinceLastMonster;

    int m_lives;

    int m_indexCharcter;
    
};
