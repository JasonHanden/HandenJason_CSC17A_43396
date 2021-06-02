/* 
 * File:   Player.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 8:47 PM
 * Purpose: Player source file
 */

#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(){}

Player::Player(float m){
    Player::setMoney(m);
}

void Player::drawThird(){
    trueHit();
}
        
float Player::getMoney(){
    return end$;
}
void Player::setMoney(float m){
    
    start$=m;
    end$=m;
}

// add money after won bet
void operator += (Player player,float a){
    player.end$+=a;
}
// subtract money after lost bet
void operator -= (Player player,float s){
    player.end$-=s;
}
// for averaging money
float operator / (Player player,float d){
    return (player.end$-player.start$)/d;
}

// input validation implementation
float Player::valCheck(float value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}