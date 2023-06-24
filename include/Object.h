#pragma once

#include <SFML/Graphics.hpp>

class Character;
// todo: change to Monster (singular)
class Monster;
class Arrow;
class RegularBrick;
class BlockBrick;
class FallBrick;



class Object : public sf::Drawable
{
public:
    explicit Object(const sf::FloatRect &boundingRect);
    
    void collide(Object &other);

    [[nodiscard]] sf::Vector2f getCenter() const;

    virtual void update(const sf::Time &deltaTime){};
    
    void die();
    
    [[nodiscard]] bool isAlive() const;


    /**
     * collide function for double dispatch
     * must be implemented in the derived class as follows:
     * ```
     * bool collideDD1(Object &other_object)
     * {
     *     return other_object.collideDD2(this);
     * }
     * ```
     */
    virtual bool collideDD1(Object &other_object) = 0;

    // Character
    virtual bool collideDD2(Character &other);
    
    virtual bool collideDD2(Monster& other);

    virtual bool collideDD2(Arrow& other);

    virtual bool collideDD2(RegularBrick& other);

    virtual bool collideDD2(BlockBrick& other);

    virtual bool collideDD2(FallBrick& other);


    [[nodiscard]] const sf::FloatRect& getBoundingRect() const;

    [[nodiscard]] virtual const sf::FloatRect& getCollisionRect() const;


protected:    
    
    void setBoundingRect(const sf::FloatRect&);


private:
    sf::FloatRect m_boundingRect;
    bool m_isAlive;
};