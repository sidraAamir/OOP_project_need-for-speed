#include "performance.hpp"

Performance::Performance(){
    // constructor, we dont need inputs because initial values are fixed.
    health = 100;
    lives = 2;
}


int Performance::getlives(){
    return lives;
}
void Performance::displayLife(){
    TTF_Init();
	TTF_Font* font = TTF_OpenFont("Futura Bold font.ttf",20);
    SDL_Color  colour = { 255, 255, 255, 0};
	string top = "Lives Left: " +to_string(getlives());
	SDL_Surface *surface_message = TTF_RenderText_Solid(font,top.c_str(),colour);
	SDL_Texture *message = SDL_CreateTextureFromSurface(Drawing::gRenderer,surface_message);
	SDL_Rect message_rect = {1050,20,100,50};
	SDL_RenderCopy(Drawing::gRenderer,message,NULL,&message_rect);	
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
	TTF_CloseFont(font);
	TTF_Quit();
}

void Performance::displayHealth(){
    TTF_Init();
	TTF_Font* font = TTF_OpenFont("Futura Bold font.ttf",20);
    SDL_Color  colour = { 255, 255, 255, 0};
	string top = "Health: " + to_string(health);
	SDL_Surface *surface_message = TTF_RenderText_Solid(font,top.c_str(),colour);
	SDL_Texture *message = SDL_CreateTextureFromSurface(Drawing::gRenderer,surface_message);
	SDL_Rect message_rect = {1050,600,100,50};
	SDL_RenderCopy(Drawing::gRenderer,message,NULL,&message_rect);	
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
	TTF_CloseFont(font);
	TTF_Quit();
}

void Performance::BothAttack(){
    cout<< "attack on spaceship"<<endl;
    health -= 20; 
    cout<< "health left"<<health<<endl;    }

void Performance::life_check(){
    if (lives==2 && health==0) {
        health=100;
        lives=1;
        cout<< "lives left"<<lives<<endl; 
    }
    else if(lives==1 && health==0){
        lives=0;
        cout<< "lives finish"<<lives<<endl; 
      
    }  
}