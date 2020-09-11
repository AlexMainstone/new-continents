#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"
#include "World/Chunk.hpp"

class Map : public sf::Drawable {
    public:
        Map(int width, int height, TileSet *tileset);

        void setTile(int x, int y, Tile *tile, bool update = true);
        Tile *getTile(int x, int y);
        void updateChunks();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        void addObject(Object *object);
        sf::Vector2i tileToChunkPos(int x, int y);

        Object *getObject(int x, int y);
    private:
        TileSet *tileset;
        int map_width, map_height;

        sf::Vector2f chunk_pixels;
        std::vector<std::vector<Chunk *>> map_data;
};