#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "drawing.hpp"
#include <iostream>
using namespace std;
class Score
{
    public:
        // overloaded postfix ++ operator
        void operator ++ (int);

        // returns the score
        int getScore();

        // initializes the score
        Score();

        // displays the score
        void showScore();
        void score_reset();

    private:
        int score;
};