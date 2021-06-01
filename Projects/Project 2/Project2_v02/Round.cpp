/* 
 * File:   Round.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 9:14 PM
 * Purpose: Round source file
 */

#include "Round.h"

Round::Round(){}

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
        rndNum=rnd;
}
void Round::setBetType(short b){
        betType=b;
}
void Round::setBetAmnt(float m){
        betAmnt=m;
}
void Round::setSumPlyr(short sumP){
        sumPlyr=sumP;
}
void Round::setSumBnkr(short sumB){
        sumBnkr=sumB;
}
void Round::setResult(short res){
        result=res;
}
void Round::setPayout(float p){
        payout=p;
}