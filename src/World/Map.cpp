#include "World/Map.hpp"

Map::Map(int width, int height, TileSet *tileset) {
    map_width = width;
    map_height = height;

    this->tileset = tileset;

    chunk_pixels = sf::Vector2f(tileset->getTileSize() * CHUNK_WIDTH, tileset->getTileSize() * CHUNK_HEIGHT);
    
    for(int x = 0; x < width; x++) {
        map_data.push_back(std::vector<Chunk *>());
        for(int y = 0; y < height; y++) {
            map_data[x].push_back(new Chunk(tileset));
        }
    }
}

void Map::setTile(int x, int y, Tile *tile, bool update) {
    int chunk_xpos = x % CHUNK_WIDTH;
    int chunk_ypos = y % CHUNK_HEIGHT;
    
    int chunk_x = (x - chunk_xpos) / CHUNK_WIDTH;
    int chunk_y = (y - chunk_ypos) / CHUNK_HEIGHT;

    map_data[chunk_x][chunk_y]->setTile(chunk_xpos, chunk_ypos, tile);

    if(update) {
        map_data[chunk_x][chunk_y]->updateTexture(tileset);
    }
}

void Map::updateChunks() {
    for(int x = 0; x < map_width; x++) {
        for(int y = 0; y < map_height; y++) {
            map_data[x][y]->updateTexture(tileset);
        }
    }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int x = 0; x < map_width; x++) {
        for(int y = 0; y < map_height; y++) {
            map_data[x][y]->drawChunk(target, sf::Vector2f(x * chunk_pixels.x, y * chunk_pixels.y));
        }
    }
}