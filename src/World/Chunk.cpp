#include "World/Chunk.hpp"

Chunk::Chunk(TileSet *tileset) {
    render_texture.create(CHUNK_WIDTH * tileset->getTileSize(), CHUNK_HEIGHT * tileset->getTileSize());

    for(int x = 0; x < CHUNK_WIDTH; x++) {
        for(int y = 0; y < CHUNK_HEIGHT; y++) {
            chunk_data[x][y] = nullptr;
        }
    }

}

void Chunk::updateTexture(TileSet *tileset) {
    render_texture.clear(sf::Color(71, 45, 60));

    for(int x = 0; x < CHUNK_WIDTH; x++) {
        for(int y = 0; y < CHUNK_HEIGHT; y++) {
            tileset->drawSprite(render_texture, sf::Vector2f(x * tileset->getTileSize(), y * tileset->getTileSize()), chunk_data[x][y]->tile, chunk_data[x][y]->color);
        }
    }

    render_texture.display();
    sprite.setTexture(render_texture.getTexture());
}

void Chunk::setTile(int x, int y, Tile *tile) {
    chunk_data[x][y] = tile;
}

Tile *Chunk::getTile(int x, int y) {
    return chunk_data[x][y];
}

void Chunk::addObject(Object *obj) {
    object_list.push_back(obj);
}

Object *Chunk::getObject(int x, int y) {
    for(auto o : object_list) {
        if(o->getPos().x == x && o->getPos().y == y) {
            return o;
        }
    }
    return nullptr;
}

void Chunk::drawChunk(sf::RenderTarget &target, TileSet *tileset, sf::Vector2f pos) {
    sprite.setPosition(pos);
    target.draw(sprite);

    for(auto o : object_list) {
        tileset->drawSprite(target, sf::Vector2f(o->getPos().x * tileset->getTileSize(), o->getPos().y * tileset->getTileSize()), o->getTile()->tile, o->getTile()->color);
    }
}