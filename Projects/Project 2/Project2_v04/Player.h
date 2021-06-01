/* 
 * File:   Player.h
 * Author: Jason Handen
 * Created on May 30, 2021, 8:47 PM
 * Purpose: Player header file
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

class Player:public Hand{
    private:
        float start$=0;              // to implement monetary betting system
        float end$=0;
    public:
        Player();
        Player(float);
        void drawThird();
        
        float getMoney();
        void setMoney(float);
        
        inline friend void operator + (Player,float);
        inline friend void operator - (Player,float);
        friend float operator / (Player,float);
};

#endif /* PLAYER_H */

