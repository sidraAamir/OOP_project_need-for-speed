#include "canon.hpp"

void Canon::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::attack, &srcRect, &moverRect);
}


Canon::Canon(std::string direction){
    // for assigning positions randomly
    int x = rand() % 3;
    // assigning positions depending on the direction of movement
    srcRect = {0, 0, 24, 24};
    if(direction == "northeast"){
        switch (x)
        {
        case 0:
            moverRect = {10, 650, 24, 24};
            break;
        
        case 1:
            moverRect = {110, 650, 24, 24};
            break;

        case 2:
            moverRect = {210, 650, 24, 24};
            break;

        default:
            break;
        }
    }
    else if(direction == "northwest"){
        switch (x)
        {
        case 0:
            moverRect = {1100, 650, 24, 24};
            break;
        
        case 1:
            moverRect = {1000, 650, 24, 24};
            break;

        case 2:
            moverRect = {900, 650, 24, 24};
            break;

        default:
            break;
        }
    }
    else{
        switch (x)
        {
        case 0:
            moverRect = {700, 650, 24, 24};
            break;
        
        case 1:
            moverRect = {500, 650, 24, 24};
            break;

        case 2:
            moverRect = {450, 650, 24, 24};
            break;
            
        default:
            break;
        }
        
    }
}