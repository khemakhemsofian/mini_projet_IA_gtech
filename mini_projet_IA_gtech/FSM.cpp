#include "FSM.hpp"

namespace IA {
    FSM::FSM() : currentState(State::Idle) {
        // Initialisation
    }

    void FSM::update(std::shared_ptr<Entity> entity) {
        switch (currentState) {
        case State::Idle:
            handleIdleState(entity);
            break;
        case State::Patrol:
            handlePatrolState(entity);
            break;
        case State::Chase:
            handleChaseState(entity);
            break;
        case State::Attack:
            handleAttackState(entity);
            break;
        }
    }

    void FSM::handleIdleState(std::shared_ptr<Entity> entity) {
        // Logique pour l'état Idle
        // Transition vers l'état Patrol
        currentState = State::Patrol;
    }

    void FSM::handlePatrolState(std::shared_ptr<Entity> entity) {
        // Logique pour l'état Patrol
        // Transition vers l'état Chase si un joueur est détecté
        currentState = State::Chase;
    }

    void FSM::handleChaseState(std::shared_ptr<Entity> entity) {
        // Logique pour l'état Chase
        // Transition vers l'état Attack si le joueur est à portée
        currentState = State::Attack;
    }

    void FSM::handleAttackState(std::shared_ptr<Entity> entity) {
        // Logique pour l'état Attack
        // Transition vers l'état Idle après l'attaque
        currentState = State::Idle;
    }
}

