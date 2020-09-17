#include <SFML/Graphics.hpp>
#include "Scenes/GameScene.hpp"

#include <sstream>
#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"

int main() {
    // Create Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "New Continent");
    ImGui::SFML::Init(window);

    // Set window icon
    sf::Image icon;
    icon.loadFromFile("../res/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Initialize Scene
    GameScene *scene = new GameScene(window); // TODO implement scene system

    // Count delat time
    sf::Clock deltaclock;
    float lastTime = 0.0;
    while(window.isOpen()) {
        // Handle Events
        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                window.close();
            }
            ImGui::SFML::ProcessEvent(e);
            scene->handleEvent(e);
        }

        // Update
        ImGui::SFML::Update(window, deltaclock.getElapsedTime());
        float currentTime = deltaclock.restart().asSeconds();
        std::ostringstream sstream;
        sstream << std::floor(1.0f / (currentTime));
        lastTime = currentTime;
        scene->update(currentTime);

        ImGui::Begin("Performance");
        ImGui::LabelText(sstream.str().c_str(), "FPS:");
        ImGui::End();

        window.clear(sf::Color(71, 45, 60));

        scene->render(); // Render
        ImGui::SFML::Render(window);

        window.display();

    }

    ImGui::SFML::Shutdown();
}