#pragma once

#include <SFML/Graphics.hpp>
#include <queue>

#include "Resources/TileSet.hpp"

class Entity {
    public:
        Entity(sf::Vector2f pos, int tile, sf::Color color = sf::Color::White);
        virtual void update(float dt);
        virtual void draw(sf::RenderTarget &target, TileSet *tileset);
        
        void move(int x, int y);
        void move(sf::Vector2i movedir);
    private:
        sf::Vector2f pos;
        int tile;
        sf::Color color;

        std::queue<sf::Vector2i> move_queue;
        sf::Vector2f move_progress;
};