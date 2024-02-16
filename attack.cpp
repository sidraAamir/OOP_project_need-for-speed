#include "attack.hpp"

void Attack::move_NorthEast(){
    moverRect.x += 10;
    moverRect.y -= 10;
}

void Attack::move_NorthWest(){
    moverRect.x -= 10;
    moverRect.y -= 10;
}

void Attack::move_up(){
    moverRect.y -= 10;
}

void Attack::move_right(){
    moverRect.x += 10;
}

int Attack::getX(){
    return moverRect.x;
}

int Attack::getY(){
    return moverRect.y;
}

SDL_Rect Attack::getRect(){
    return moverRect;
}