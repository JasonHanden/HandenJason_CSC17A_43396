/* 
 * File:   Player.h
 * Author: Jason Handen
 * Created on May 30, 2021, 8:47 PM
 * Purpose: Player header file
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <vector>
using namespace std;

class Player:public Hand{
    private:
        float start$=0;              // to implement monetary betting system
        float end$=0;
        vector<char> name;
    public:
        Player();
        Player(float);
        void drawThird();
        
        inline float getSMoney(){
            return start$;
        }
        inline float getMoney(){
            return end$;
        }
        inline vector<char> getName(){
            return name;
        }
        void setFMoney(float);
        void setMoney(float);
        void setName(vector<char>);
        
        friend float operator + (Player,float);
        friend float operator - (Player,float);
        friend float operator / (Player,float);
        
        float valCheck(float,const short,const int);
};

#endif /* PLAYER_H */