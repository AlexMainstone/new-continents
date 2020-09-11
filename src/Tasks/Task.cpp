#include "Tasks/Task.hpp"

Task::Task(Object *o) {
    object = o;
}

Object *Task::getObject() {
    return object;
}

void Task::act() {}