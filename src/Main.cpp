#include <SFML/Graphics.hpp>
#include "Scenes/GameScene.hpp"

int main() {
    // Create Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Settlex");

    sf::Image icon;
    icon.loadFromFile("../res/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

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
        window.clear(sf::Color(71, 45, 60));

        // Draw
        scene->render();

        window.display();
    }
}