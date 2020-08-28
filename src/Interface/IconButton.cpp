#include "Interface/IconButton.hpp"

IconButton::IconButton(sf::Vector2f pos, int tile, int tilesize, float scale) {
    this->tile = tile;
    rect = sf::FloatRect(pos, sf::Vector2f(tilesize * scale, tilesize * scale));
    this->scale = scale;

    hover = pressed = false;
}

bool IconButton::isHovered() {
    return hover;
}

bool IconButton::isPressed() {
    if(pressed) {
        pressed = false;
        return true;
    }
    return false;
}

bool IconButton::handleEvent(sf::Event e) {
    if(e.type == sf::Event::MouseMoved) {
        if(rect.contains(e.mouseMove.x, e.mouseMove.y)) {
            hover = true;
        } else {
            hover = false;
        }
    } else if(e.type == sf::Event::MouseButtonPressed) {
        if(e.mouseButton.button == sf::Mouse::Left && hover) {
            pressed = true;
            return true;
        }
    }
    return false;
}

void IconButton::draw(sf::RenderTarget &target, TileSet *tileset) {
    sf::RectangleShape shape;
    shape.setPosition(rect.left, rect.top);
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(207, 198, 184));

    if(hover) {
        shape.setFillColor(sf::Color(207, 198, 184));
        target.draw(shape);
        tileset->drawSprite(target, sf::Vector2f(rect.left, rect.top), tile, sf::Color::Black, scale);
    } else {
        shape.setFillColor(sf::Color::Black);
        target.draw(shape);
        tileset->drawSprite(target, sf::Vector2f(rect.left, rect.top), tile, sf::Color(207, 198, 184), scale);
    }
}