#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Grid.hpp"
#include "Node.hpp"
#include <vector>

class AStar {
public:
    static std::vector<sf::Vector2i> findPath(Grid& grid, sf::Vector2i start, sf::Vector2i end);
};

#endif