#pragma once

#include "World/Map.hpp"
#include "Maths/PerlinNoise.hpp"
#include "python3.8/Python.h"

class MapGenerator {
    public:
        Map *generate(TileSet *tileset, std::uint32_t seed = 0);
        Map *generate_from_py(TileSet *tileset);
    private:
        PyObject *pInt;
};