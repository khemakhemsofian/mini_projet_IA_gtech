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
        // Logique pour l'�tat Idle
        // Transition vers l'�tat Patrol
        currentState = State::Patrol;
    }

    void FSM::handlePatrolState(std::shared_ptr<Entity> entity) {
        // Logique pour l'�tat Patrol
        // Transition vers l'�tat Chase si un joueur est d�tect�
        currentState = State::Chase;
    }

    void FSM::handleChaseState(std::shared_ptr<Entity> entity) {
        // Logique pour l'�tat Chase
        // Transition vers l'�tat Attack si le joueur est � port�e
        currentState = State::Attack;
    }

    void FSM::handleAttackState(std::shared_ptr<Entity> entity) {
        // Logique pour l'�tat Attack
        // Transition vers l'�tat Idle apr�s l'attaque
        currentState = State::Idle;
    }
}

