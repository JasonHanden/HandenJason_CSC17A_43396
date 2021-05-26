
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 6:41 PM
 * Purpose: 
 */

#include <iostream>
//#include "gradedactivity.h"
#include "essay.h"

using namespace std;

int main(int argc, char** argv) {
    float g,s,l,c;
    
    cout<<"Please enter the grammar score (0-30): ";
    cin>>g;
    cout<<"Please enter the spelling score (0-20): ";
    cin>>s;
    cout<<"Please enter the length score (0-20): ";
    cin>>l;
    cout<<"Please enter the content score (0-30): ";
    cin>>c;
    
    Essay essay(g,s,l,c);
    
    cout<<"\nThe final letter grade is: "<<essay.getLetterGrade()<<endl;
    cout<<"          with a score of: "<<essay.getScore();
    
    
    
    return 0;
}