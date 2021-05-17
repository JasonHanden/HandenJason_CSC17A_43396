
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
        string month;
        string prntStr;
        short result;
    public:
        DayOfYear(short);
        DayOfYear(string,short);
        void numbPrep();
        short prep();
        void print1();
        void print2();
        short valCheck(short,const short,const short);
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
};


#endif /* DAYOFYEAR_H */

