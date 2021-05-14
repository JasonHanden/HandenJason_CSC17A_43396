
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 26, 2021, 12:29 AM
 * Purpose: 
 */

#include <iostream>
#include <iomanip>


using namespace std;

int main(int argc, char** argv) {

    char character=1;
    unsigned char unsigChar=1;
    short shortInt=1;
    unsigned short unsigShort=1;
    int integer=1;
    unsigned int unsigInt=1;
    float floating=1;
    double doubleFloat=1;
    
    int n=171;
    
    for(int i=1;i<=n;i++){
        character*=i;
        unsigChar*=i;
        shortInt*=i;
        unsigShort*=i;
        integer*=i;
        unsigInt*=i;
        floating*=i;
        doubleFloat*=i;
    }

    cout<<"N = "<<n<<endl;
    cout<<" character:"<<character <<endl;    
    cout<<" unsigChar:"<<unsigChar <<endl;
    cout<<" shortInt:"<<shortInt <<endl;
    cout<<" unsigShort:"<< unsigShort<<endl;
    cout<<" integer:"<<integer <<endl;
    cout<<" unsigInt:"<<unsigInt <<endl;
    cout<<" floating:"<<floating <<endl;
    cout<<" doubleFloat:"<<doubleFloat <<endl;

/*
    cout<<"The highest n for which n! can be calculated for the following data types:\n"
        <<" char              n=5\n"
        <<" unsigned char     n=5\n"
        <<" short             n=7\n"
        <<" unsigned short    n=8\n"
        <<" int               n=12\n"
        <<" unsigned int      n=12\n"
        <<" float             n=13\n"
        <<" double            n=22\n";
*/    
    
    return 0;
}