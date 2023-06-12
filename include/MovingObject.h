#pragma once
#include "Object.h"
#include "Map.h"

class MovingObject : public Object
{
public:
    explicit MovingObject(const sf::FloatRect &boundingRect,
                          const sf::Vector2u &worldSize,
                          const Map* bricksList);
    
    virtual void update(sf::Time deltaTime) = 0;
    
    bool collideDD1(Object *other_object) override;

    

protected:
    bool tryMove(sf::Vector2f delta);

private:
    sf::Vector2u m_worldSize;
    const Map* m_map;
};