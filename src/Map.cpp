#include "Map.h"

Map::Map(const sf::Vector2u &size) :
        m_size(size)
{

}

void Map::setSize(const sf::Vector2u &size)
{
    this->m_size = size;
}

const sf::Vector2u &Map::getSize() const
{
    return m_size;
}

void Map::addBrick(Brick *brick)
{
    m_brickList.push_back(brick);
}

const std::vector<Brick *> &Map::getBricks() const
{
    return m_brickList;
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

bool Map::isCollide(const sf::FloatRect &firstRect, 
                    const sf::Vector2f &deltaMove) const
{
    
    sf::FloatRect allRectsFirst[9];
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            allRectsFirst[(i + 1) * 3 + j + 1] = sf::FloatRect(firstRect.left + i * m_size.x * 32, firstRect.top + j * m_size.y * 32,
                                                               firstRect.width, firstRect.height);
        }
    }

    sf::FloatRect rect = firstRect;
    rect.left += deltaMove.x;
    rect.top += deltaMove.y;
    
    sf::FloatRect allRects[9];
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            allRects[(i + 1) * 3 + j + 1] = sf::FloatRect(rect.left + i * m_size.x * 32, rect.top + j * m_size.y * 32,
                                                          rect.width, rect.height);
        }
    }
    for (auto &brick : m_brickList)
    {
        for(int i = 0; i < 9; ++i)
        {
            if (brick->getBoundingRect().intersects(allRects[i]) && 
                !brick->getBoundingRect().intersects(allRectsFirst[i]) &&
                 brick->isCollideable(deltaMove))
            {
                return true;
            }
        }
    }
    return false;
    
}
