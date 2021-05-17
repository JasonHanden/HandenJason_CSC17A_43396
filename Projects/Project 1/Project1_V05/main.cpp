
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 11, 2021, 3:47 PM
 * Purpose: Project 1 Version 5, Functional program
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
struct Hand{
    string card[3];
    short value[3];
    bool natural=false;
    bool hit=false;
    short sum;
};
struct Round{
    short rndNum;
    short betType;
    Hand *player;
    Hand *banker;
    short result;
    string rsltStr;
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
void memClear(Round*,const short); // deallocate memory
short valCheck(short,const short, const short);  // input validation

int main(int argc, char** argv)
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // declare file and vars
    //ifstream in;
    //ofstream out;
    
    // initialize vars
    char results[]="GameResults.bin";
    //char runtime
    const short RNDMIN=1;
    const short RNDMAX=30;

    //prntPrior(in,file);
    
    short rndNumb=promptGame(RNDMIN,RNDMAX);
    Round *round=new Round[rndNumb];        // new rounds according to input
    
    for(short i=0;i<rndNumb;i++){
        Hand *player=new Hand;
        round[i].player=player;                 // assign pointers to rounds  
        Hand *banker=new Hand;
        round[i].banker=banker;                 // assign pointers to rounds
    }
    
    for(short i=0;i<rndNumb;i++){
        round[i].rndNum=i+1;
        playBaccarat(round+i);             // runs game until complete
    }
    
    //prntResults(round[]);
    //binResults(round[],out);
    
    //in.close();                             // close file input
    //out.close();                            // close file output
    memClear(round,rndNumb);              // deallocate memory
    return 0;
}

void prntPrior(ifstream in,char file[]){
    
}
short promptGame(const short RNDMIN,const short RNDMAX){
    short rndNumb=0;
    cout<<"How many rounds of Bacarrat would you like to play: ";
    cin>>rndNumb;
    rndNumb=valCheck(rndNumb,RNDMIN,RNDMAX);
    return rndNumb;
}
void playBaccarat(Round *round){
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
    if(round->banker->sum>7){
        round->banker->natural=true;
    }else{
        round->banker->natural=false;
    }
    if(round->player->sum>7){
        round->player->natural=true;
    }else{
        round->player->natural=false;
    }
    // if player's sum less than 6, draw third card, add to sum
    if(round->player->natural==false&&round->banker->natural==false){

        if(round->player->sum<6){
            round->player->hit=true;
            round->player->sum+=round->player->value[2];
            if(round->player->sum>9){
                round->player->sum-=10;
            }
        }
    }
    // run through banker conditions for drawing
    if(round->player->natural==false&&round->banker->natural==false){
        if(round->player->hit==false&&round->banker->sum<6){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }else if(round->player->hit==false&&round->banker->sum>5){
            // banker stands
        }else if(round->banker->sum<3){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }else if(round->player->hit==true&&round->banker->sum==3
                &&round->player->value[2]!=8){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }else if(round->player->hit==true&&round->banker->sum==4
                &&round->player->value[2]>1&&round->player->value[2]<8){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }else if(round->player->hit==true&&round->banker->sum==5
                &&round->player->value[2]>3&&round->player->value[2]<8){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }else if(round->player->hit==true&&round->banker->sum==6
                &&round->player->value[2]>5&&round->player->value[2]<8){
            round->banker->hit=true;
            round->banker->sum+=round->banker->value[2];
            if(round->banker->sum>9){
                round->banker->sum-=10;
            }
        }
    }
    if(round->player->sum > round->banker->sum){
        round->result=PLAYER;
        round->rsltStr="PLAYER WON.";
    }else if(round->player->sum < round->banker->sum){
        round->result=BANKER;
        round->rsltStr="BANKER WON.";
    }else{
        round->result=TIE;
        round->rsltStr="IT'S A TIE.";
    }
    prntRound(round);           // print results of that round
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
            hand->card[i]="Ten";
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
    const short WIDTH=25;
    
    cout<<"*****\n";
    cout<<setw(WIDTH)<<left<<"Player"<<setw(WIDTH)<<"Banker"<<endl;
    cout<<setw(WIDTH)<<left<<round->player->card[0]
            <<setw(WIDTH)<<left<<round->banker->card[0]<<endl;
    cout<<setw(WIDTH)<<left<<round->player->card[1]
            <<setw(WIDTH)<<left<<round->banker->card[1]<<endl;
    
    if(round->player->hit==true){
        cout<<setw(WIDTH)<<left<<round->player->card[2];
        if(round->banker->hit==true){
            cout<<setw(WIDTH)<<left<<round->banker->card[2];
        }
        cout<<endl;
    }else if(round->banker->hit==true){
        cout<<setw(WIDTH)<<" "<<setw(WIDTH)<<left<<round->banker->card[2]<<endl;
    }
    
    cout<<setw(WIDTH-5)<<left<<"Sum: "<<round->player->sum<<"    "
            <<setw(WIDTH-5)<<left<<"Sum: "<<round->banker->sum<<endl;
    if(round->player->sum>round->banker->sum){
        cout<<setw(WIDTH)<<left<<"WINNER"<<endl;
    }else if(round->player->sum<round->banker->sum){
        cout<<setw(WIDTH)<<"  "<<setw(WIDTH)<<left<<"WINNER"<<endl;
    }else{
        cout<<setw(WIDTH)<<left<<"TIE"<<setw(WIDTH)<<left<<"TIE"<<endl;
    }
    if(round->betType==round->result){
        cout<<"  Won Bet!\n";
    }else if(round->betType!=round->result){
        cout<<"  Lost Bet!\n";
    }
    cout<<"Press Enter to Continue... ";
    cin.ignore();
    cin.get();
}
void prntResults(Round round[]){
    
}
void binResults(Round round[]){
    
}
void memClear(Round *round,const short rndNumb){
    for(short i=0;i<rndNumb;i++){
        delete round[i].player;
        delete round[i].banker;
    }
    delete []round;
}
short valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}