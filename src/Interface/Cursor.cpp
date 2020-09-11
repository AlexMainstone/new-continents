#include "Interface/Cursor.hpp"
Cursor::Cursor() {
    selected = false;
    destroy_button = new IconButton(sf::Vector2f(8,720-(16*4) - 8), 283, 16, 4.0);
}

void Cursor::setPosition(sf::Vector2f pos) {
    this->select_pos = pos;
}

void Cursor::setSelected(bool selected) {
    this->selected = selected;
}

void Cursor::setObject(Object *o) {
    select_obj = o;
}

void Cursor::handleEvent(sf::Event e, TaskManager *taskmanager) {
    if(!selected) {
        return;
    }

    destroy_button->handleEvent(e);
    if(destroy_button->isPressed()) {
        taskmanager->addTask(new DestroyTask(select_obj));
    }
}

void Cursor::drawCursor(sf::RenderTarget &target, TileSet *tileset) {
    if(!selected) {
        return;
    }
    tileset->drawSprite(target, select_pos, 612, sf::Color(255, 0, 0, 150));
}

void Cursor::drawButtons(sf::RenderTarget &target, TileSet *tileset) {
    if(!selected) {
        return;
    }
    destroy_button->draw(target, tileset);
}