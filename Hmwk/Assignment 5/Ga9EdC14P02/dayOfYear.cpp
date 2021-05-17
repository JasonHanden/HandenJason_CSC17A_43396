
/* 
 * File:   dayOfYear.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 8:51 PM
 * Purpose: day of year source file
 */

#include <string>
#include <iostream>
#include "dayOfYear.h"

static const string months[]={
    "January","February","March","April","May","June","July","August",
            "September","October","November","December"
};
static const short mnthVal[]={
    31,28,31,30,31,30,31,31,30,31,30,31
};


DayOfYear::DayOfYear(short dayVal){
    day=valCheck(dayVal,1,365);
}
short DayOfYear::prep(){
    prntStr="";
    short dayNew=day;
    short counter=0;
    
    while(dayNew>0){
        dayNew-=mnthVal[counter];
        if(dayNew>0) 
            counter++;
    }
    prntStr+=months[counter];
    prntStr+=" ";
    
    dayNew+=mnthVal[counter];
    return dayNew;
    
}
void DayOfYear::print(){
    short dayNew=DayOfYear::prep();
    cout<<prntStr<<dayNew<<" is Day #"<<day;
}

short DayOfYear::valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}