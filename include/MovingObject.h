#pragma once
#include "Object.h"

class MovingObject : public Object
{
public:
    explicit MovingObject(const sf::FloatRect &boundingRect, const sf::Vector2u &worldSize);
    virtual void update(sf::Time deltaTime) = 0;
    bool collideDD(Object *other_object) override;
protected:
    void FixModulu();
private:
    sf::Vector2u m_worldSize;
};