
/* 
 * File:   miltime.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 6:08 PM
 * Purpose: Military Time source file
 */


#include "miltime.h"
#include <iostream>
#include <string>
using namespace std;

MilTime::MilTime(short hr,short s){
    
    if(hr>=0&&hr<2400){
        milHour=hr;
    }else{
        throw BadHour();
    }

    if(s>=0&&s<60){
        milSec=s;
    }else{
        throw BadSec();
    }
        
    MilTime::setTime(milHour,milSec);
}
void MilTime::setTime(short hr,short s){
    hour=hr/100;
    if(hour>12){
        hour-=12;
    }
    
    min=hr%100;
    
    sec=s;
}
short MilTime::getHour(){
    return milHour;
}

short MilTime::getStdHr(){ 
    return hour;
}