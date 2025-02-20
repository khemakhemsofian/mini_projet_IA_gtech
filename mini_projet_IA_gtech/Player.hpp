// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"
#include <vector>

class Player : public Entity {
public:
    static constexpr float SPEED = 200.0f;
    static constexpr int DAMAGE = 20;
    static constexpr float ATTACK_COOLDOWN = 0.5f;
    float attackTimer;

    Player(float x, float y, sf::Color color, int hp);
    void attack(std::vector<Entity*> enemies);
    void update(float deltaTime, Grid& grid, std::vector<Entity*>& neededEntities, std::vector<Entity*>& enemies) override;
};

#endif // PLAYER_HPP
