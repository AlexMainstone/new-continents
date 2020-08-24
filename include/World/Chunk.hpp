#pragma once

#include <SFML/Graphics.hpp>

#include "Resources/TileSet.hpp"
#include "World/Tile.hpp"

const int CHUNK_WIDTH = 32;
const int CHUNK_HEIGHT = 32;

class Chunk {
    public:
        Chunk(TileSet *tileset);
        void updateTexture(TileSet *tileset);

        void setTile(int x, int y, Tile *tile);

        void drawChunk(sf::RenderTarget &target, sf::Vector2f pos);
    private:
        sf::RenderTexture render_texture;
        sf::Sprite sprite;

        Tile *chunk_data[CHUNK_WIDTH][CHUNK_HEIGHT];
};