#include "Objects/Object.hpp"

Object::Object(Tile *tile, sf::Vector2i pos) : tile(tile), pos(pos) {}

Tile *Object::getTile() {
    return tile;
}

sf::Vector2i Object::getPos() {
    return pos;
}

void Object::setPos(int x, int y) {
    pos.x = x;
    pos.y = y;
}