
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

    short day;
    cout<<"Please enter a day of the year: ";
    cin>>day;
    
    DayOfYear dayOfYear(day);
    
    dayOfYear.print();
    
    return 0;
}