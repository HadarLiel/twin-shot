#pragma once
#include "Object.h"
#include "Map.h"

class MovingObject : public Object
{
public:
    explicit MovingObject(const sf::FloatRect &boundingRect,
                          const Map* bricksList);
    
    bool collideDD1(Object *other_object) override;
    
    [[nodiscard]] const Map* getMap() const;
   

protected:
    // todo: why not `const&`?
    sf::Vector2<bool> tryMove(sf::Vector2f delta);
   

private:
    const Map* m_map;
};