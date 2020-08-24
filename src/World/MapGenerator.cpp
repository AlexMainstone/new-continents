#include "World/MapGenerator.hpp"
#include <cstdlib>

Map *MapGenerator::generate(TileSet *tileset, std::uint32_t seed) {
    int chunks = 6;

    if(seed == 0) {
        seed = time(0);
    }
    siv::PerlinNoise noise(seed);
    Map *map = new Map(chunks, chunks, tileset);

    for(int x = 0; x < CHUNK_WIDTH * chunks; x++) {
        for(int y = 0; y < CHUNK_HEIGHT * chunks; y++) {
            double n = noise.noise2D(x/10.0, y/10.0);
            if(n > -0.15) {
                map->setTile(x, y, tileset->getTile(1), false);
            } else {
                if(rand() % 2) {
                    map->setTile(x, y, tileset->getTile(2), false);
                } else {
                    map->setTile(x, y, tileset->getTile(3), false);
                }
            }
        }
    }

    map->updateChunks();
    return map;
}