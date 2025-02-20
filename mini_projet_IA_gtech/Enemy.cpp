#include "Enemy.hpp"

Enemy::Enemy(float x, float y, int hp)
    : Entity(x, y, sf::Color::Red, hp),
    aStar(std::make_unique<AStar>()),
    fsm(std::make_unique<IA::FSM>()),
    behaviourTree(std::make_unique<IA::BehaviourTree>()),
    goap(std::make_unique<IA::GOAP>()) {
}

void Enemy::update(float deltaTime, Grid& grid, std::vector<Entity*>& neededEntities, std::vector<Entity*>& enemies) {
    // Utiliser les techniques d'IA pour mettre à jour l'ennemi
    // Exemple : Utiliser A* pour trouver un chemin
    auto path = aStar->findPath(grid, { (int)shape.getPosition().x / 40,(int)shape.getPosition().y / 40 }, { (int)neededEntities[0]->shape.getPosition().x / 40, (int)neededEntities[0]->shape.getPosition().y / 40 });
};
    // Implémenter la logique de mise à jour en utilisant FSM, Behaviour Trees, GOAP
