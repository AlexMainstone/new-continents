#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Resources/TileSet.hpp"

#include "World/MapGenerator.hpp"

#include "Managers/TaskManager.hpp"
#include "Managers/WorkerManager.hpp"

#include "Interface/GameInterface.hpp"
#include "Interface/Cursor.hpp"

#include "Maths/Pathfinding.hpp"
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

        // TODO camera class
        bool dragging;
        sf::Vector2f drag_pos;
        sf::Vector2i cam_move;

        TaskManager *taskmanager;
        WorkerManager *workermanager;
        Cursor *cursor;

        TileSet *tileset;
        Map *map;

        sf::View world_view;
        sf::View ui_view;

        GameInterface *interface;
};