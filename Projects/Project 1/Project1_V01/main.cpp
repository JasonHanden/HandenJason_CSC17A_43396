
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 8, 2021, 7:28 PM
 * Purpose: Project 1 Version 1, Outline
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
short prompt();             // determine rounds to play
void playBaccarat(Round*);  // plays the game for a given round
void dealCard(Hand*);       // deal card
void prntRounds(Round*);    // print results
void binRounds(Round*);     // save results to binary file
void memClear(Round*);      // deallocate memory
short valCheck(short,short,short);  // input validation

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(0)));
    
    
    return 0;
}

void prntPrior(ifstream in){
    
}
short prompt(){
    
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