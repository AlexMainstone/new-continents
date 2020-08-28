#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/TileSet.hpp"
#include "Interface/IconButton.hpp"

class ActionMenu {
    public:
        ActionMenu();
        bool handleEvent(sf::Event e);
        void draw(sf::RenderTarget &target, TileSet *tileset);
    private:
        IconButton actionbutton;
};