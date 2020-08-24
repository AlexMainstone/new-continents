#include "Resources/TileSet.hpp"

TileSet::TileSet(const char *path, int tilesize) {
    tile_size = tilesize;

    texture.loadFromFile(path);

    set_size = texture.getSize().x / tile_size;

    sprite.setTexture(texture);

    sprite_rect = sf::IntRect(0, 0, tilesize, tilesize);

    addTile(new Tile(0, sf::Color::White, false));
    addTile(new Tile(5, sf::Color(56, 217, 115), false));
    addTile(new Tile(1, sf::Color(122, 68, 74), false));
    addTile(new Tile(48, sf::Color(50, 125, 50), true));
}

int TileSet::getTileSize() {
    return tile_size;
}

void TileSet::drawSprite(sf::RenderTarget &target, sf::Vector2f pos, int tile, sf::Color color, float scale) {
    sprite_rect.left = tile % set_size;
    sprite_rect.top = (tile - sprite_rect.left) / set_size;
    sprite_rect.left *= tile_size;
    sprite_rect.top *=  tile_size;

    sprite.setColor(color);
    sprite.setTextureRect(sprite_rect);
    sprite.setPosition(pos);
    sprite.setScale(scale, scale);
    target.draw(sprite);
}

Tile *TileSet::getTile(int t) {
    return tile_data[t];
}

void TileSet::addTile(Tile *tile) {
    tile_data.push_back(tile);
}