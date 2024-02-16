#include<iostream>
using namespace std;
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "drawing.hpp"
#pragma once
class Performance{
    public:
        int health;
        int lives;
        Performance();
        // getter for health
        int getlives(); 
        //it decreases the health by 20, when ship is attacked
        void BothAttack(); 
        bool alive = true ;
        //keeps check on lives left
        void life_check();
        // displays life
        void displayLife();
        // displays health
        void displayHealth();
};