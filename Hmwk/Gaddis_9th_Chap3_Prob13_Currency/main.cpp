
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 7:43 PM
 * Purpose: Currency converter
 */

#include <iostream>     //  Input/Output stream
#include <iomanip>

using namespace std;


int main() {
    const float YEN_PER_DOLLAR = 105.63;        // dollar-yen conversion factor
    const float EURO_PER_DOLLAR = 0.8249;       // dollar-euro conversion factor
    
    unsigned short dolAmnt;                     //  variable declaration
    cout <<"Enter dollar amount: $";            //  user prompt
    cin >>dolAmnt;                              //  value assignment
    
    //  processing, conversion
    float yenAmnt= dolAmnt * YEN_PER_DOLLAR;
    float eurAmnt= dolAmnt * EURO_PER_DOLLAR;
    
    //  output
    cout <<fixed <<setprecision(2) <<showpoint
            <<"$" <<dolAmnt <<" is equivalent to:\n"
            <<yenAmnt <<" yen\n"
            <<eurAmnt <<" euros\n";
    return 0;
}