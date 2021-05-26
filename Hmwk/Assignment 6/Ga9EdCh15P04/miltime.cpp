
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
    milHour=MilTime::valCheck(hr,0,2359,"hour");
    milSec=MilTime::valCheck(s,0,59,"second");
    
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


short MilTime::valCheck(short value,const short MIN,const short MAX,string str){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid "<<str
                                <<" entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}