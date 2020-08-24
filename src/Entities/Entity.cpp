#include "Entities/Entity.hpp"

Entity::Entity(sf::Vector2f pos, int tile, sf::Color color) {
    this->pos = pos;
    this->tile = tile;
    this->color = color;
}

#include<iostream>
void Entity::update(float dt) {
    // skip if no move
    if(move_queue.size() == 0) {
        return;
    }

    sf::Vector2i move = move_queue.front();

    if(move.x != 0) {
        move_progress.x += 2 * dt;
    }

    if(move.y != 0) {
        move_progress.y += 2 * dt;
    }

    if(move_progress.x >= 1 || move_progress.y >= 1) {
        move_progress.x = 0;
        move_progress.y = 0;
        pos.x += move.x;
        pos.y += move.y;
        move_queue.pop();
    }
}

void Entity::move(int x, int y) {
    move(sf::Vector2i(x, y));
}

void Entity::move(sf::Vector2i movedir) {
    move_queue.push(movedir);
}

void Entity::draw(sf::RenderTarget &target, TileSet *tileset) {
    sf::Vector2f final_pos = sf::Vector2f(move_progress.x * move_queue.front().x, move_progress.y * move_queue.front().y) + pos;
    tileset->drawSprite(target, sf::Vector2f(final_pos.x * tileset->getTileSize(), final_pos.y * tileset->getTileSize()), 25, color);
}