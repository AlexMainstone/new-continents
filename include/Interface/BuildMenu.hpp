#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"

#include "Interface/IconButton.hpp"
#include "Interface/WordButton.hpp"

class BuildMenu {
    public:
        BuildMenu();
        bool handleEvent(sf::Event e);
        void draw(sf::RenderTarget &target, TileSet *tileset);
    private:
        IconButton *buildbutton;
        WordButton *wordbutton;
        
        std::vector<IconButton> button_vec;
        bool vec_hover;
};