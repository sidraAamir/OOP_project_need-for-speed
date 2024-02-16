#include "attack.hpp"
#pragma once
class Canon : public Attack{
    public:
        // constructor
        Canon(std::string);

        // runtime polymorphism
        void draw();
};