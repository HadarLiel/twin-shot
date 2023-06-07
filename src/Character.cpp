#include "Character.h"

Character::Character(const sf::Vector2u &position,
                     const sf::Vector2u &worldSize) :
        MovingObject(sf::FloatRect(position.x, position.y, 64, 96),
                     worldSize)
{

}

void Character::update(sf::Time deltaTime)
{
    sf::FloatRect rect = getBoundingRect();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect.left -= 100 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect.left += 100 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect.top -= 100 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect.top += 100 * deltaTime.asSeconds();
    }
    setBoundingRect(rect);
    MovingObject::FixModulu();
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape rect(
            sf::Vector2f(getBoundingRect().width, getBoundingRect().height));
    rect.setPosition(getBoundingRect().left, getBoundingRect().top);
    rect.setFillColor(sf::Color::Green);
    target.draw(rect, states);
}

bool Character::collideDD(Object *other_object)
{
    return other_object->collideDD2(*this);
}
