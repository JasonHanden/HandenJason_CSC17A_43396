
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 9:53 PM
 * Purpose: Celsius Temp Table
 */

#include <iostream>
#include <iomanip>
float celsius(short);

using namespace std;

int main() {
    // print table and call celsius function
    cout <<"---------------\n"
         <<"| degF | degC |\n";
    for(short i=0; i<21; i++){
        cout <<"|" <<setw(4) <<i <<"  |" <<fixed <<setprecision(2) <<setw(6) <<celsius(i) <<"|\n";
    }
    cout <<"---------------" <<endl;

    return 0;
}
// Fahrenheit to Celsius conversion function
float celsius(short F){
    float C = (float(F)-32)*5/9;
    return C;
}