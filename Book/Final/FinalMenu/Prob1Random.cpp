/* 
 * File:   Prob1Random.cpp
 * Author: Jason Handen
 * Created on June 3, 2021, 4:19 PM
 * Purpose: Problem 1 source file
 */

#include <cstdlib>
#include <ctime>

#include "Prob1Random.h"

Prob1Random::Prob1Random(const char n,const char *seq){
    srand(static_cast<unsigned int>(time(0)));
    numRand=0;
    nset=n;                         // assign number of vars in sequence
    set = new char[nset];           // set array for storage
    freq = new int[nset];           // frequency array
    
    for(short i=0;i<nset;i++){      // assign values over
        set[i]=seq[i];
    }
    for(short i=0;i<nset;i++){      // initialize to zero
        freq[i]=0;
    }
}
Prob1Random::~Prob1Random(){
    delete []set;
    delete []freq;
}
char Prob1Random::randFromSet(){
    numRand++;

    short index= rand()%nset;
    freq[index]++;
    return set[index];
}
int* Prob1Random::getFreq() const{
    return freq;
}
char* Prob1Random::getSet() const{
    return set;
}
int Prob1Random::getNumRand() const{
    return numRand;
}