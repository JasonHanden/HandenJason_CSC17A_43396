
/* 
 * File:   time.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 5:07 PM
 * Purpose: Time header source
 */

#include "time.h"

Time::Time(){
    hour=0;
    min=0;
    sec=0;
}
Time::Time(short h,short m,short s){
    hour=h;
    min=m;
    sec=s;
}
short Time::getHour() const{
    return hour;
}
short Time::getMin() const{
    return min;
}
short Time::getSec() const{
    return sec;
}