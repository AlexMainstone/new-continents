#include "Interface/ActionMenu.hpp"

ActionMenu::ActionMenu() : actionbutton(sf::Vector2f(32, 0), 282, 16, 2.0) {

}

bool ActionMenu::handleEvent(sf::Event e) {
    actionbutton.handleEvent(e);
}

void ActionMenu::draw(sf::RenderTarget &target, TileSet *tileset) {
    actionbutton.draw(target, tileset);
}