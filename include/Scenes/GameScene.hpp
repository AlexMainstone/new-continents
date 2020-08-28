#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"

#include "World/MapGenerator.hpp"

#include "Entities/Player.hpp"

#include "Interface/GameInterface.hpp"

class GameScene {
    public:
        GameScene(sf::RenderWindow &window);

        void handleEvent(sf::Event e);
        void update(float dt);
        void render();

    private:
        sf::RenderWindow &window;

        int cursor_tile;
        sf::Vector2f cursor_pos;
        bool dragging;
        sf::Vector2f drag_pos;
        sf::Vector2i cam_move;

        bool selected;
        sf::Vector2f select_pos;

        TileSet *tileset;
        Map *map;

        sf::View world_view;
        sf::View ui_view;

        std::vector<Entity *> entity_vec;

        GameInterface *interface;
};