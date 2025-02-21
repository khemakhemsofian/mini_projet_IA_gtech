// Pathfinding.hpp

#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Grid.hpp"
#include "Node.hpp"

class Pathfinding {
public:
    std::vector<sf::Vector2i> findPath(Grid& grid, sf::Vector2i start, sf::Vector2i end);
};

#endif // PATHFINDING_HPP
