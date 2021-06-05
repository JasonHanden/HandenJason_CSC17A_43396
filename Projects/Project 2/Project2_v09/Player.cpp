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
    Player::setFMoney(m);
    Player::setMoney(m);
}

void Player::drawThird(){
    trueHit();
}
// Replaced get function once it became inline
void Player::setFMoney(float m){
    m=valCheck(m,0,100000);
    start$=m;
    end$=m;
}
void Player::setMoney(float m){
    m=valCheck(m,0,100000);
    end$=m;
}
void Player::setName(vector<char> s){
    name=s;
}

// add money after won bet
float operator + (Player player,float a){
    return player.end$+a;
}
// subtract money after lost bet
float operator - (Player player,float s){
    return player.end$-s;
}
// for averaging money
float operator / (Player player,float d){
    return (player.end$-player.start$)/d;
}

// input validation implementation
float Player::valCheck(float value,const short MIN,const int MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}