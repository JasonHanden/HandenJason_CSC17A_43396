/* 
 * File:   Result.cpp
 * Author: Jason Handen
 * Created on May 31, 2021, 6:22 PM
 * Purpose: Result source file
 */

#include "Result.h"
#include "Round.h"

#include <iostream>

// constructor for first use
Result::Result(){
    rndTot=0;

    Round *rnd = new Round;
    round=rnd;
}
// constructor for second use
Result::Result(short s){
    //if(s>0&&s<21){

        rndTot=s;

        Round *rnd = new Round[rndTot];
        
        round=rnd;
    /*}else{
        throw BadRoundCount();
    }*/
}
// destructor to clean up dynamic memory allocation
Result::~Result(){  
    delete round;
}

// GETTERS
short Result::getRndTot(){
    return rndTot;
}
short Result::getWins(){
    return wins;
}
short Result::getLosses(){
    return losses;
}
float Result::getPlayer$(){
    return player$;
}
// SETTERS
void Result::setRndTot(short t){
    rndTot=t;
}
void Result::setWins(short w){
    wins=w;
}
void Result::setLosses(short l){
    losses=l;
}
void Result::setPlayer$(float m){
    player$=m;
}
// adds one to wins category
void Result::addWin(){
    ++wins;
}
// adds one to losses category
void Result::addLoss(){
    ++losses;
}