#pragma once

#include "Entities/Entity.hpp"
#include "Tasks/Task.hpp"
#include "Managers/TaskManager.hpp"

class Worker : public Entity {
    public:
        Worker(sf::Vector2f pos, Map *map, TaskManager *task);

        void update(float dt);
        void draw(sf::RenderTarget &target, TileSet *tileset);

        void move(int x, int y);
    private:
        Task *currentTask;
        TaskManager *taskmanager;

        Map *map;
};