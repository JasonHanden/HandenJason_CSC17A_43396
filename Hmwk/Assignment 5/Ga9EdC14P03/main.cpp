
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 8:48 PM
 * Purpose: 
 */

#include <iostream>
#include "dayOfYear.h"

using namespace std;

int main(int argc, char** argv) {
    
    string month;
    short day;
    
    cout<<"Please enter a month and day: ";
    cin>>month>>day;
    
    DayOfYear dayOfYear(month,day);
    
    dayOfYear.print2();
    
    return 0;
}