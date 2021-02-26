
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 9:17 PM
 * Purpose: Predict Population Size
 */

#include <iostream>

using namespace std;

int main() {
    short Org;          // starting organisms
    float popIncr;      // daily population increase
    short days;         // days for which the simulation will run

    // user prompts
    cout <<"Enter the starting number of organisms: ";
    cin >>Org;
    while(Org<2){       // input validation
        cout <<"Please select a value of 2 or greater: ";
        cin >>Org;
    }
    cout <<"Enter the average daily population increase (as a %): ";
    cin >>popIncr;
    while(popIncr<0){   // input validation
        cout <<"Please choose a positive value: ";
        cin >>popIncr;
    }
    cout <<"Enter the number of days for multiplication: ";
    cin >>days;
    while(days<1){      // input validation
        cout <<"Please choose a number greater than 0: ";
        cin >>days;
    }

    // calculation and output 
    popIncr=popIncr/100+1;          // convert user percentage to usable decimal
    for(short i=0; i<days; i++){      // loop for printing population day on day
        Org*=popIncr;
        cout <<"Population on day " <<i+1 <<" is " <<Org <<endl;
    }
    
    return 0;
}