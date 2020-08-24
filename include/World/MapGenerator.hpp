#pragma once

#include "World/Map.hpp"
#include "Maths/PerlinNoise.hpp"

class MapGenerator {
    public:
        Map *generate(TileSet *tileset, std::uint32_t seed = 0);
};