
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on June 3, 2021, 4:16 PM
 * Purpose: Problem 1 Driver main
 */

#include <iostream>
#include "Prob1Random.h"

using namespace std;

int main() {
    
    cout<<"Problem 1: Random Numbers\n";
    
    char n=5;
    char rndseq[]={18,33,56,79,124};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    return 0;
}