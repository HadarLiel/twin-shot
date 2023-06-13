
#include <iostream>
#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Arrow.h"


Map::Map(const sf::Vector2u &size) :
        m_size(size)
{
    m_brickList.resize(size.y, std::vector<Brick *>(size.x, nullptr));
}

void Map::restart(const sf::Vector2u &size)
{
    this->m_size = size;
    m_brickList.clear();
    m_brickList.resize(size.y, std::vector<Brick *>(size.x, nullptr));
}

const sf::Vector2u &Map::getSize() const
{
    return m_size;
}

void Map::addBrick(Brick *brick)
{
    m_brickList[brick->getPosition().y][brick->getPosition().x] = brick;
}

sf::Vector2f Map::fixPosition(sf::Vector2f pos) const
{
    pos.x = fmod(pos.x, m_size.x * 32);
    pos.y = fmod(pos.y, m_size.y * 32);
    if (pos.x < 0)
    {
        pos.x += m_size.x * 32;
    }
    if (pos.y < 0)
    {
        pos.y += m_size.y * 32;
    }
    return pos;
}

Map::Map(const Map &oldMap)
{
    m_size = oldMap.m_size;
    m_brickList.clear();
    for (auto &brick: oldMap.m_brickList)
    {
        m_brickList.push_back(brick);
    }
}


const Brick *const &Map::operator[](const sf::Vector2u &pos) const
{
    sf::Vector2u pos_mod = sf::Vector2u(pos.x % m_size.x, pos.y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
}

Brick *&Map::operator[](const sf::Vector2u &pos)
{
    sf::Vector2u pos_mod = sf::Vector2u(pos.x % m_size.x, pos.y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
}

void Map::addArrow(Arrow *arrow)
{
    m_arrowList.push_back(arrow);
}

void Map::removveArrow(Arrow *arrow)
{
    auto it = std::find(m_arrowList.begin(), m_arrowList.end(), arrow);
    if (it != m_arrowList.end())
    {
        m_arrowList.erase(it);
    }

}

Brick *&Map::operator()(unsigned int y, unsigned int x)
{
    sf::Vector2u pos_mod = sf::Vector2u(x % m_size.x, y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
}

const Brick *const &Map::operator()(unsigned int y, unsigned int x) const
{
    sf::Vector2u pos_mod = sf::Vector2u(x % m_size.x, y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];

}

sf::Vector2f Map::maxMove(const sf::FloatRect &firstRect,
                          const sf::Vector2f &deltaMove) const
{
    sf::FloatRect currentRect = firstRect;
    sf::Vector2f maxDelta = deltaMove;
    maxDelta.x = MaxMoveX(currentRect, deltaMove.x);
    maxDelta.y = MaxMoveY(currentRect, deltaMove.y);
    return maxDelta;
}

float Map::MaxMoveX(const sf::FloatRect &firstRect, float deltaX) const
{
    int xIndex;
    float loc;
    float toReturn;
    if (deltaX > 0)
    {
        xIndex = (int) (firstRect.left + firstRect.width + deltaX) / 32;
        // todo: this is fucked up
        toReturn = xIndex * 32 - (firstRect.left + firstRect.width) - 0.001;
        loc = firstRect.left + firstRect.width;
    }
    else
    {
        xIndex = (int) (firstRect.left + deltaX) / 32;
        toReturn = (xIndex * 32 + 32 - firstRect.left);
        loc = firstRect.left;
    }
    
    int yStart = (int) firstRect.top / 32;
    int yEnd = (int) (firstRect.top + firstRect.height) / 32;
    if (xIndex != (int) (loc) / 32)
    {
        std::cout << xIndex << " diff\n";
        for (int y = yStart; y <= yEnd; ++y)
        {
            std::cout << (y % m_size.y) << " " 
                      << (xIndex % m_size.x) << " "
                      << (m_brickList[y % m_size.y][xIndex % m_size.x] == nullptr) << "\n";
            
            if (m_brickList[y % m_size.y][xIndex % m_size.x] != nullptr &&
                m_brickList[y % m_size.y][xIndex % m_size.x]->isBlock({deltaX, 0}))
            {
                std::cout << xIndex << " block " << toReturn << "\n";
                return toReturn;
            }
        }
    }
    return deltaX;
}

float Map::MaxMoveY(const sf::FloatRect &firstRect, float deltaY) const
{
    int yIndex;
    float loc;
    float toReturn;
    if (deltaY > 0)
    {
        yIndex = (int) (firstRect.top + firstRect.height + deltaY) / 32;
        toReturn = yIndex * 32 - (firstRect.top + firstRect.height) - 0.001;
        loc = firstRect.top + firstRect.height;
    }
    else
    {
        yIndex = (int) (firstRect.top + deltaY) / 32;
        toReturn = (yIndex * 32 + 32 - firstRect.top);
        loc = firstRect.top;
    }
    
    int xStart = (int) firstRect.left / 32;
    int xEnd = (int) (firstRect.left + firstRect.width) / 32;
    if (yIndex != (int) (loc) / 32)
    {
        for (int x = xStart; x <= xEnd; ++x)
        {
            if (m_brickList[yIndex % m_size.y][x % m_size.x] != nullptr &&
                m_brickList[yIndex % m_size.y][x % m_size.x]->isBlock({0, deltaY}))
            {
                return toReturn;
            }
        }
    }
    if (deltaY < 0)
    {
        return deltaY;
    }
    // here y is positive, we are going down
    // need to check with arrow
    sf::FloatRect afterMoveRect = firstRect;
    afterMoveRect.top += deltaY;

    for (auto arrow: m_arrowList)
    {
        if (arrow->getBoundingRect().intersects(afterMoveRect) &&
            !arrow->getBoundingRect().intersects(firstRect))
        {
            deltaY = std::min(deltaY,
                              arrow->getBoundingRect().top - firstRect.top - firstRect.height - 0.001f);
        }
    }
    return deltaY;
}
