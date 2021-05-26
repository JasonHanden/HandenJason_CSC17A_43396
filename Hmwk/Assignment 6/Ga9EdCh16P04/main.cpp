
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 8:43 PM
 * Purpose: More Templates
 */

#include <iostream>

using namespace std;

template<class T> T abs(T a);

int main(int argc, char** argv) {
    short a=2;
    int b=-1800;
    float c=-12.498;
    
    cout<<"Absolute value of short "<<a<<" is "<<abs(a)<<endl;
    cout<<"Absolute value of short "<<b<<" is "<<abs(b)<<endl;
    cout<<"Absolute value of short "<<c<<" is "<<abs(c)<<endl;
    
    return 0;
}

template<class T> T abs(T a){
    if(a<0)
        a*=-1;
    return a;
}