#include <vector>
#include "canon.hpp"
#include "laser.hpp"
#include "spaceship.hpp"
using namespace std;
#include <map>
#pragma once

// SINGLETON CLASS

class AttackManager{
    public:
        // returns the class pointer
        static AttackManager* getPointer();

        // map to store the attacks and the direction of their movement
        map<Attack*, string> attacks;

        // draws and moves all objects
        void drawObjects(); 

        // obtains a dynamic memory
        void createObject(int);

        // returns true if the attack has collided with the ship
        bool DetectCollision(SDL_Rect);

        //Performance ship_health;
        string a_type;
        
        //friend class Performance;
        Performance Health;

    private:
        // constructor
        AttackManager();

        // destructor to release dynamic memory
        ~AttackManager();

        // static pointer
        static AttackManager* objPointer;
};