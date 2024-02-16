// code from homework 4
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include <time.h>
#include "spaceship.hpp"
#include "cloudmanager.hpp"
#include "diamond_manager.hpp"
#include "attackManager.hpp"
#include "score.hpp"

#pragma once

// SINGLETON CLASS

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 700;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    // to keep track of the score on the screen
    Score score;

    // ctor
    Game();

    // dtor to destroy all dynamically allocated memory
    ~Game();

    // singleton implementation
    static Game* Instance;

    // to maintain the health and lives
    int x=0;
    Performance Health;
    
public:
    // for selecting the page that needs to be diplayed
    int state = 0;

    // initializes the renderer
    bool init();

    // loads the start page
    bool loadMenu();

    // loads the level one of the game
    bool loadMedia();

    // loads the rules page of the game 
    bool loadRules();

    // loads the level two of the game
    bool loadLevelTwo();

    // closes everything; sets the pointers to nullptr
    void close();

    // loads all the textures; sets the path
    SDL_Texture* loadTexture( std::string path );

    // returns the dynamically created pointer of this class
    static Game* getPointer();

    // main work happens here
    void run();
    
    // displays the score
    void showScore();
};

