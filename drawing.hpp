#include<SDL.h>
#pragma once
class Drawing{
    public:
    //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;
    static SDL_Texture* attack;
    static SDL_Texture* clouds;
    static SDL_Texture* diamond;
    static SDL_Texture* laser;
};
//assets