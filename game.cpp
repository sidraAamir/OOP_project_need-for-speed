/* 
This file contains all the function definitions for our SDL Class.
*/

#include "game.hpp"

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;
SDL_Texture *Drawing::attack = NULL;
SDL_Texture *Drawing::clouds = NULL;
SDL_Texture *Drawing::diamond = NULL;
SDL_Texture *Drawing::laser = NULL;

Game* Game::Instance = NULL;

Game::Game(){} // no need to write anything in the ctor.

Game::~Game(){
	delete Instance;
}

Game* Game::getPointer(){
	if(Instance == NULL){
		Instance = new Game();
	}
	return Instance;
}

bool Game::init()
{
	// Initialization flag
	bool success = true;
	TTF_Init();
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		
		// Create window
		gWindow = SDL_CreateWindow("NEED FOR SPEED", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool Game::loadMenu()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("assets/menu.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::loadRules()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("assets/rules.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	Drawing::assets = loadTexture("assets/shipsprite.png"); // for the ship to move
	Drawing::attack = loadTexture("assets/Gameassets/UI bomb.png"); // for the canon
	Drawing::clouds = loadTexture("assets/clouds.png"); // for the clouds
	Drawing::diamond = loadTexture("assets/diamond.png"); // for the diamonds
	// Drawing::laser = loadTexture("assets/beams.png"); // for the laser -> we dont need laser here

	gTexture = loadTexture("assets/Background.png"); // for the background image
	
	if (Drawing::assets == NULL|| gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::loadLevelTwo()
{
		// Loading success flag
	bool success = true;
	

	Drawing::assets = loadTexture("assets/shipsprite.png"); // for the ship to move
	Drawing::attack = loadTexture("assets/Gameassets/UI bomb.png"); // for the canon
	Drawing::clouds = loadTexture("assets/clouds.png"); // for the clouds
	Drawing::diamond = loadTexture("assets/diamond.png"); // for the diamonds
	Drawing::laser = loadTexture("assets/beams.png"); // for the laser 

	gTexture = loadTexture("assets/Background.png"); // for the background image
	
	if (Drawing::assets == NULL|| gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	SDL_DestroyTexture(Drawing::attack);
	SDL_DestroyTexture(Drawing::clouds);
	SDL_DestroyTexture(Drawing::diamond);
	SDL_DestroyTexture(Drawing::laser);

	Drawing::diamond = NULL;
	Drawing::assets = NULL;
	Drawing::attack = NULL;
	Drawing::clouds = NULL;
	Drawing::laser = NULL;
	
	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::run()
{
	// for the music
	int init2 = Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("assets/Music/bgMusic.ogg"); // background music
	Mix_Chunk* button = Mix_LoadWAV("assets/Music/buttonClick.wav"); // button click sound
	Mix_Chunk* attackSound = Mix_LoadWAV("assets/Music/attack.wav"); // laser + canon attack sound
	Mix_Chunk* diamondFound = Mix_LoadWAV("assets/Music/diamondFound.wav"); // when diamond is collected
	
	Mix_PlayMusic(music, -1); // plays the bg music in loop
	bool quit = false;
	SDL_Event e;

	spaceship ship; // we will have our spaceship here	
	AttackManager* attack = AttackManager::getPointer(); // to display the attacks
	bool checkAttack = false;
	cloudmanager c2;  //cloud created at one level
	cloudmanager c3;  //cloud created at another level
	diamond_manager d;   //diamond created
	bool moveLevel;
	bool collisionCheck;
	int count = 0;
	int adjust = 0;
	int currTime = 0;
	int startTime;	

	while (!quit)
	{		
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
				cout << quit << endl;
			}
	
			// mouse button pressed
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				if (state == 0 and xMouse >= 487 and xMouse <= 710 and yMouse >= 456 and yMouse <= 548)
				{
					state = 2; // state2 represents the game has started (play is pressed)
					Mix_PlayChannel(-1, button, 0);
					loadMedia();					
				}
				else if (state == 0 and xMouse >= 485 and xMouse <= 713 and yMouse >= 573 and yMouse <= 654)
				{
					state = 1; // state 1 is the rules page
					Mix_PlayChannel(-1, button, 0);					
					loadRules();				
				}
				
				 else if (state == 1 and xMouse >=1008 and xMouse <= 1160 and yMouse >= 601 and yMouse <= 659)
				{
					state = 0;
					Mix_PlayChannel(-1, button, 0);
					loadMenu();
				} 
				else if(state==4){
					cout << xMouse << "," << yMouse << endl;
					//return to menu screen button conditions
			 	 	if ((xMouse >= 378 && xMouse <= 760) && (yMouse >= 454 && yMouse <= 615)){
						d.diamondsCollected=0;
						score.score_reset();
						Health.health=100;
						Health.lives=2;
						cout << "health" <<Health.health<< endl;
						cout << "lives" <<Health.lives<< endl;
						//state =  0 is menu screen
						state=0;
					    cout << "game restarted" << endl;
						loadMenu(); 
				}    
				}
			  	else if (state == 5){ //showing level2 screen
					cout << xMouse << "," << yMouse << endl;
					if ((xMouse >= 496 && xMouse <= 700) && (yMouse >= 501 && yMouse <= 583)) //level 2 play button check
					{
						state = 3; //level 2 permenant state
						Mix_PlayChannel(-1, button, 0); //plays music
						startTime = SDL_GetTicks(); //timer
						loadLevelTwo();			    	
					} 
				}
				
				else if(state == 6){ // game won screen
					cout << xMouse << "," << yMouse << endl;
					if((xMouse >= 384 && xMouse <= 751) && (yMouse >= 454 && yMouse <= 609)){
						Mix_PlayChannel(-1, button, 0);
						d.diamondsCollected=0;
						score.score_reset();
						Health.health=100;
						Health.lives=2;
						cout << "health" <<Health.health<< endl;
						cout << "lives" <<Health.lives<< endl;
						//state =  0 is menu screen
						state=0;
					    cout << "game restarted" << endl;
						loadMenu(); 				
					}
				}

			}

			// a key is pressed
			else if(e.type == SDL_KEYDOWN){
				adjust = 0;
				switch( e.key.keysym.sym ){

                    case SDLK_UP:
						ship.moveup();
                        break;

                    case SDLK_DOWN:
						ship.move_down();
                        break;

                    default:
                        break;
                }
			}
			
			else{
				ship.adjust(); // if the button is not pressed the ship will be straight
			}

		}
	
	
		SDL_RenderClear(Drawing::gRenderer); // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer

		// to create attacks with 5% probability
		// showScore();
		int y = rand() % 20;
		switch (y)
		{
			case 1:
				attack->createObject(state); 
				break;
			
			default:
				break;
		}
		
		// ship's collision with attacks
		if(attack->DetectCollision(ship.getRect())){
			checkAttack = true;
			ship.showAttack(Health.getlives());
			adjust++;
			cout << "collision detected" << endl;

			Mix_PlayChannel(-1, attackSound, 0); // play the attack sound

			//whatever is the type of attack, health decrement is 10;
            Health.BothAttack();
			if(Health.health==0){
				Health.life_check();
				if(Health.lives==0){
					Health.alive==false;
					//end game
					gTexture = loadTexture("assets/game_over.png");
					state=4;//end game
				}
    		}
		}

		// ship's collision with diamonds
		if(d.DetectCollision(ship.getRect())){
			cout << "found diamond" << endl; count++;
			cout << "total diamonds = " << d.diamondsCollected<<endl; 
			Mix_PlayChannel(-1, diamondFound, 0); // play the diamond collected sound
			score++;
			cout << "current score: " << score.getScore() << endl;

			
			// move to level two if the player has collected 10 diamonds
			if(state == 2 && d.diamondsCollected == 10){
				moveLevel = true; state = 5; //state 5 is just a temperory state for level2
				gTexture = loadTexture("assets/level2.png");
			}
		}
		if(adjust > 0){adjust++;}

		if(adjust >= 10){
			ship.adjust();
			adjust = 0;
		}

		if(state == 2 || state == 3 ){
			attack->drawObjects(); // display the bombs
			ship.draw(); // display the ship

			// for diamonds
			d.creatobj2();
			d.drawobj2(); 

			// for clouds
			c2.creatobj();
			c3.creatobj1();
			c2.drawobj();
			c3.drawobj1();	

			// to display the score
			score.showScore();	

			// to display the lives left
			Health.displayLife();

			// to display the health
			Health.displayHealth();	
		}
		
		if(state == 3){
			if((SDL_GetTicks() - startTime >= 90000) || (d.diamondsCollected == 20)){
				gTexture = loadTexture("assets/game_won.png");
				state = 6; // temp state for winning screen				
				cout << "game over" << endl;
				
			} 
		}
		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(50); // causes sdl engine to delay for specified miliseconds		
	}
}
