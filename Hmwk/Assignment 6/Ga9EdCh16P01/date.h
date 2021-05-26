/* 
 * File:   date.h
 * Author: Jason Handen
 * Created on May 15, 2021, 2:31 PM
 * Purpose: date class header file
 */

#ifndef DATE_H
#define DATE_H

using namespace std;
#include <string>

class Date{
    private:
        short date[3]; 
            // Element 0: month value
            // Element 1: day value
            // Element 2: year value
        string mnthStr;
    
    public:
        class InvalidDay{};
        class InvalidMonth{};
        void setDate(short month,short day,short year);
        void strSet();
        void dtNumb();
        void dtMonth();
        void dtDay();
};

#endif /* DATE_H */
