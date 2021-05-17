
/* 
 * File:   dayOfYear.h
 * Author: Jason Handen
 * Created on May 15, 2021, 8:51 PM
 * Purpose: day of year header file
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear{
    private:
        short day;
        string prntStr;
    public:
        DayOfYear(short);
        short prep();
        void print();
        short valCheck(short,const short,const short);
};


#endif /* DAYOFYEAR_H */

