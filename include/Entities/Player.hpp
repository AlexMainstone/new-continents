#pragma once

#include "Entities/Entity.hpp"

class Player : public Entity {
    public:
        Player(sf::Vector2f pos);

        void update(float dt);
        void draw(sf::RenderTarget &target, TileSet *tileset);

        void move(int x, int y);
    private:
};