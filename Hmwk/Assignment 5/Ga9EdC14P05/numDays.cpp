/* 
 * File:   numDays.h
 * Author: Jason Handen
 * Created on May 16, 2021, 1:21 PM
 * Purpose: numDays source file
 */

#include "numDays.h"

NumDays::NumDays(short hours){
    numHour=hours;
    NumDays::setNumDays();
}
float NumDays::getNumHour(){
    return numHour;
}
void NumDays::setNumHour(short hours){
    numHour=hours;
    NumDays::setNumDays();
}
float NumDays::getNumDays(){
    return numDays;
}
void NumDays::setNumDays(){
    numDays=(float)numHour/8;
}

float NumDays::operator +(NumDays add1){
    float sum = numHour + add1.numHour;
    return sum;
}
float NumDays::operator -(NumDays add1){
    float diff = numHour - add1.numHour;
    return diff;
}
void NumDays::operator ++(){
    numHour++;
    NumDays::setNumDays();
}
void NumDays::operator ++(int){
    numHour++;
    NumDays::setNumDays();
}
void NumDays::operator --(){
    numHour--;
    NumDays::setNumDays();
}
void NumDays::operator --(int){
    numHour--;
    NumDays::setNumDays();
}