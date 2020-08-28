#pragma once

#include <string>
#include "Resources/TileSet.hpp"

class Text {
    public:
        Text(const char *text, sf::Vector2f pos, sf::Color color = sf::Color::White, float scale = 1.0);

        void setColor(sf::Color color);

        int getSize();
        
        void draw(sf::RenderTarget &target, TileSet *tileset);
    private:
        int charToTile(char c);
        std::string text;
        sf::Vector2f pos;
        sf::Color color;

        float scale;
};