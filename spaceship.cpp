#include "spaceship.hpp"

spaceship::spaceship(){
    srcRect = {12, 18, 71, 70};
    moverRect = {550, 350, 71, 70};
}

void spaceship::adjust(){
    srcRect = {12, 18, 71, 70};
}

void spaceship::moveup(){
    if(!(moverRect.y <= 0)){
        moverRect.y -= 10;
        if ((srcRect.x == 12 && srcRect.y == 18) || (srcRect.x == 12 && srcRect.y == 114) || (srcRect.x == 24 && srcRect.y == 319))
        {
            srcRect = {108, 123, 71, 70};

        }
    }
}
void spaceship::move_down(){
    if(!(moverRect.y >= 625)){
        moverRect.y += 5;
        if ((srcRect.x == 12 && srcRect.y == 18) || (srcRect.x == 108 && srcRect.y == 123) || (srcRect.x == 24 && srcRect.y == 319))
        {
            srcRect = {12, 114, 69, 82};
        }
    }
}

void spaceship::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void spaceship::changeship(SDL_Rect sr = {12, 18, 71, 70}){ // to change the ship to show movement
    srcRect = sr;
}

void spaceship::showAttack(int Health){    
    if(Health == 0){
        srcRect = {418, 319, 63, 63};
        cout << "health completely destroyed" << endl;
    }
    else{
        cout << "sprite change" << endl;
        srcRect = {24, 319, 57, 62};
    }
}

int spaceship::getX(){
    return moverRect.x;
}

int spaceship::getY(){
    return moverRect.y;
}   

SDL_Rect spaceship::getRect(){
    return moverRect;
}