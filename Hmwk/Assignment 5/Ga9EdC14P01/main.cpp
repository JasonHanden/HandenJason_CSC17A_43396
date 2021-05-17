
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 7:32 PM
 * Purpose: 
 */

#include <iostream>

#include "numbers.h"

using namespace std;

int main(int argc, char** argv) {
    
    short number=0;
    
    cout<<"Please enter a value between 0 and 9999: ";
    cin>>number;
    
    Numbers numbers(number);
    
    numbers.print();
    
    return 0;
}