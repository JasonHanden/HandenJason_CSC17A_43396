
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 4:57 PM
 * Purpose: 
 */

#include <iostream>

#include "time.h"
#include "miltime.h"

using namespace std;

int main(int argc, char** argv) {

    short hour,sec;
    cout<<"Please enter the time in military format(HHMM SS): ";
    cin>>hour>>sec;
    
    MilTime mil(hour,sec);
    
    cout<<"The time is: "<<mil.getStdHr()<<":"<<mil.getMin()<<":"<<mil.getSec()<<endl;
    cout<<"Military time is: "<<mil.getHour()<<" hours and "<<mil.getSec()<<" seconds\n";
    
    return 0;
}