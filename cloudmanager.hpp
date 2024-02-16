using namespace std;
#pragma once
#include "clouds.hpp"
#include "clouds1.hpp"
class cloudmanager{
    private:
        vector<clouds*>cld;
        vector<clouds1*>cld1;
    public:
        // for the first layer of clouds
        void drawobj();
        void drawobj1();

        // second layer of clouds
        void creatobj();
        void creatobj1();

        int check1=0;
        int check=0;

        ~cloudmanager();
};