#include <SDL.h>
#include "performance.hpp"
#include "drawing.hpp"
#include <iostream>
using namespace std;
#pragma once

class spaceship{
    // attributes
    Performance health;
    SDL_Rect srcRect, moverRect; // for moving the ship
    
    public:
        // function members

        // constructor
        spaceship(); 

        // SDL rendering
        void draw(); 
        
        // to move the ship up
        void moveup(); 

        // to move the ship down
        void move_down();

        // to change the asset
        void changeship(SDL_Rect sr);

        //changes the asset to original ship
        void adjust();

        // returns the x coordinate of the ship
        int getX(); 

        // return the y coordinate of the ship
        int getY(); 

        // displays the attack sprite.
        void showAttack(int); 

        // returns the sdl rect
        SDL_Rect getRect();
};      