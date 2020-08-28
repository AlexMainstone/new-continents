#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/TileSet.hpp"
#include "Interface/IconButton.hpp"

#include "Interface/BuildMenu.hpp"
#include "Interface/ActionMenu.hpp"

class GameInterface {
    public:
        GameInterface();
        void update(float dt);
        bool handleEvent(sf::Event e);
        void draw(sf::RenderTarget &target, TileSet *tileset, sf::RenderStates states = sf::RenderStates::Default);
    private:
        BuildMenu buildmenu;
        ActionMenu actionmenu;
};