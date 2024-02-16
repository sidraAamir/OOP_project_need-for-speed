using namespace std;
#include "diamond.hpp"
#include<vector>

class diamond_manager

{
    private:
          vector<diamond*>dim;
    // for the diamonds
    public:
    void drawobj2();
    void creatobj2();

    // to check if the ship collided with the diamond
    bool DetectCollision(SDL_Rect);

    // to keep track of the number of diamonds
    int diamondsCollected = 0;
    int check2;
    ~diamond_manager();
};