#include "Interface/BuildMenu.hpp"

BuildMenu::BuildMenu() {
    wordbutton = new WordButton(sf::Vector2f(0, 31), "STRUCTURE", 16, 1.25);
    buildbutton = new IconButton(sf::Vector2f(0, 0), 373, 16, 2);
    vec_hover = false;

    for(int x = 0; x < 6; x++) {
        for(int y = 0; y < 6; y++) {
            button_vec.push_back(IconButton(sf::Vector2f(113 + (32 * x), 31 + (32 * y)), 6 * y + x, 16, 2));
        }
    }
}

bool BuildMenu::handleEvent(sf::Event e) {
    buildbutton->handleEvent(e);

    vec_hover = false;
    for(auto b : button_vec) {
        if(b.isHovered()) {
            vec_hover = true;
            break;
        }
    }

    if(buildbutton->isHovered() | wordbutton->isHovered() | vec_hover) {
        wordbutton->handleEvent(e);
        for(int i = 0; i < button_vec.size(); i++) {
            button_vec[i].handleEvent(e);
        }
    }
    return false;
}

void BuildMenu::draw(sf::RenderTarget &target, TileSet *tileset) {
    buildbutton->draw(target, tileset);

    if(buildbutton->isHovered() | wordbutton->isHovered() | vec_hover) {
        wordbutton->draw(target, tileset);
        if(wordbutton->isHovered() | vec_hover) {
            for(auto b : button_vec) {
                b.draw(target, tileset);
            }
        }
    }
}