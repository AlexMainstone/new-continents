#include "World/Tile.hpp"

Tile::Tile(int tile, sf::Color color, bool collision) {
    this->tile = tile;
    this->color = color;
    this->collision = collision;
}