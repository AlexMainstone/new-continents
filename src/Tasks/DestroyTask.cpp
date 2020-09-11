#include "Tasks/DestroyTask.hpp"

DestroyTask::DestroyTask(Object *o) : Task(o) {}

void DestroyTask::act() {
    delete Task::getObject();
}