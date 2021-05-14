
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 10, 2021, 8:24 PM
 * Purpose: Project 1 Version 4, Beginning game and member functions
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
    string card[3];
    short value[3];
    bool hit=false;
    short sum;
};

// Function Prototypes
void prntPrior(ifstream,char[]);// pull bin file data to print last run's result
short promptGame(const short,const short);  // determine rounds to play
void playBaccarat(Round*);      // plays the game for a given round
short promptBet(const short,const short);   // determine user bet
void dealCards(Hand*);          // deal cards (including extra) and sum
void writeCards(Hand*);         // write card name to string
void prntRound(Round*);         // print round
void prntResults(Round[]);       // print results
void binResults(Round[],ofstream);   // save results to binary file
void memClear(Round[],const short); // deallocate memory
short valCheck(short,const short, const short);  // input validation

int main(int argc, char** argv)
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // declare file and vars
    ifstream in;
    ofstream out;
    
    // initialize vars
    char results[]="GameResults.bin";
    //char runtime
    const short RNDMIN=1;
    const short RNDMAX=30;

    prntPrior(in,file[]);
    
    short rndNumb=prompt(RNDMIN,RNDMAX);
    Round *round=new Round[rndNumb];        // new rounds according to input
    Hand *player=new Hand[rndNumb];         // new player for rounds
    Hand *banker=new Hand[rndNumb];         // new banker for rounds
    
    for(short i=0;i<rndNumb;i++){
        round[i].player=player[i];          // assign pointers to rounds
        round[i].banker=banker[i];          // assign pointers to rounds
    }
    
    for(short i=0;i<rndNumb;i++){
        round[i].rndNum=i+1;
        playBaccarat(round[i]);             // runs game until complete
    }
    
    prntResults(round[]);
    binResults(round[],out);
    
    in.close();                             // close file input
    out.close();                            // close file output
    memClear(round[],rndNumb);              // deallocate memory
    return 0;
}

void prntPrior(ifstream in,char file[]){
    
}
short prompt(const short RNDMIN,const short RNDMAX){
    short rndNumb=0;
    cout<<"How many rounds of Bacarrat would you like to play: ";
    cin>>rndNumb;
    rndNumb=valCheck(rndNumb,RNDMIN,RNDMAX);
    return rndNumb;
}
void playBaccarat(Round* round){
    round->betType=promptBet(PLAYER,TIE);
    dealCards(round->player);
    dealCards(round->banker);
    round->player->sum=round->player->value[0]+round->player->value[1];
    if(round->player->sum>9){
        round->player->sum-=10;
    }
    round->banker->sum =round->banker->value[0] +round->banker->value[1];
    if(round->banker->sum>9){
        round->banker->sum-=10;
    }
    // checking baccarat rules
    // if either hand sum is 8 or 9, both hands stand
    if(round->banker->sum>7||round->player->sum>7){
        break;
    // if player's sum less than 6, draw third card, add to sum
    }else if(round->player->sum<6){
        round->player->hit=true;
        round->player->sum+=round->player->value[2];
        if(round->player->sum>9){
            round->player->sum-=10;
        }
        if(round->player->sum>7){
            break;
        }
    }
}
short promptBet(const short MIN,const short MAX){
    short bet;
    cout<<"Press 1 to bet on the player.\n"
        <<"Press 2 to bet on the banker.\n"
        <<"Press 3 to bet on a tie.\n"
        <<" Choice: ";
    cin>>bet;
    bet=valCheck(bet,MIN,MAX);
    return bet;
}
void dealCards(Hand *hand){
    for(short i=0;i<3;i++){
        hand->value[i]=rand()%52;   // value[2] only used if bool set to true
    }
    writeCards(hand);
}
void writeCards(Hand *hand){
    for(short i=0;i<3;i++){
        short suit=hand->value[i]/13;
        // determine card face
        hand->value[i]%=13;
        if(hand->value[i]==0){              // hand value of 0 is "Ace"
            hand->card[i]="Ace";            // value corrected below
        }else if(hand->value[i]==1){
            hand->card[i]="Two";
        }else if(hand->value[i]==2){
            hand->card[i]="Three";
        }else if(hand->value[i]==3){
            hand->card[i]="Four";
        }else if(hand->value[i]==4){
            hand->card[i]="Five";
        }else if(hand->value[i]==5){
            hand->card[i]="Six";
        }else if(hand->value[i]==6){
            hand->card[i]="Seven";
        }else if(hand->value[i]==7){
            hand->card[i]="Eight";
        }else if(hand->value[i]==8){
            hand->card[i]="Nine";
        }else if(hand->value[i]==9){
            hand->card[i]="10";
        }else if(hand->value[i]==10){
            hand->card[i]="Jack";
        }else if(hand->value[i]==11){
            hand->card[i]="Queen";
        }else if(hand->value[i]==12){
            hand->card[i]="King";
        }
        // set to proper value for summing later
        if(hand->value[i]>=0 && hand->value[i]<=8){
            hand->value[i]+=1;              // pip cards have face value
        }else{
            hand->value[i]=0;               // 10s and face cards value 0
        }
        // add " of " for formatting
        hand->card[i]+=" of ";
        // determine card suit and concatenate
        switch(suit){
            case CLUBS:hand->card[i]+="Clubs";break;
            case DIAMONDS:hand->card[i]+="Diamonds";break;
            case HEARTS:hand->card[i]+="Hearts";break;
            case SPADES:hand->card[i]+="Spades";break;
        }
    }
}
void prntRound(Round *round){
    
}
void prntResults(Round round[]){
    
}
void binResults(Round round[]){
    
}
void memClear(Round round[],const short rndNumb){
    for(short i=0;i<rndNumb;i++){
        delete round[i].player;
        delete round[i].banker;
    }
    delete round;
}
short valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}