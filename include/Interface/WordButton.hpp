#pragma once

#include <string>
#include "Interface/Button.hpp"
#include "Interface/Text.hpp"

class WordButton : public Button {
    public:
        WordButton(sf::Vector2f pos, std::string word, int tilesize, float scale = 1.0);

        bool isPressed();
        bool isHovered();
        
        bool handleEvent(sf::Event e);

        void draw(sf::RenderTarget &target, TileSet *tileset);

    private:
        std::string stext;
        int tilesize;
        Text text;
};