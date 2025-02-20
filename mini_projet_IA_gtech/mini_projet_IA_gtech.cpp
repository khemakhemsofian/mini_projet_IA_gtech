#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Grid.hpp"
#include <vector>
#include <memory>

const int WINDOW_WIDTH = 800; // Définir la largeur de la fenêtre
const int WINDOW_HEIGHT = 600; // Définir la hauteur de la fenêtre

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jeu SFML - IA Ennemis");
    window.setFramerateLimit(60);

    Player player(400, 400, sf::Color::Blue, 10);
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.push_back(std::make_unique<Enemy>(100, 100, 10));
    enemies.push_back(std::make_unique<Enemy>(700, 100, 100));
    Grid grid;
    grid.loadFromFile("map.txt");

    std::vector<Entity*> neededEntities;
    neededEntities.push_back(&player);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Convertir le vecteur de unique_ptr en un vecteur de pointeurs bruts
        std::vector<Entity*> enemyPointers;
        for (const auto& enemy : enemies) {
            enemyPointers.push_back(enemy.get());
        }

        // Définir le vecteur neededEntities

        player.update(deltaTime, grid, neededEntities, enemyPointers);
        for (auto& enemy : enemies) {
            enemy->update(deltaTime, grid, neededEntities, enemyPointers);
        }

        window.clear();
        grid.draw(window);
        window.draw(player.shape);
        for (const auto& enemy : enemies) {
            if (enemy->isAlive()) {
                window.draw(enemy->shape);
            }
        }
        window.display();
    }
    return 0;
}
