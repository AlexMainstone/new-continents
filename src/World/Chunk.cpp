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

#include<iostream>
void Chunk::setTile(int x, int y, Tile *tile) {
    chunk_data[x][y] = tile;
}

void Chunk::drawChunk(sf::RenderTarget &target, sf::Vector2f pos) {
    sprite.setPosition(pos);
    target.draw(sprite);
}