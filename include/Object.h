#pragma once

#include <SFML/Graphics.hpp>

class MovingObject;
class Character;
class Brick;

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
     * mus be implemented in the derived class as follows:
     * ```
     * bool collideDD(Object *other_object)
     * {
     *     return other_object->collideDD2(this);
     * }
     * ```
     */
    virtual bool collideDD1(Object *other_object);

    // Object
    virtual bool collideDD2(Object &other);

    // MovingObject
    virtual bool collideDD2(MovingObject &other);

    // Character
    virtual bool collideDD2(Character &other);
    
    // Brick
    virtual bool collideDD2(Brick &other);


    [[nodiscard]] const sf::FloatRect& getBoundingRect() const;

protected:    
    
    void setBoundingRect(const sf::FloatRect&);


private:
    sf::FloatRect m_boundingRect;
    bool m_isAlive;
};