#include "clouds.hpp"
#include <iostream>
#pragma once

clouds::clouds(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {593, 35, 148,120 };
     // setting pigeon x and y values
    moverRect = {1200,150,100,100};
}

clouds::clouds(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect =  {1200,150,100,100};
     // setting pigeon x and y values
    srcRect = {593, 35, 148,120 };
}


void clouds::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::clouds, &srcRect, &moverRect);  //makes the object
   
}

void clouds::move(){

    moverRect.x -=10;
} 
