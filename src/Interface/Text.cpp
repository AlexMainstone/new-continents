#include "Interface/Text.hpp"

Text::Text(const char *text, sf::Vector2f pos, sf::Color color, float scale) {
    this->text = text;
    this->pos = pos;
    this->color = color;
    this->scale = scale;
}

int Text::charToTile(char c) {
    if(c == 32) { return 0; }
    int out = c + 799;
    while(out % 48 < 35) { out += 35; }
    return out;
}

void Text::setColor(sf::Color color) {
    this->color = color;
}

int Text::getSize() {
    return (text.size()*16) * scale;
}

#include<iostream>
void Text::draw(sf::RenderTarget &target, TileSet *tileset) {
    for(int i = 0; i < text.size(); i++) {
        tileset->drawSprite(target, sf::Vector2f((i*(tileset->getTileSize()-6)*scale), 0) + pos, charToTile(text.at(i)), color, scale);
    }
}