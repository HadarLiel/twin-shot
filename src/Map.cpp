
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

bool Map::isCollide(const sf::FloatRect &firstRect,
                    const sf::Vector2f &deltaMove) const
{

    sf::FloatRect currentRect = firstRect;
    currentRect.left += deltaMove.x;
    currentRect.top += deltaMove.y;

    sf::Vector2u iterations = sf::Vector2u(firstRect.width / 32 + 2,
                                           firstRect.height / 32 + 2);
    
    sf::Vector2f fixed = fixPosition({currentRect.left, currentRect.top});


    sf::Vector2u firstPos = sf::Vector2u(fixed.x / 32,
                                         fixed.y / 32);
    
    for(int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            sf::FloatRect first_test_rect = firstRect;
            first_test_rect.left += j * m_size.x * 32;
            first_test_rect.top += i * m_size.y * 32;
            
            sf::FloatRect curr_test_rect = currentRect;
            curr_test_rect.left += j * m_size.x * 32;
            curr_test_rect.top += i * m_size.y * 32;

            for (size_t k = 0; k < iterations.y; ++k)
            {
                for (size_t l = 0; l < iterations.x; ++l)
                {
                    sf::Vector2u pos = sf::Vector2u(firstPos.x + l, firstPos.y + k);
                    pos.x %= m_size.x;
                    pos.y %= m_size.y;

                    if (m_brickList[pos.y][pos.x] != nullptr &&
                        m_brickList[pos.y][pos.x]->getBoundingRect().intersects(
                                curr_test_rect) &&
                        !m_brickList[pos.y][pos.x]->getBoundingRect().intersects(
                                first_test_rect) &&
                        m_brickList[pos.y][pos.x]->isBlock(deltaMove))
                    {
                        return true;
                    }


                }
            }

            
        }
    }
    

    return false;
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




const Brick * const &Map::operator[](const sf::Vector2u &pos) const
{
    sf::Vector2u pos_mod = sf::Vector2u(pos.x % m_size.x, pos.y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
}
Brick * &Map::operator[](const sf::Vector2u &pos)
{
    sf::Vector2u pos_mod = sf::Vector2u(pos.x % m_size.x, pos.y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
}

void Map::addArrow(Arrow* arrow)
{
    m_arrowList.push_back(arrow);
}

void Map::removveArrow(Arrow* arrow)
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

const Brick * const &Map::operator()(unsigned int y, unsigned int x) const
{
    sf::Vector2u pos_mod = sf::Vector2u(x % m_size.x, y % m_size.y);
    return m_brickList[pos_mod.y][pos_mod.x];
    
}
