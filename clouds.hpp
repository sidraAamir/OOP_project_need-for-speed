#include <SDL.h>
#include "drawing.hpp"
#pragma once

class clouds {
    //friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    int frame = 0 ;
    void draw();
    void move();
    clouds();
    clouds(int, int);
}; 