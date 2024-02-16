#include <SDL.h>
#include <iostream>
#include "drawing.hpp"
#pragma once
class Attack{
    public:
        // SDL Rects for animations
        SDL_Rect srcRect;
        SDL_Rect moverRect;
        int health_dec;

        // draw() works differently for both weapons
        virtual void draw() = 0;

        // for canon's movement
        void move_NorthEast();
        void move_NorthWest();
        
        // for laser's movement
        void move_up();
        void move_right();

        // returns the x coordinate of the attack
        int getX();

        // returns the y coordinate of the attack 
        int getY(); 

        // returns the sdl rect of the attack
        SDL_Rect getRect();
        
};