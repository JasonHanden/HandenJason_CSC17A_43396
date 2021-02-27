
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 8:36 PM
 * Purpose: Find Days in a Given Month 
 */

#include <iostream>

using namespace std;

int main() {
    // variable declarations
    unsigned short month;    // for input
    unsigned short year;     // for input
    unsigned char index;     // for day assignment
    // Days in each month (29 for leap years)
    const unsigned char days[]= {31,28,31,30,31,30,31,31,30,31,30,31,29};
    
    // user prompts and input assignment
    cout <<"Enter a month (1-12): ";
    cin >>month;
    while (month<1 || month>12){
        cout <<"Please enter a valid month value: ";
        cin >>month;
    }
    cout <<"Enter a year: "; 
    cin >>year;
    
    // data processing, decide index value
    if (month==2){      // check for leap year
        if(year%100==0 && year%400==0)
            index=12;
        else if(year%4==0 && year%100!=0)
            index=12;
        else 
            index=1;
    }
    else{               // ready index for use in array
        index=month-1;
    }
    
    // result output
    cout <<static_cast<int>(days[index]) <<" days\n";
    
    return 0;
}