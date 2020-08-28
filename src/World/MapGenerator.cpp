#include "World/MapGenerator.hpp"
#include <cstdlib>

Map *MapGenerator::generate(TileSet *tileset, std::uint32_t seed) {
    int chunks = 3;

    if(seed == 0) {
        seed = time(0);
    }
    siv::PerlinNoise noise(seed);
    Map *map = new Map(chunks, chunks, tileset);

    for(int x = 0; x < CHUNK_WIDTH * chunks; x++) {
        for(int y = 0; y < CHUNK_HEIGHT * chunks; y++) {
            double n = noise.noise2D((x+8)/8.0, (y+8)/8.0);
            if(n > -0.15) {
                int n = rand() % 20;
                if(n == 0) {
                    map->setTile(x, y, tileset->getTile(2), false);
                // } else if(n < 5) {
                    // map->setTile(x, y, tileset->getTile(3), false);
                } else {
                    map->setTile(x, y, tileset->getTile(1), false);
                }
            } else {
                map->setTile(x, y, tileset->getTile(4), false);
                if(rand() % 2) {
                    map->addObject(new Object(tileset->getTile(5), sf::Vector2i(x, y)));
                } //else {
                    // map->setTile(x, y, tileset->getTile(5), false);
                //}
            }
        }
    }

    map->updateChunks();
    return map;
}