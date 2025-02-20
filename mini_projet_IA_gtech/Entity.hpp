// Entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.hpp"

class Entity {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    int health;

    Entity(float x, float y, sf::Color color, int hp);
    virtual void update(float deltaTime, Grid& grid, std::vector<Entity*>& neededEntities, std::vector<Entity*>& enemies) = 0;
    bool isAlive() const;
    void takeDamage(int damage);

    bool operator==(const Entity& other) const;
};

#endif // ENTITY_HPP