#pragma once

#include <vector>
#include "Brick.h"

class Map
{
public:
    explicit Map(const sf::Vector2u &m_size = {0, 0});

    Map(const Map &oldMap);
//
//    Map(Map &&oldMap);
//
//    Map &operator=(const Map &oldMap);
//    
//    ~Map();

    void restart(const sf::Vector2u &size);

    void addBrick(Brick *brick);
    
    [[nodiscard]] const sf::Vector2u &getSize() const;

    [[nodiscard]] sf::Vector2f fixPosition(sf::Vector2f pos) const;

    [[nodiscard]] bool isCollide(const sf::FloatRect &firstRect,
                                 const sf::Vector2f &deltaMove) const;

    const Brick * const &operator() (unsigned int y, unsigned int x) const;
    Brick * &operator() (unsigned int y, unsigned int x);
    const Brick * const &operator[] (const sf::Vector2u &pos) const;
    Brick * &operator[] (const sf::Vector2u &pos);

private:
    // m_brickList[y][x] and not m_brickList[x][y]
    std::vector<std::vector<Brick *>> m_brickList;
    sf::Vector2u m_size;
};
