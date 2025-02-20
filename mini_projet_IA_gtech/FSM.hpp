#ifndef FSM_HPP
#define FSM_HPP

#include <memory>
#include "Entity.hpp"

namespace IA {
    class FSM {
    public:
        FSM();
        void update(std::shared_ptr<Entity> entity);
    private:
        enum class State {
            Idle,
            Patrol,
            Chase,
            Attack
        };

        State currentState;
        void handleIdleState(std::shared_ptr<Entity> entity);
        void handlePatrolState(std::shared_ptr<Entity> entity);
        void handleChaseState(std::shared_ptr<Entity> entity);
        void handleAttackState(std::shared_ptr<Entity> entity);
    };
}

#endif // FSM_HPP

