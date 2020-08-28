#include "Interface/WordButton.hpp"


WordButton::WordButton(sf::Vector2f pos, std::string word, int tilesize, float scale) : text(word.c_str(), sf::Vector2f(pos.x - 4, pos.y), sf::Color::White, scale), Button(sf::FloatRect(pos.x, pos.y, word.size() * 10 * scale, tilesize * scale)) {
}

bool WordButton::isPressed() {
    return Button::isPressed();
}

bool WordButton::isHovered() {
    return Button::isHovered();
}

bool WordButton::handleEvent(sf::Event e) {
    return Button::handleEvent(e);
}

void WordButton::draw(sf::RenderTarget &target, TileSet *tileset) {
    Button::draw(target, tileset);

    if(Button::isHovered()) {
        text.setColor(sf::Color::Black);
    } else {
        text.setColor(sf::Color::White);
    }

    text.draw(target, tileset);
}