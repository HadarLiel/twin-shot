#pragma once
#include "Object.h"
#include "BricksList.h"

class MovingObject : public Object
{
public:
    explicit MovingObject(const sf::FloatRect &boundingRect, const sf::Vector2u &worldSize, const BricksList* bricksList);
    virtual void update(sf::Time deltaTime) = 0;
    bool collideDD1(Object *other_object) override;

    

protected:
    void FixModulu();

    bool isValid(sf::Vector2f pos) const;

private:
    sf::Vector2u m_worldSize;
    
    const BricksList* m_bricksList;

    
};