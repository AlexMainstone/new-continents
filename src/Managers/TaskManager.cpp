#include "Managers/TaskManager.hpp"

TaskManager::TaskManager() {

}

void TaskManager::addTask(Task *task) {
    task_vec.push_back(task);
}

#include<iostream>
Task *TaskManager::getTask() {
    if(task_vec.empty()) {
        return nullptr;
    }

    Task *t = task_vec.back();
    task_vec.pop_back();
    return t;
}

void TaskManager::drawTasks(sf::RenderTarget &target, TileSet *tileset) {
    for(auto t : task_vec) {
        sf::Vector2i pos = t->getObject()->getPos();
        tileset->drawSprite(target, sf::Vector2f(pos.x * 16, pos.y * 16), 48*11 + 24, sf::Color::Red);
    }
}
