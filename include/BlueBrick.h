#pragma once

#include "Brick.h"
#include "Map.h"

class BlueBrick : public Brick
{
public:
    BlueBrick(sf::Vector2u pos,const Map* map);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    [[nodiscard]] bool isBlock(const sf::Vector2f &deltaMove) const override;
    
    bool collideDD1(Object& other_object);
private:
    const Map* m_map;
};