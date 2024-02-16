#include <SDL.h>
#include <iostream>
#include "drawing.hpp"
#pragma once

class diamond {
    //friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    void draw();
    void move();
    diamond();
    diamond(int, int);
    int getX();
    int getY();
}; 