#include "Enemy.hpp"
#include <cmath>

Enemy::Enemy(float x, float y, int hp) : Entity(x, y, sf::Color::Red, hp) {}

void Enemy::update(float deltaTime, Grid& grid, std::vector<Entity*> players) {
    if (players.empty()) return;

    // Trouve le player le plus proche
    Entity* playerProche = players[0];
    float minDistance = std::hypot(playerProche->shape.getPosition().x - shape.getPosition().x,
        playerProche->shape.getPosition().y - shape.getPosition().y);

    for (auto& player : players) {
        float distance = std::hypot(player->shape.getPosition().x - shape.getPosition().x,
            player->shape.getPosition().y - shape.getPosition().y);
        if (distance < minDistance) {
            playerProche = player;
            minDistance = distance;
        }
    }

    // Se déplacer vers le player le plus proche
    sf::Vector2f direction = playerProche->shape.getPosition() - shape.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length; // Normalise la direction
    }

    velocity = direction * SPEED;
    shape.move(velocity * deltaTime);
     if (shape.getGlobalBounds().intersects(playerProche->shape.getGlobalBounds())) {
        playerProche->takeDamage(DAMAGE);
    }
}

