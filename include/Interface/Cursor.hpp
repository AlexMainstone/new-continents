#pragma once

#include <SFML/Graphics.hpp>
#include "Resources/TileSet.hpp"
#include "Interface/IconButton.hpp"
#include "Managers/TaskManager.hpp"
#include "Objects/Object.hpp"
#include "Tasks/DestroyTask.hpp"

class Cursor {
    public:
        Cursor();
        void setPosition(sf::Vector2f pos);
        void setSelected(bool selected);
        void setObject(Object *o);
        void handleEvent(sf::Event e, TaskManager *taskmanager);

        void drawCursor(sf::RenderTarget &target, TileSet *tileset);
        void drawButtons(sf::RenderTarget &target, TileSet *tileset);
    private:
        bool selected;
        Object *select_obj;
        sf::Vector2f select_pos;

        IconButton *destroy_button;
};