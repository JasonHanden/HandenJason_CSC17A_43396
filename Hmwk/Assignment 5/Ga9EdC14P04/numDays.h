/* 
 * File:   numDays.h
 * Author: Jason Handen
 * Created on May 16, 2021, 1:21 PM
 * Purpose: numDays header file
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
    private:
        short numHour;
        float numDays;
    public:
        NumDays(short);
        float getNumHour();
        void setNumHour(short);
        float getNumDays();
        void setNumDays();
        
        float operator +(NumDays);
        float operator -(NumDays);
        void operator ++();
        void operator ++(int);
        void operator --();
        void operator --(int);
};


#endif /* NUMDAYS_H */

