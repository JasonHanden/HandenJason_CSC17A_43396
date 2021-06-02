/* 
 * File:   Hand.h
 * Author: Jason Handen
 * Created on May 30, 2021, 7:30 PM
 * Purpose: Hand header file (abstract class), for inheritance
 */

#ifndef HAND_H
#define HAND_H

#include "AbsHand.h"

#include <string>
using namespace std;

class Hand:public AbsHand{
    protected:
        string card[3];
        short value[3];
        bool natural=false;
        bool hit=false;
        short sum;
    public:
        enum suit{CLUBS,DIAMONDS,HEARTS,SPADES};    // for card naming
        
        Hand();
        void drawThird(){};         // different implementation for player/banker
        void dealCards();           // deal all three cards
        void writeCards();          // write card name to string
        void sumCards(short,short); // sum given cards
        
        string getCard(short);      // return card name
        short getValue(short);      // return card value
        bool getNatural();          // return natural status, true or false
        bool getHit();              // return hit status, true or false
        short getSum();             // return sum of hand
        
        void setNatural();          // set Natural to true
        void trueHit();             // set Hit to true, call sum
};

#endif /* HAND_H */