#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Managers/TaskManager.hpp"

#include "Entities/Worker.hpp"

#include "Resources/TileSet.hpp"


class WorkerManager {
    public:
        WorkerManager(TaskManager *taskmanager, Map *map);

        void update(float dt);
        void render(sf::RenderTarget &target, TileSet *tileset);
    private:
        std::vector<Worker *> worker_vec;
};