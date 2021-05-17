
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 16, 2021, 1:20 PM
 * Purpose: 
 */

#include <iostream>
#include <iomanip>
#include "numDays.h"

using namespace std;

int main(int argc, char** argv) {
    short input;
    
    cout<<"How many hours did you work: ";
    cin>>input;
    NumDays numDays(input);
    
    cout<<numDays.getNumHour()<<" is "
            <<fixed<<setprecision(2)<<(float)numDays.getNumDays()<<" work days";
    
    return 0;
}