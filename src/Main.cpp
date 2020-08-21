#include <SFML/Graphics.hpp>
#include "Scenes/GameScene.hpp"

int main() {
    // Create Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "base-builder");

    GameScene *scene = new GameScene(window);

    sf::Clock deltaclock;
    while(window.isOpen()) {
        // Handle Events
        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                window.close();
            }
            scene->handleEvent(e);
        }

        // Update
        scene->update(deltaclock.restart().asSeconds());

        // Render
        window.clear();

        // Draw
        scene->render();

        window.display();
    }
}