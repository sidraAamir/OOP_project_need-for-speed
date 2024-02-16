#include "laser.hpp"

void Laser::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::laser, &srcRect, &moverRect);
}

Laser::Laser(){
    // for assigning positions randomly depending on the screen size
    int y = rand() % 700;

    // for selecting random laser beams
    int select = rand() % 46;

    // for each sprite's exact details
    int w, h;

    // selecting the sprite
    switch(select){
        case 0:
            srcRect = {300, 296, 120, 71};
            w = 120; h = 71;
            break;

        case 1:
            srcRect = {357, 236, 83, 49};
            w = 83; h = 49;
            break;

        case 2:
            srcRect = {425, 200, 21, 21};
            w = h = 21;
            break;

        case 3:
            srcRect = {414, 168, 26, 20};
            w = 26; h = 20;
            break;

        case 4:
            srcRect = {386, 170, 21, 17};
            w = 21; h = 17;
            break;

        case 5:
            srcRect = {396, 202, 24, 18};
            w = 24; h = 18;
            break;

        case 6:
            srcRect = {359, 203, 33, 17};
            w = 33; h = 17;
            break;

        case 7:
            srcRect = {352, 167, 26, 22};
            w = 26; h = 22;
            break;

        case 8:
            srcRect = {253, 232, 97, 56};
            w = 97; h = 56;
            break;

        case 9:
            srcRect = {318, 202, 21, 21};
            w = h = 21;
            break;

        case 10:
            srcRect = {307, 170, 26, 20};
            h = 20; w = 26;
            break;

        case 11:
            srcRect = {279, 172, 21, 17};
            h = 17; w = 21;
            break;

        case 12:
            srcRect = {289, 204, 24, 18};
            h = 18; w = 24;
            break;

        case 13:
            srcRect = {252, 205, 33, 17};
            h = 17; w = 33;
            break;

        case 14:
            srcRect = {245, 169, 26, 22};
            h = 22; w = 26;
            break;

        case 15:
            srcRect = {151, 227, 85, 48};
            h = 48; w = 85;
            break;

        case 16:
            srcRect = {35, 203, 111, 62};
            h = 62; w = 111;
            break;

        case 17:
            srcRect = {146, 162, 85, 47};
            h = 47; w = 85;
            break;

        case 18:
            srcRect = {40, 135, 97, 54};
            h = 54; w = 97;
            break;

        case 19:
            srcRect = {156, 117, 70, 41};
            h = 41; w = 70;
            break;

        case 20:
            srcRect = {67, 77, 70, 39};
            h = 39; w = 70;
            break;

        case 21:
            srcRect = {161, 0, 43, 33};
            h = 33; w = 43;
            break;

        case 22:
            srcRect = {238, 2, 26, 22};
            w = 26; h = 22;
            break;

        case 23:
            srcRect = {245, 38, 33, 17};
            h = 17; w = 33;
            break;

        case 24:
            srcRect = {272, 5, 21, 17};
            h = 17; w = 21;
            break;

        case 25:
            srcRect = {282, 37, 24, 18};
            h = 18; w = 24;
            break;

        case 26:
            srcRect = {300, 3, 26, 20};
            h = 20, w = 26;
            break;

        case 27:
            srcRect = {311, 35, 21, 21};
            w = h = 21;
            break;

        case 28:
            srcRect = {353, 3, 26, 22};
            w = 26; h = 22;
            break;

        case 29:
            srcRect = {360, 39, 33, 17};
            h = 17; w = 33;
            break;

        case 30:
            srcRect= {397, 38, 24, 18};
            h = 18; w = 24;
            break;

        case 31:
            srcRect = {387, 6, 21, 17};
            w = 21; h = 17;
            break;

        case 32:
            srcRect = {415, 4, 26, 20};
            h = 20; w = 26;
            break;

        case 33:
            srcRect = {426, 36, 20, 21};
            h = 21; w = 20;
            break;

        case 34:
            srcRect = {410, 83, 26, 20};
            h = 20; w = 26;
            break;

        case 35:
            srcRect = {421, 115, 21, 21};
            w = h = 21;
            break;

        case 36:
            srcRect = {392, 117, 24, 18};
            h = 18; w = 24;
            break;
        
        case 37:
            srcRect = {382, 85, 21, 17};
            h = 17; w = 21;
            break;

        case 38:
            srcRect = {348, 82, 26, 22};
            h = 22; w = 26;
            break;

        case 39:
            srcRect = {355, 118, 33, 17};
            h = 17; w = 33;
            break;

        case 40:
            srcRect = {305, 84, 20, 26};
            h = 20; w = 26;
            break;

        case 41:
            srcRect = {316, 116, 21, 21};
            w = h = 21;
            break;

        case 42:
            srcRect = {287, 118, 24, 18};
            h = 18; w = 24;
            break;

        case 43:
            srcRect = {277, 86, 21, 17};
            h = 17; w = 21;
            break;

        case 44:
            srcRect = {243, 83, 26, 22};
            h = 22; w = 26;
            break;

        case 45:
            srcRect = {250, 119, 33, 17};
            h = 17; w = 33;
            break;

        default:
            break;        
    }
    
    // assigning the width and height of the respective laser beam
    moverRect = {0, y, w, h}; 
}