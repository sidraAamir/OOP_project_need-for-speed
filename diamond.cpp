#include "diamond.hpp"



diamond::diamond(int x, int y){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1,1,711,517};
    moverRect = {x,y,50,50};
}

diamond::diamond(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect =  {500,450,100,100};
    srcRect = {1,1,711,517};
}


void diamond::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::diamond, &srcRect, &moverRect);  //makes the object
}

void diamond::move(){
    moverRect.x -=10;
} 

int diamond::getX(){
    return moverRect.x;
}

int diamond::getY(){
    return moverRect.y;
}