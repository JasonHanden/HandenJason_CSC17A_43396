/* 
 * File:   Banker.h
 * Author: Jason Handen
 * Created on May 30, 2021, 8:40 PM
 * Purpose: Banker header file
 */

#ifndef BANKER_H
#define BANKER_H

#include "Hand.h"

class Banker:public Hand{
    private:
        
    public:
        void drawThird();       // overwrites virtual from Hand abstract class
};

#endif /* BANKER_H */

