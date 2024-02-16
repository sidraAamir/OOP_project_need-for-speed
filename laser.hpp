#include "attack.hpp"
#pragma once
class Laser : public Attack{
    public:
        // constructor
        Laser();

        // runtime polymorphism
        void draw();
};