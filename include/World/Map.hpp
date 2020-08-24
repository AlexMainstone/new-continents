#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"
#include "World/Chunk.hpp"

class Map : public sf::Drawable {
    public:
        Map(int width, int height, TileSet *tileset);

        void setTile(int x, int y, Tile *tile, bool update = true);
        void updateChunks();

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    private:
        TileSet *tileset;
        int map_width, map_height;

        sf::Vector2f chunk_pixels;
        std::vector<std::vector<Chunk *>> map_data;
};