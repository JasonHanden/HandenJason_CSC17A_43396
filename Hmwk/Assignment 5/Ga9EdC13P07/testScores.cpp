/* 
 * File:   testScores.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 7:17 PM
 * Purpose: Test scores source file
 */

#include "testScores.h"
using namespace std;

TestScores::TestScores(float sc0,float sc1,float sc2){
    scores[0]=sc0;
    scores[1]=sc1;
    scores[2]=sc2;
    average=0;
}
float TestScores::getAverage(){
    for(short i=0;i<3;i++){
        average+=scores[i];
    }
    average/=3;
    return average;
}