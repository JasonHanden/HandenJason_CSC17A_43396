
/* 
 * File:   time.h
 * Author: Jason Handen
 * Created on May 25, 2021, 5:07 PM
 * Purpose: Time header file
 */

#ifndef TIME_H
#define TIME_H

class Time{
    protected:  
        short hour;
        short min;
        short sec;
    public:
        Time();
        Time(short,short,short);
        short getHour() const;
        short getMin() const;
        short getSec() const;
};


#endif /* TIME_H */

