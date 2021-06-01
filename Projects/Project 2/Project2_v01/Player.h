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
        float money=0;              // to implement monetary betting system
    public:
        void drawThird();
        
        float getMoney();
        void operator+(Player,float);
        void operator-(Player,float);
};

#endif /* PLAYER_H */

