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
    if(s>0&&s<21){
        rndTot=s;
        Round *rnd = new Round[rndTot];
        round=rnd;
    }else{
        throw BadRoundCount();
    }
}
Result::Result(Result& obj){
    rndTot=obj.getRndTot();
    wins=obj.getWins();
    losses=obj.getLosses();
    playerS$=obj.getPlayerS$();
    playerE$=obj.getPlayerE$();
    
    Round *rnd = new Round;
    round=rnd;
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
float Result::getPlayerS$(){
    return playerS$;
}
float Result::getPlayerE$(){
    return playerE$;
}
// SETTERS
void Result::setRndTot(short t){
    valCheck(t,1,20);
    rndTot=t;
}
void Result::setWins(short w){
    valCheck(w,0,20);
    wins=w;
}
void Result::setLosses(short l){
    valCheck(l,0,20);
    losses=l;
}
void Result::setPlayerS$(float m){
    valCheck(m,0);
    playerS$=m;
}
void Result::setPlayerE$(float m){
    playerE$=m;
}
// adds one to wins category
void Result::addWin(){
    ++wins;
}
// adds one to losses category
void Result::addLoss(){
    ++losses;
}

template<class T> 
void Result::valCheck(T value,const short MIN,const short MAX){
    if(value<MIN || value>MAX){
        throw BadValueEx();
    }
}
template<class T> 
void Result::valCheck(T value,const short MIN){
    if(value<MIN){
        throw BadValueEx();
    }
}