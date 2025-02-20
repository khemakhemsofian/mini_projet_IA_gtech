#include "Grid.hpp"

Grid::Grid() {
    // Initialisation de la grille
    cells.resize(GRID_WIDTH, std::vector<Cell>(GRID_HEIGHT));
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            cells[x][y].walkable = true; // Par défaut, toutes les cellules sont marchables
            cells[x][y].position = sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE);
            cells[x][y].shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cells[x][y].shape.setPosition(cells[x][y].position);
        }
    }
}

void Grid::loadFromFile(const std::string& filename) {
    // Charger la grille à partir d'un fichier
}

void Grid::draw(sf::RenderWindow& window) {
    for (const auto& column : cells) {
        for (const auto& cell : column) {
            window.draw(cell.shape);
        }
    }
}

Cell& Grid::getCell(int x, int y) {
    return cells[x][y];
}

std::vector<sf::Vector2i> Grid::getNeighbors(const sf::Vector2i& position) const {
    std::vector<sf::Vector2i> neighbors;
    std::vector<sf::Vector2i> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for (const auto& dir : directions) {
        sf::Vector2i neighborPos = position + dir;
        if (neighborPos.x >= 0 && neighborPos.x < GRID_WIDTH && neighborPos.y >= 0 && neighborPos.y < GRID_HEIGHT) {
            neighbors.push_back(neighborPos);
        }
    }

    return neighbors;
}