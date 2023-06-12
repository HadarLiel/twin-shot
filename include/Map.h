#pragma once

#include <vector>
#include "Brick.h"

class Map
{
public:
    explicit Map(const sf::Vector2u &m_size = {0, 0});

    void setSize(const sf::Vector2u &size);

    void addBrick(Brick *brick);

    [[nodiscard]] const std::vector<Brick *> &getBricks() const;

    [[nodiscard]] const sf::Vector2u &getSize() const;

    sf::Vector2f fixPosition(sf::Vector2f pos) const;

    bool isCollide(const sf::FloatRect &firstRect,
                   const sf::Vector2f &deltaMove) const;


private:
    std::vector<Brick *> m_brickList;
    sf::Vector2u m_size;
};
