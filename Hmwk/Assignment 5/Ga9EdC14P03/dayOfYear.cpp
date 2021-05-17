
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

DayOfYear::DayOfYear(string mnthStr,short dayVal){
    month=mnthStr;
    day=valCheck(dayVal,1,31);
}
void DayOfYear::numbPrep(){
    result=day;
    for(short i=0;i<12;i++){
        if(month==months[i]){
            for(short j=0;j<i;j++){
                result+=mnthVal[j];
            }
        }
    }
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
void DayOfYear::print1(){
    short dayNew=DayOfYear::prep();
    cout<<prntStr<<dayNew<<" is Day #"<<day;
}
void DayOfYear::print2(){
    DayOfYear::numbPrep();
    cout<<month<<" "<<day<<" is the "<<result<<" day of the year.";
}
short DayOfYear::valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}

void DayOfYear::operator ++(){    
    result++;
    if(result>365){
        result=1;
    }
}
void DayOfYear::operator ++(int){    
    result++;
    if(result>365){
        result=1;
    }
}
void DayOfYear::operator --(){    
    result--;
    if(result<1){
        result=365;
    }
}
void DayOfYear::operator --(int){    
    result--;
    if(result<1){
        result=365;
    }
}