#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"
#include "World/Tile.hpp"
#include "Objects/Object.hpp"

const int CHUNK_WIDTH = 16;
const int CHUNK_HEIGHT = 16;

class Chunk {
    public:
        Chunk(TileSet *tileset);
        void updateTexture(TileSet *tileset);

        void setTile(int x, int y, Tile *tile);
        Tile *getTile(int x, int y);

        void drawChunk(sf::RenderTarget &target, TileSet *tileset, sf::Vector2f pos);

        void addObject(Object *obj);
        Object *getObject(int x, int y);
    private:
        sf::RenderTexture render_texture;
        sf::Sprite sprite;

        Tile *chunk_data[CHUNK_WIDTH][CHUNK_HEIGHT];

        std::vector<Object*> object_list;
};