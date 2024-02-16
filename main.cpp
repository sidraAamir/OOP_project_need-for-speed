/*
This is our game's main file. 
*/
#include "game.hpp"

// FROM CS/CE 224/272 HOMEWORK 4
int main(int argc, char *argv[]){
    // Get the pointer
    Game* game = Game::getPointer();

    srand(time(NULL));
    if( !game->init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
    // start with menu
    if( !game->loadMenu() ){
        printf( "Failed to load media!\n" );
        return 0;
    }   
    game->run();
    game->close();

    return 0;
}