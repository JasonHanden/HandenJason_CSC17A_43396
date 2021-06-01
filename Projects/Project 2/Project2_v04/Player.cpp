/* 
 * File:   Player.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 8:47 PM
 * Purpose: Player source file
 */

#include "Player.h"

Player::Player(){

}
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
void operator + (Player player,float a){
    player.end$+=a;
}
// subtract money after lost bet
void operator - (Player player,float s){
    player.end$-=s;
}
// for averaging money
float operator / (Player player,float d){
    return (player.end$-player.start$)/d;
}