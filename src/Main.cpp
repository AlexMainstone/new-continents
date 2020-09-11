#include <SFML/Graphics.hpp>
#include "Scenes/GameScene.hpp"

int main() {
    // Create Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "New Continent");

    // Set window icon
    sf::Image icon;
    icon.loadFromFile("../res/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Initialize Scene
    GameScene *scene = new GameScene(window); // TODO implement scene system

    // Count delat time
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

        window.clear(sf::Color(71, 45, 60));

        scene->render(); // Render

        window.display();
    }
}