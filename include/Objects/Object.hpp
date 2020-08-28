#pragma once

#include "World/Tile.hpp"

class Object {
    public:
        Object(Tile *tile, sf::Vector2i pos);
        Tile *getTile();
        sf::Vector2i getPos();
        void setPos(int x, int y);
    private:
        Tile *tile;
        sf::Vector2i pos;
};