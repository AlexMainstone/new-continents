#include "Entities/Player.hpp"


Player::Player(sf::Vector2f pos) : Entity(pos, 25, sf::Color(255, 100, 255)) {
    Entity::move(1, 1);
}

void Player::update(float dt) {
    Entity::update(dt);
}

void Player::draw(sf::RenderTarget &target, TileSet *tileset) {
    Entity::draw(target, tileset);
}