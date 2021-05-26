
/* 
 * File:   miltime.h
 * Author: Jason Handen
 * Created on May 25, 2021, 6:08 PM
 * Purpose: Military Time header file
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "time.h"
#include <string>
using namespace std;

class MilTime:public Time{
    private:
        short milHour;
        short milSec;
    public:
        MilTime(short,short);
        void setTime(short,short);
        short getHour();
        short getStdHr();
        short valCheck(short,const short,const short,string);
};


#endif /* MILTIME_H */

