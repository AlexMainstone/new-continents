#pragma once

#include "Tasks/Task.hpp"

class DestroyTask : public Task {
    public:
        DestroyTask(Object *o);
        void act();
    private:
};