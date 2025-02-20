// Enemy.hpp
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "AStar.hpp"
#include "FSM.hpp"
#include "BehaviourTree.hpp"
#include "GOAP.hpp"
#include <memory>

class Enemy : public Entity {
public:
    Enemy(float x, float y, int hp);
    void update(float deltaTime, Grid& grid, std::vector<Entity*>& neededEntities, std::vector<Entity*>& enemies) override;

private:
    std::unique_ptr<AStar> aStar;
    std::unique_ptr<IA::FSM> fsm;
    std::unique_ptr<IA::BehaviourTree> behaviourTree;
    std::unique_ptr<IA::GOAP> goap;
};

#endif // ENEMY_HPP