#include "Scenes/GameScene.hpp"

GameScene::GameScene(sf::RenderWindow &window) : window(window) {
    tileset = new TileSet("../res/tileset.png", 16);
    MapGenerator gen;
    map = gen.generate(tileset);
    
    world_view = ui_view = window.getView();

    cursor_tile = 518;

    window.setMouseCursorVisible(false);
    world_view.zoom(0.5);
    dragging = false;

    entity_vec.push_back(new Player(sf::Vector2f(1, 1)));
}

void GameScene::handleEvent(sf::Event e) {
    if(e.type == sf::Event::MouseMoved) {
        cursor_pos.x = e.mouseMove.x;
        cursor_pos.y = e.mouseMove.y;
        
        if(dragging) {
            sf::Vector2f world_cursor = window.mapPixelToCoords(sf::Vector2i(cursor_pos.x, cursor_pos.y), world_view);
            world_view.setCenter(world_view.getCenter() + (drag_pos - world_cursor));
        }
    } else if(e.type == sf::Event::MouseButtonPressed) {
        dragging = true;
        drag_pos = window.mapPixelToCoords(sf::Vector2i(e.mouseButton.x, e.mouseButton.y), world_view);
        cursor_tile = 48* 21 + 19;
    } else if(e.type == sf::Event::MouseButtonReleased) {
        dragging = false;
        cursor_tile = 518;
    } else if(e.type == sf::Event::MouseWheelScrolled) {
        world_view.zoom(1 + (0.1 * e.mouseWheelScroll.delta));
    }
}

void GameScene::update(float dt) {
    for(int i = 0; i < entity_vec.size(); i++) {
        entity_vec[i]->update(dt);
    }
}

void GameScene::render() {
    // World View
    window.setView(world_view);
    window.draw(*map);

    for(int i = 0; i < entity_vec.size(); i++) {
        entity_vec[i]->draw(window, tileset);
    }

    // UI view
    window.setView(ui_view);
    tileset->drawSprite(window, cursor_pos, cursor_tile, sf::Color::White, 1.5);

}