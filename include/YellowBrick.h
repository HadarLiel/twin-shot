#include "Brick.h"
#include "Map.h"

class YellowBrick : public Brick
{
public:
    YellowBrick(sf::Vector2u pos, const Map* map);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    [[nodiscard]] bool isBlock(const sf::Vector2f& deltaMove) const override;

    bool collideDD1(Object& other_object);
    bool collideDD2(Character& other_object);

    const sf::FloatRect& getCollisionRect() const override;

    void update(const sf::Time& deltaTime) override;


private:
    const Map* m_map;

    sf::Time m_showTime;

    sf::FloatRect m_collisionRect;

    //bool m_needChangeTime;
};