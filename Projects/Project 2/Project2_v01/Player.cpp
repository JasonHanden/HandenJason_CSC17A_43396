/* 
 * File:   Player.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 8:47 PM
 * Purpose: Player source file
 */

#include "Player.h"

void Player::drawThird(){
    // will implement this in future revision
}
        
float Player::getMoney(){
    return money;
}
// add money after won bet
void Player::operator+(Player player,float a){
    player.money+=a;
}
// subtract money after lost bet
void Player::operator-(Player player,float s){
    player.money-=s;
}