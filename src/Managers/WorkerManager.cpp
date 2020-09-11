#include "Managers/WorkerManager.hpp"

WorkerManager::WorkerManager(TaskManager *taskmanager, Map *map) {
    worker_vec.push_back(new Worker(sf::Vector2f(5, 5), map, taskmanager));
}

void WorkerManager::update(float dt) {
    for(auto *w : worker_vec) {
        w->update(dt);
    }
}

void WorkerManager::render(sf::RenderTarget &target, TileSet *tileset) {
    for(auto w : worker_vec) {
        w->draw(target, tileset);
    }
}