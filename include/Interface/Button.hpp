#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/TileSet.hpp"

class Button {
    public:
        Button(sf::FloatRect rect);
        bool isPressed();
        bool isHovered();
        
        bool handleEvent(sf::Event e);

        void draw(sf::RenderTarget &target, TileSet *tileset);
    private:
        sf::FloatRect rect;
        bool hover;
        bool pressed;
};