
/* 
 * File:   timeOff.h
 * Author: Jason Handen
 * Created on May 16, 2021, 4:33 PM
 * Purpose: TimeOff header file
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <string>
#include "numDays.h"
using namespace std;

class TimeOff{
    private:
        string empName;
        int empNumb;
        
        NumDays mxSckDy(0);
        NumDays sckTake(0);
        NumDays vacMax(0);
        NumDays vacTakn(0);
        NumDays unpMax(0);
        NumDays unpTakn(0);
        
    public:
        TimeOff();
        void setMxSckDy(short);
        short getMxSckDy();
        void setSckTake(short);
        short getSckTake();
        void setVacMax(short);
        short getVacMax();
        void setVacTakn(short);
        short getVacTakn();
        void setUnpMax(short);
        short getUnpMax();
        void setUnpTakn(short);
        short getUnpTakn();
        short valCheck(short,const short,const short);
};


#endif /* TIMEOFF_H */

