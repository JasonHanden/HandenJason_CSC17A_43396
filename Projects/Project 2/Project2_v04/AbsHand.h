/* 
 * File:   AbsHand.h
 * Author: Jason Handen
 * Created on May 31, 2021, 8:48 PM
 * Purpose: full virtual class for inheritance
 */

#ifndef ABSHAND_H
#define ABSHAND_H

#include <string>
using namespace std;

class AbsHand{
    public:
        AbsHand(){};
        ~AbsHand(){};
        virtual void drawThird()=0;         // different implementation for player/banker
        virtual void dealCards()=0;         // deal all three cards
        virtual void writeCards()=0;        // write card name to string
        virtual void sumCards(short,short)=0;// sum given cards
        virtual string getCard(short)=0;    // return card name
        virtual bool getNatural()=0;        // return natural status, true or false
        virtual bool getHit()=0;            // return hit status, true or false
        virtual short getSum()=0;           // return sum of hand
        virtual void setNatural()=0;        // set Natural to true
        virtual void trueHit()=0;           // set Hit to true, call sum

};

#endif /* ABSHAND_H */

