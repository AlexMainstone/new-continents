#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "World/Tile.hpp"

class TileSet {
    public:
        TileSet(const char *path, int tilesize);
        void drawSprite(sf::RenderTarget &target, sf::Vector2f pos, int tile, sf::Color color = sf::Color::White, float scale = 1);

        int getTileSize();

        Tile *getTile(int t);
        void addTile(Tile *tile);
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect sprite_rect;

        int tile_size;
        int set_size;

        std::vector<Tile *> tile_data;
};