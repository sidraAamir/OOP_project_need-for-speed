#include <SDL.h>
#pragma once
#include "drawing.hpp"
#include<vector>
#include<list>

class clouds1 {
    //friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    int frame = 0 ;
    void draw();
    void move();
    clouds1();
    clouds1(int, int);
}; 