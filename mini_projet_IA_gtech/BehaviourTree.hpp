#ifndef BEHAVIOURTREE_HPP
#define BEHAVIOURTREE_HPP

#include <memory>
#include "Entity.hpp"

namespace IA {
    class BehaviourTree {
    public:
        BehaviourTree();
        void execute(std::shared_ptr<Entity> entity);
    private:
        // M�thodes et attributs priv�s pour les Behaviour Trees
    };
}

#endif // BEHAVIOURTREE_HPP

