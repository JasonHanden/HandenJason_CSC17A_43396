
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 7:08 PM
 * Purpose: Celsius to Fahrenheit converter
 */

#include <iostream>     //  Input/Output stream

using namespace std;

int main() {
    short tempC;                                        //  variable declaration
    cout <<"Celsius value to be converted to Fahrenheit: "; //  user prompt
    cin >>tempC;                                            //  value assignment
    
    //  processing, convert 
    short tempF= 9*tempC/5+32;
    //  output
    cout <<tempC <<" converted to Fahrenheit is: " <<tempF;
    return 0;
}