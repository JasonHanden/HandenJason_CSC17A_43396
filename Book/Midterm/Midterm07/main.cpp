
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
    char counter=0;
    Primes *primes=new Primes;
    Prime *prime = new Prime[7];
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
    primes->nPrimes=counter;
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
