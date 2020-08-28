#include "Interface/Button.hpp"

Button::Button(sf::FloatRect rect) {
    this->rect = rect;
    hover = pressed = false;
}

bool Button::isPressed() {
    return pressed;
}

bool Button::isHovered() {
    return hover;
}

bool Button::handleEvent(sf::Event e) {
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

void Button::draw(sf::RenderTarget &target, TileSet *tileset) {
    sf::RectangleShape shape;
    shape.setPosition(rect.left, rect.top);
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color(207, 198, 184));

    if(hover) {
        shape.setFillColor(sf::Color(207, 198, 184));
        target.draw(shape);
    } else {
        shape.setFillColor(sf::Color::Black);
        target.draw(shape);
    }

}