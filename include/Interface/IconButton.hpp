#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/TileSet.hpp"

class IconButton {
    public:
        IconButton(sf::Vector2f pos, int tile, int tilesize, float scale = 1.0);

        bool isPressed();
        bool isHovered();

        sf::Vector2f setPosition(sf::Vector2f pos);
        
        bool handleEvent(sf::Event e);

        void draw(sf::RenderTarget &target, TileSet *tileset);
    private:
        bool hover;
        bool pressed;

        int tile;

        float scale;

        sf::FloatRect rect;
};