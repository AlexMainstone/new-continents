#include "Entities/Worker.hpp"

#include <iostream>
Worker::Worker(sf::Vector2f pos, Map *map, TaskManager *taskmanager) : Entity(pos, 25, sf::Color(255, 100, 255)) {
    this->map = map;
    this->taskmanager = taskmanager;
    currentTask = nullptr;
}

void Worker::update(float dt) {
    Entity::update(dt);

    if(currentTask == nullptr) {
        currentTask = taskmanager->getTask();
    } else if (!Entity::isMoving()) {
        sf::Vector2i taskpos = currentTask->getObject()->getPos();
        Entity::moveTo(taskpos.x-1, taskpos.y, map);
    } 
}

void Worker::draw(sf::RenderTarget &target, TileSet *tileset) {
    Entity::draw(target, tileset);
}