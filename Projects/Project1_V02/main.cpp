
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 10, 2021, 6:42 PM
 * Purpose: Project 1 Version 2, Main structure
 */

#include <iostream>     // for input/output
#include <iomanip>      // for output formatting
#include <ctime>        // for rand function
#include <fstream>      // for binary file read/write

using namespace std;

// Enums
enum bets{PLAYER=1,BANKER,TIE};
enum suit{CLUBS,DIAMONDS,HEARTS,SPADES};

// Structures
struct Round{
    short rndNum;
    short betType;
    Hand *player;
    Hand *banker;
    short result;
    string rsltStr;
};
struct Hand{
    string card1;
    short value1;
    string card2;
    short value2;
    bool hit=false;
    string card3;
    short value3;
};

// Function Prototypes
void prntPrior(ifstream);   // pull bin file data to print last run's result
short prompt(const short,const short);  // determine rounds to play
void playBaccarat(Round*);  // plays the game for a given round
void dealCard(Hand*);       // deal card
void prntRounds(Round*);    // print results
void binRounds(Round*,ofstream);    // save results to binary file
void memClear(Round*);      // deallocate memory
short valCheck(short,const short, const short);  // input validation

int main(int argc, char** argv)
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // declare file and vars
    ifstream in;
    ofstream out;
    
    // initialize vars
    char file[]="GameStats.bin";
    const short RNDMIN=1;
    const short RNDMAX=30;

    prntPrior(in);
    in.close();                             // close file input
    
    short rndNumb=prompt(RNDMIN,RNDMAX);
    Round *round=new Round[rndNumb];        // new rounds according to input
    Hand *player=new Hand[rndNumb];         // new player for rounds
    Hand *banker=new Hand[rndNumb];         // new banker for rounds
    
    for(short i=0;i<rndNumb;i++){
        round[i].player=player[i];          // assign pointers to rounds
        round[i].banker=banker[i];          // assign pointers to rounds
    }
    
    for(short i=0;i<rndNumb;i++){
        playBaccarat(round[i]);             // runs game until complete
    }
    
    prntRounds(round[]);
    binRounds(round[],out);
    out.close();
    memClear(round[]);                      // deallocate memory
    return 0;
}

void prntPrior(ifstream in){
    
}
short prompt(const short RNDMIN,const short RNDMAX){
    
}
void playBaccarat(Round*){
    
}
void dealCard(Hand*){
    
}
void prntRounds(Round*){
    
}
void binRounds(Round*){
    
}
void memClear(Round*){
    
}
short valCheck(short value,short low,short high){
    
}