
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 8:53 PM
 * Purpose: Summing Template
 */

#include <iostream>

using namespace std;

template<class T> float total(T a);

int main(int argc, char** argv) {
    short a=2;
    int b=3;
    float c=4,sum;
    
    cout<<"Short argument:\n";
    sum=total(a);
    cout<<"Total is: "<<sum<<endl;
    
    cout<<"Int argument:\n";
    sum=total(b);
    cout<<"Total is: "<<sum<<endl;
    
    cout<<"Float argument:\n";
    sum=total(c);
    cout<<"Total is: "<<sum<<endl;
    
    return 0;
}

template<class T> float total(T a){
    float total=0,temp;
    for(short i=0; i<a; i++){
        cout<<"Please enter a value for the running total: ";
        cin>>temp;
        total+=temp;
    }
    return total;
}