/* 
 * File:   Round.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 9:14 PM
 * Purpose: Round source file
 */

#include "Round.h"

static short count=-1;          // aligns as index for program

Round::Round(){
    rndNum=getCount();
}

short Round::getCount(){
    count++;
    return count;
}

bool Round::compBetResult(){
    return betType==result;
}
/*
float calcPayout(float b,bool r,short t){
    float payout=b;
    if(r){
            return -payout;
    }
    return payout;
}
*/
short Round::getRndNum(){
    return rndNum;
}
short Round::getBetType(){
    return betType;
}
float Round::getBetAmnt(){
    return betAmnt;
}
short Round::getSumPlyr(){
    return sumPlyr;
}
short Round::getSumBnkr(){
    return sumBnkr;
}
short Round::getResult(){
    return result;
}
float Round::getPayout(){
    return payout;
}

void Round::setRndNum(short rnd){
    valCheck(rnd,0,20);
    rndNum=rnd;
}
void Round::setBetType(short b){
    valCheck(b,1,3);
    betType=b;
}
void Round::setBetAmnt(float m){
    valCheck(m,0);
    betAmnt=m;
}
void Round::setSumPlyr(short sumP){
    valCheck(sumP,0,9);
    sumPlyr=sumP;
}
void Round::setSumBnkr(short sumB){
    valCheck(sumB,0,9);
    sumBnkr=sumB;
}
void Round::setResult(short res){
    valCheck(res,1,3);
    result=res;
}
void Round::setPayout(float p){
    payout=p;
}

template<class T> 
void Round::valCheck(T value,const short MIN,const short MAX){
    if(value<MIN || value>MAX){
        throw BadValueEx();
    }
}
template<class T> 
void Round::valCheck(T value,const short MIN){
    if(value<MIN){
        throw BadValueEx();
    }
}