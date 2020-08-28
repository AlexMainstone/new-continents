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

sf::Vector2i Map::tileToChunkPos(int x, int y) {
    int chunk_xpos = x % CHUNK_WIDTH;
    int chunk_ypos = y % CHUNK_HEIGHT;
    
    sf::Vector2i chunkpos;
    chunkpos.x = (x - chunk_xpos) / CHUNK_WIDTH;
    chunkpos.y = (y - chunk_ypos) / CHUNK_HEIGHT;
    return chunkpos;
}

void Map::setTile(int x, int y, Tile *tile, bool update) {
    int chunk_xpos = x % CHUNK_WIDTH;
    int chunk_ypos = y % CHUNK_HEIGHT;
    sf::Vector2i chunkpos = tileToChunkPos(x, y);

    map_data[chunkpos.x][chunkpos.y]->setTile(chunk_xpos, chunk_ypos, tile);

    if(update) {
        map_data[chunkpos.x][chunkpos.y]->updateTexture(tileset);
    }
}

void Map::addObject(Object *object) {
    int chunk_xpos = object->getPos().x % CHUNK_WIDTH;
    int chunk_ypos = object->getPos().y % CHUNK_HEIGHT;
    sf::Vector2i chunkpos = tileToChunkPos(object->getPos().x, object->getPos().y);
    object->setPos(chunk_xpos, chunk_ypos);
    map_data[chunkpos.x][chunkpos.y]->addObject(object);
}

Object *Map::getObject(int x, int y) {
    int chunk_xpos = x % CHUNK_WIDTH;
    int chunk_ypos = y % CHUNK_HEIGHT;
    sf::Vector2i chunkpos = tileToChunkPos(x, y);
    return map_data[chunkpos.x][chunkpos.y]->getObject(chunk_xpos, chunk_ypos);
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
            map_data[x][y]->drawChunk(target, tileset, sf::Vector2f(x * chunk_pixels.x, y * chunk_pixels.y));
        }
    }
}