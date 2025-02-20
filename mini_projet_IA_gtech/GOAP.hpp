#ifndef GOAP_HPP
#define GOAP_HPP

#include <memory>
#include "Entity.hpp"

namespace IA {
    class GOAP {
    public:
        GOAP();
        void plan(std::shared_ptr<Entity> entity);
    private:
        // M�thodes et attributs priv�s pour le GOAP
    };
}

#endif // GOAP_HPP