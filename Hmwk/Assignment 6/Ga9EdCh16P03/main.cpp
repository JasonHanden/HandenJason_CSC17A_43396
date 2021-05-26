
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 8:30 PM
 * Purpose: Demonstrate Templates
 */

#include <iostream>

using namespace std;

template<class T> T minimum(T a,T b);
template<class T> T maximum(T a,T b);

int main(int argc, char** argv) {
    short aShort=1, bShort=3;
    int aInt=100, bInt=52;
    float aFloat=12.5, bFloat=11.9999;
    
    cout<<"Templates for shorts:\n";
    cout<<minimum(aShort,bShort)<<" is less than "<<maximum(aShort,bShort)<<endl;
    
    cout<<"Templates for ints:\n";
    cout<<maximum(aInt,bInt)<<" is greater than "<<minimum(aInt,bInt)<<endl;
    
    cout<<"Templates for floats:\n";
    cout<<minimum(aFloat,bFloat)<<" is less than "<<maximum(aFloat,bFloat)<<endl;
    
    return 0;
}

template<class T>
T minimum(T a,T b){
    if(a<b)
        return a;
    else
        return b;
}

template<class T>
T maximum(T a,T b){
    if(a>b)
        return a;
    else
        return b;
}