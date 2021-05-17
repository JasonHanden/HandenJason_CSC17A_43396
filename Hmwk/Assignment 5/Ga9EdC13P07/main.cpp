
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 7:17 PM
 * Purpose: 
 */

#include <iostream>
#include "testScores.h"
using namespace std;

int main(int argc, char** argv){
    float sc0,sc1,sc2;
    cout<<"Enter three test scores to average: ";
    cin>>sc0>>sc1>>sc2;
    
    TestScores testScores(sc0,sc1,sc2);
    cout<<"The average of the three scores is: "<<testScores.getAverage();
    
    return 0;
}