#pragma once

#include <vector>
#include "Tasks/Task.hpp"
#include "Resources/TileSet.hpp"

class TaskManager {
    public:
        TaskManager();
        void addTask(Task *task);
        Task *getTask();

        void drawTasks(sf::RenderTarget &target, TileSet *tileset);
    private:
        std::vector<Task *> task_vec;
};