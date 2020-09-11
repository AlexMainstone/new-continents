#pragma once

#include "Objects/Object.hpp"

class TreeObject : public Object {
    public:
        Object(Tile *tile, sf::Vector2i pos);
};