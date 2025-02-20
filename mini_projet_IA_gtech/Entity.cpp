#include "Entity.hpp"

Entity::Entity(float x, float y, sf::Color color, int hp) : health(hp) {
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

bool Entity::isAlive() const {
    return health > 0;
}

void Entity::takeDamage(int damage) {
    health -= damage;
}

bool Entity::operator==(const Entity& other) const {
    return shape.getPosition() == other.shape.getPosition() && health == other.health;
}