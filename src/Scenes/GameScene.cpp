#include "Scenes/GameScene.hpp"

#include<iostream>
GameScene::GameScene(sf::RenderWindow &window) : window(window) {
    tileset = new TileSet("../res/tilesets/tileset.png", 16);
    MapGenerator gen;
    // map = gen.generate(tileset);
    map = gen.generate_from_py(tileset);
    cursor = new Cursor();
    
    taskmanager = new TaskManager();
    workermanager = new WorkerManager(taskmanager, map);

    world_view = ui_view = window.getView();

    cursor_tile = 518;

    window.setMouseCursorVisible(false);
    world_view.zoom(0.5);
    dragging = false;

    interface = new GameInterface();

}

void GameScene::handleEvent(sf::Event e) {
    if(interface->handleEvent(e)) {
        return;
    }

    if(e.type == sf::Event::MouseMoved) {
        cursor_pos.x = e.mouseMove.x;
        cursor_pos.y = e.mouseMove.y;
        if(dragging) {
            sf::Vector2f world_cursor = window.mapPixelToCoords(sf::Vector2i(cursor_pos.x, cursor_pos.y), world_view);
            world_view.setCenter(world_view.getCenter() + (drag_pos - world_cursor));
        }
    } else if(e.type == sf::Event::MouseButtonPressed) {
        if(e.mouseButton.button == sf::Mouse::Middle) {
            dragging = true;
            drag_pos = window.mapPixelToCoords(sf::Vector2i(e.mouseButton.x, e.mouseButton.y), world_view);
            cursor_tile = 48* 21 + 19;
        }
    } else if(e.type == sf::Event::MouseButtonReleased) {
        if(e.mouseButton.button == sf::Mouse::Middle) {
            dragging = false;
            cursor_tile = 518;
        } else if(e.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f select_pos = window.mapPixelToCoords(sf::Vector2i(e.mouseButton.x, e.mouseButton.y), world_view);
            select_pos.x = ((int)select_pos.x / 16);
            select_pos.y = ((int)select_pos.y / 16);
            Object *o = map->getObject(select_pos.x, select_pos.y);
            cursor->setObject(o);
            select_pos.x *= 16;
            select_pos.y *= 16;
            cursor->setPosition(select_pos);
            if(o == nullptr) {
                cursor->setSelected(false);
            } else {
                cursor->setSelected(true);
            }
        }
    } else if(e.type == sf::Event::MouseWheelScrolled) {
        world_view.zoom(1 + (0.1 * e.mouseWheelScroll.delta));
    } else if(e.type == sf::Event::KeyPressed) {
        if(e.key.code == sf::Keyboard::W) {
            cam_move.y = -1;
        } else if(e.key.code == sf::Keyboard::S) {
            cam_move.y = 1;
        }

        if(e.key.code == sf::Keyboard::A) {
            cam_move.x = -1;
        } else if(e.key.code == sf::Keyboard::D) {
            cam_move.x = 1;
        }
    } else if(e.type == sf::Event::KeyReleased) {
        if(e.key.code == sf::Keyboard::S | e.key.code == sf::Keyboard::W) {
            cam_move.y = 0;
        }
        if(e.key.code == sf::Keyboard::A | e.key.code == sf::Keyboard::D) {
            cam_move.x = 0;
        }
    }
    cursor->handleEvent(e, taskmanager);
}

void GameScene::update(float dt) {
    world_view.move(sf::Vector2f((cam_move.x * 100) * dt, (cam_move.y * 100) * dt));
    workermanager->update(dt);
}

void GameScene::render() {
    // World View
    window.setView(world_view);
    window.draw(*map);
    workermanager->render(window, tileset);
    taskmanager->drawTasks(window, tileset);

    cursor->drawCursor(window, tileset);


    // UI view
    window.setView(ui_view);
    interface->draw(window, tileset);
    cursor->drawButtons(window, tileset);
    tileset->drawSprite(window, cursor_pos, cursor_tile, sf::Color::White, 1.5);
}