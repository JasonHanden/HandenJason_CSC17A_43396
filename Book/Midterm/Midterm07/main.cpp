
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 26, 2021, 3:57 PM
 * Purpose: Prime factors
 */

#include <iostream>

using namespace std;

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int);
void prntPrm(Primes *);

int main(int argc, char** argv) {

    int data=0;
    while(data<2){
        cout<<"Please enter a value between 2 and 10,000: ";
        cin>>data;
    }
    
    Primes *primes=factor(data);
    
    cout<<data<<" = ";
    prntPrm(primes);
    

    delete primes->prime;
    delete primes;
    return 0;
}

Primes *factor(int input){
    char power;
    short counter=0;
    int testVal=input;
    Primes *primes=new Primes;
    primes->nPrimes=0;
    
    for(short i=2;i<10000;i++){
        if(testVal%i==0){
            while(testVal%i==0){
                testVal/=i;
            }
            primes->nPrimes++;
        }
    }
    
    Prime *prime = new Prime[primes->nPrimes];
    primes->prime=prime;
    
    for(short i=2;i<10000;i++){
        power=0;
        if(input%i==0){
            while(input%i==0){
                input/=i;
                power++;
            }
            primes->prime[counter].prime=i;
            primes->prime[counter].power=power;
            counter++;
        }
    }   
    return primes;
}
void prntPrm(Primes *primes){
    for(char i=0;i<primes->nPrimes;i++){
        cout<<primes->prime[i].prime<<"^"<<short(primes->prime[i].power);
        if(i+1<primes->nPrimes){
            cout<<" * ";
        }
    }
}
