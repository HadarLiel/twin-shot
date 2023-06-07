#pragma once

#include <SFML/Graphics.hpp>

class MovingObject;
class Character;
class Brick;

class Object : public sf::Drawable
{
public:
    void collide(Object &other);
    
    explicit Object(const sf::FloatRect &boundingRect);

    [[nodiscard]] sf::Vector2f getCenter() const;



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
    virtual bool collideDD(Object *other_object);

    // Object
    virtual bool collideDD2(Object &other);

    // MovingObject
    virtual bool collideDD2(MovingObject &other);

    // Character
    virtual bool collideDD2(Character &other);
    
    // Brick
    virtual bool collideDD2(Brick &other);



protected:    
    
    [[nodiscard]] const sf::FloatRect &getBoundingRect() const;
    void setBoundingRect(const sf::FloatRect &);


private:
    sf::FloatRect m_boundingRect;
};