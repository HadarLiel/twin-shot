#include "Brick.h"
#include "Map.h"
#include "Character.h"

class FallBrick : public Brick
{
public:
    FallBrick(sf::Vector2u pos, const Map* map);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    [[nodiscard]] bool isBlock(const sf::Vector2f& deltaMove) const override;

    bool collideDD1(Object& other_object);
    //bool collideDD2(Character& other_object);

private:
    const Map* m_map;

    sf::Time m_showTime;

    //bool m_needChangeTime;
};