#pragma once

#include "Objects/Object.hpp"
class Task {
    public:
        Task(Object *o);

        Object *getObject();

        virtual void act();
    private:
        Object *object;

};