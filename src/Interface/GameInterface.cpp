#include "Interface/GameInterface.hpp"

GameInterface::GameInterface() {
}

void GameInterface::update(float dt) {

}

bool GameInterface::handleEvent(sf::Event e) {
    actionmenu.handleEvent(e);
    buildmenu.handleEvent(e);
    return false;
}

void GameInterface::draw(sf::RenderTarget &target, TileSet *tileset, sf::RenderStates states) {
    actionmenu.draw(target, tileset);
    buildmenu.draw(target, tileset);
}