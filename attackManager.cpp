#include "attackManager.hpp"


AttackManager::AttackManager(){} // no need to write anything here

AttackManager* AttackManager::objPointer = NULL;

AttackManager* AttackManager::getPointer(){
    if(objPointer == NULL){
        objPointer = new AttackManager();
    }
    return objPointer;
}

void AttackManager::drawObjects(){
    // draw all the attacks
    for(auto attack : attacks){
        if(attack.first != NULL){
            attack.first->draw();

            // move according to the attack's origin

            if(attack.second == "northeast"){
                attack.first->move_NorthEast();
            }
            else if(attack.second == "northwest"){
                attack.first->move_NorthWest();
            }
            else if(attack.second == "laser"){
                attack.first->move_right();
            }
            else{
                attack.first->move_up();
            }
        }
    }
}

void AttackManager::createObject(int state){
    // choose which attack to shoot
    //string attack_type; //holds type of attack 
    int att = rand() % 2; 
    // if in level 1, this is the only option. In level 2, it depends on the value of att
    if((att == 0 && state == 3) || state == 2){
        a_type = "canon";
        // selects a random position to attack from
        int s = rand() % 3;
        switch (s)
        {
        case 0: // coming from the left side of the screen
            attacks.insert(pair<Attack*, string>(new Canon("northeast"), "northeast"));
            break;
        
        case 1: // coming from the right side of the screen 
            attacks.insert(pair<Attack*, string>(new Canon("northwest"), "northwest"));
            break;

        case 2: // coming from the middle of the screen
            attacks.insert(pair<Attack*, string>(new Canon("up"), "up"));   
            break;

        default:
            break;
        }

    }
    // will only work if we're in level 2 or state 3
    else if(att == 1 && state == 3){
        a_type = "laser";
        attacks.insert(pair<Attack*, string>(new Laser(), "laser"));  
    }
    

}

AttackManager::~AttackManager(){
    // release dynamic memory allocated to all the keys.
    for(auto attack : attacks){
        if(attack.first != NULL){
            delete attack.first;
            // bombs.erase(attack.first);
        }
    }
    attacks.clear(); // clear the map
    cout << "everything deleted" << endl;
    delete objPointer;
}

bool AttackManager::DetectCollision(SDL_Rect coord){
    int h = coord.h; 
    int w = coord.w;
    int x = coord.x;
    int y = coord.y;
    
 
    for(auto attack : attacks){
        // remove the attack from the screen and deduct points for attack
        if((x == attack.first->getX()) || ((x + w) == attack.first->getX())){
            if((attack.first->getY() >= y && attack.first->getY() <= (y + h))){
                Attack* temp = attack.first;           
                attacks.erase(attack.first);
                temp = NULL;
                return true;    
            }
        }
        else if(y == attack.first->getY()){
            if((x + w) >= attack.first->getX() && (x + w) <= (attack.first->getX() + w)){
                Attack* temp = attack.first;
                attacks.erase(attack.first);
                temp = NULL;
                return true;
            }
        }
    
        
    }
    return false;
}