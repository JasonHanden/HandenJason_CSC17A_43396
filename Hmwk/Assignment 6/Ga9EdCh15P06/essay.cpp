/* 
 * File:   essay.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 6:57 PM
 * Purpose: Essay class source file
 */

#include "essay.h"
#include <string>
#include <iostream>
using namespace std;

Essay::Essay(float g,float s,float l,float c){
    grammar=Essay::valCheck(g,0,30,"grammar");
    spelling=Essay::valCheck(s,0,20,"spelling");
    length=Essay::valCheck(l,0,20,"correct length");
    content=Essay::valCheck(c,0,30,"content");
    
    score=grammar+spelling+length+content;
}
char Essay::getLetterGrade(){
    if(score>89.5){
        return 'A';
    }else if(score>79.5){
        return 'B';
    }else if(score>69.5){
        return 'C';
    }else if(score>59.5){
        return 'D';
    }else{
        return 'F';
    }
}
float Essay::getGram(){
    return grammar;
}
float Essay::getSpel(){
    return spelling;
}
float Essay::getLeng(){
    return length;
}
float Essay::getCont(){
    return content;
}

float Essay::valCheck(float value,const short MIN,const short MAX,string str){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid "<<str
                                <<" score between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}
