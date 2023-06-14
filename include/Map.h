#pragma once

#include <vector>
#include "Brick.h"

class Arrow;

class Map
{
public:
    explicit Map(const sf::Vector2u &m_size = {0, 0});

    Map(const Map &oldMap);

    void restart(const sf::Vector2u &size);

    void addBrick(Brick *brick);
    
    [[nodiscard]] const sf::Vector2u &getSize() const;

    [[nodiscard]] sf::Vector2f fixPosition(sf::Vector2f pos) const;

    [[nodiscard]] sf::Vector2f maxMove(const sf::FloatRect &firstRect, 
                                       const sf::Vector2f &deltaMove) const;

    [[nodiscard]] bool isCollide(const sf::FloatRect &firstRect,
                                 const sf::Vector2f &deltaMove) const;

    
    const Brick * const &operator() (int y, int x) const;
    Brick * &operator() (unsigned int y, unsigned int x);
    const Brick * const &operator[] (const sf::Vector2u &pos) const;
    Brick * &operator[] (const sf::Vector2u &pos);

    void addArrow(Arrow* arrow);
    void removveArrow(Arrow* arrow);

private:
    float MaxMoveX(const sf::FloatRect &firstRect, 
                   float deltaX) const;
    
    float MaxMoveY(const sf::FloatRect &firstRect,
                      float deltaY) const;
    
    // m_brickList[y][x] and not m_brickList[x][y]
    std::vector<std::vector<Brick *>> m_brickList;

    std::vector<Arrow *> m_arrowList;
    

    sf::Vector2u m_size;
};
