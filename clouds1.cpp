#include "clouds1.hpp"

#include <iostream>
//#include "game.hpp"

clouds1::clouds1(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = srcRect = {548,195,208,100};
     // setting pigeon x and y values
    moverRect = {1100,300,100,100};
}

clouds1::clouds1(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect =  {1100,300,100,100};
     // setting pigeon x and y values
    srcRect = {548,195,208,100};
}


void clouds1::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::clouds, &srcRect, &moverRect);  //makes the object
    /* tick++;
    if(tick>10){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::clouds, &srcRect, &moverRect);  //makes the object
    moverRect = {100,150,100,100};
    if (frame == 0){
        srcRect = {593, 35, 148,120 };
        SDL_RenderCopy(Drawing::gRenderer, Drawing::clouds, &srcRect, &moverRect);  //makes the object
        }
    if (frame==1){
        srcRect = {548,195,208,100};
        SDL_RenderCopy(Drawing::gRenderer, Drawing::clouds, &srcRect, &moverRect); } //makes the object
    if (frame==2){srcRect = {342,23,204,90};}
    frame++; 
    if (frame == 3){frame = 0;}
    tick=0;
    } */
}

void clouds1::move(){
    moverRect.x -= 13;
} 
