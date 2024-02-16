#include "score.hpp"

Score::Score()
{
   score = 0; 
}

int Score::getScore()
{
    return score;
}

void Score:: operator++(int i){
    score++;
}
void Score::score_reset(){
	score=0;
}

void Score::showScore(){
    TTF_Init();
	TTF_Font* font = TTF_OpenFont("Futura Bold font.ttf",20);
    SDL_Color  colour = { 255, 255, 255, 0};
	string top = "Score: " +to_string(getScore());
	SDL_Surface *surface_message = TTF_RenderText_Solid(font,top.c_str(),colour);
	SDL_Texture *message = SDL_CreateTextureFromSurface(Drawing::gRenderer,surface_message);
	SDL_Rect message_rect = {20,20,100,50};
	SDL_RenderCopy(Drawing::gRenderer,message,NULL,&message_rect);	
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
	TTF_CloseFont(font);
	TTF_Quit();
}