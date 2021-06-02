/* 
 * File:   Hand.cpp
 * Author: Jason Handen
 * Created on May 30, 2021, 7:30 PM
 * Purpose: Hand source file
 */

#include "Hand.h"

#include <string>
using namespace std;

// CONSTRUCTOR
Hand::Hand(){}
// Work Function
void Hand::dealCards(){
    for(short i=0;i<3;i++){
        value[i]=rand()%52;   // value[2] only used if hit set to true
    }
    
    Hand::writeCards();
    Hand::sumCards(value[0],value[1]);
    Hand::setNatural();
}
// GETTER FUNCTIONS
string Hand::getCard(short index){
    return card[index];
}
short Hand::getValue(short index){
    return value[index];
}
bool Hand::getNatural(){
    return natural;
}
bool Hand::getHit(){
    return hit;
}
short Hand::getSum(){
    return sum;
}
//SETTER FUNCTION
void Hand::trueHit(){
    hit=true;
    Hand::sumCards(sum,value[2]);
}

// Protected Utility Functions
void Hand::writeCards(){
    for(short i=0;i<3;i++){
        short suit=value[i]/13;
        // determine card face
        value[i]%=13;
        if(value[i]==0){                  // hand value of 0 is "Ace"
            card[i]="Ace";                // value corrected below
        }else if(value[i]==1){
            card[i]="Two";
        }else if(value[i]==2){
            card[i]="Three";
        }else if(value[i]==3){
            card[i]="Four";
        }else if(value[i]==4){
            card[i]="Five";
        }else if(value[i]==5){
            card[i]="Six";
        }else if(value[i]==6){
            card[i]="Seven";
        }else if(value[i]==7){
            card[i]="Eight";
        }else if(value[i]==8){
            card[i]="Nine";
        }else if(value[i]==9){
            card[i]="Ten";
        }else if(value[i]==10){
            card[i]="Jack";
        }else if(value[i]==11){
            card[i]="Queen";
        }else if(value[i]==12){
            card[i]="King";
        }
        // set to proper value for summing later
        if(value[i]>=0 && value[i]<=8){
            value[i]+=1;                  // pip cards have face value
        }else{
            value[i]=0;                   // 10s and face cards value 0
        }
        // add " of " for formatting
        card[i]+=" of ";
        // determine card suit and concatenate
        switch(suit){
            case CLUBS:card[i]+="Clubs";        break;
            case DIAMONDS:card[i]+="Diamonds";  break;
            case HEARTS:card[i]+="Hearts";      break;
            case SPADES:card[i]+="Spades";      break;
        }
    }
}
void Hand::sumCards(short a,short b){
    sum = a + b;
    if(sum>9){
        sum-=10;
    }
}
void Hand::setNatural(){
    if(sum>7){
        natural=true;
    }
}