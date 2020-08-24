#pragma once

#include <SFML/Graphics.hpp>

class Tile {
    public:
        Tile(int tile, sf::Color color, bool collision);
        int tile;
        sf::Color color;
        bool collision;
    private:
};