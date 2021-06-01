
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 13, 2021, 1:21 PM
 * Purpose: Project 2 Version 3, Working on Result class, prntPrior and makeResults corrections
 */

#include <iostream>     // for input/output
#include <iomanip>      // for output formatting
#include <ctime>        // for rand function
#include <fstream>      // for binary file read/write

#include "Hand.h"
#include "Banker.h"
#include "Player.h"
#include "Round.h"
#include "Result.h"

using namespace std;

// Enums
enum bets{PLAYER=1,BANKER,TIE};
//enum suit{CLUBS,DIAMONDS,HEARTS,SPADES};

// Structures
/*
struct Hand{
    string card[3];
    short value[3];
    bool natural=false;
    bool hit=false;
    short sum;
};
*/
/*
struct Round{
    short rndNum;
    short betType;
    Hand *player;
    Hand *banker;
    short result;
};
*/
/*
struct Result{
    short rndTot;
    short wins=0;
    short losses=0;
};
*/
// Function Prototypes
void prntPrior(char[],char[],ifstream&,ifstream&);// pull bin file data to print
short promptGame(const short,const short);          // determine rounds to play
void playBaccarat(Player,Banker,Round*);            // plays the game for a given round
short promptBet(const short,const short);           // determine user bet
void dealCards(Hand*);                  // deal cards (including extra) and sum
void writeCards(Hand*);                             // write card name to string
void prntRound(Round*);                             // print round
void makeResult(Result);             // make Result struct
void prntResult(Result*);                   // print results
void binData(Round[],Result*,ofstream&,ofstream&,char[],char[]);// save to binary file
void memClear(Round*,Result*);                      // deallocate memory
short valCheck(short,const short, const short);     // input validation

int main(int argc, char** argv)
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // declare file and vars
    ifstream inRnd;
    ifstream inRes;
    ofstream outRnd;
    ofstream outRes;
    
    // initialize vars
    char rounds[]="GameRounds.bin";
    char results[]="GameResults.bin";
    //char runtime
    const short RNDMIN=1;
    const short RNDMAX=20;

    prntPrior(rounds,results,inRnd,inRes);
    
    short rndNumb=promptGame(RNDMIN,RNDMAX);
    Result result(rndNumb);
    Player player;
    Banker banker;
    /*
    for(short i=0;i<rndNumb;i++){
        Hand *player=new Hand;
        round[i].player=player;                 // assign pointers to rounds  
        Hand *banker=new Hand;
        round[i].banker=banker;                 // assign pointers to rounds
    }
    */

    for(short i=0;i<rndNumb;i++){
        result.round->setRndNum(i+1);
        playBaccarat(player,banker,result.round+i);                  // runs game until complete
    }
    
    makeResult(result);

    prntResult(result);
    binData(round,result,outRnd,outRes,rounds,results);
    
    inRes.close();                              // close file input
    inRnd.close();                              // close file input
    outRes.close();                             // close file output
    outRnd.close();                             // close file output
    memClear(round,result);                     // deallocate memory
    return 0;
}

void prntPrior(char rounds[],char results[],ifstream &inRnd,ifstream &inRes){
    short response=0;
    Result result;
    Player player;
    Banker banker;
    
    inRnd.open(rounds,ios::binary|ios::in);
    inRes.open(results,ios::binary|ios::in);
    
    if(!inRnd){
        cout<<"No Round file to open. This must be the first run!\n";
    }else if(!inRes){
        cout<<"No Result file to open. This must be the first run!\n";
    }else{
        short tempRnd,tempWin,tempLoss;
        // read in values from file
        inRes.read((char*)&tempRnd,sizeof(short));
        inRes.read((char*)&tempWin,sizeof(short));
        inRes.read((char*)&tempLoss,sizeof(short));
        // assign values to object
        result.setRndTot(tempRnd);
        result.setWins(tempWin);
        result.setLosses(tempLoss);

        cout<<"This was the round total for the last game played: "
                <<result.getRndTot()<<endl;
        cout<<"Total wins for last game: "<<result.getWins()<<endl;
        cout<<"Total losses for last game: "<<result.getLosses()<<endl<<endl;
        
        do{
            inRnd.seekg(0);
            cout<<"Choose a round, 1-"<<result.getRndTot()<<", or 0 (Zero) to exit: ";
            cin>>response;
            
            
            
            // Check for exception application
            response=valCheck(response,0,result.getRndTot());
            



            short rndNum,betType,res,sumB,sumP;
            for(short i=0;i<response;i++){
                inRnd.read((char*)&rndNum,sizeof(short));
                inRnd.read((char*)&betType,sizeof(short));
                inRnd.read((char*)&res,sizeof(short));
                inRnd.read((char*)&sumB,sizeof(short));
                inRnd.read((char*)&sumP,sizeof(short));
            }
            if(response!=0){
                result.round->setRndNum(rndNum);
                result.round->setBetType(betType);
                result.round->setResult(res);
                result.round->setSumBnkr(sumB);
                result.round->setSumPlyr(sumP);

                cout<<"For Round #"<<result.round->getRndNum()<<":\n";
                if(result.round->getBetType()==PLAYER){
                    cout<<"Player bet with ";
                }else if(result.round->getBetType()==BANKER){
                    cout<<"Banker bet with ";
                }else{
                    cout<<"Tie bet with ";
                }
                if(result.round->getResult()==PLAYER){
                    cout<<"player win.\n";
                }else if(result.round->getResult()==BANKER){
                    cout<<"banker win.\n";
                }else{
                    cout<<"tie game.\n";
                }
                cout<<"Player sum: "<<result.round->getSumPlyr()<<endl;
                cout<<"Banker sum: "<<result.round->getSumBnkr()<<endl<<endl;
            }
        }while(response!=0);
    }
}
short promptGame(const short RNDMIN,const short RNDMAX){
    short rndNumb=0;
    cout<<"\nHow many rounds of Bacarrat would you like to play: ";
    cin>>rndNumb;
    
    return rndNumb;
}
void playBaccarat(Player player,Banker banker,Round *round){
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
    }else if(round->player->sum < round->banker->sum){
        round->result=BANKER;
    }else{
        round->result=TIE;
    }
    prntRound(round);                           // print results of that round
}
short promptBet(const short MIN,const short MAX){
    short bet;
    cout<<"\nPress 1 to bet on the player.\n"
        <<"Press 2 to bet on the banker.\n"
        <<"Press 3 to bet on a tie.\n"
        <<" Choice: ";
    cin>>bet;
    bet=valCheck(bet,MIN,MAX);
    return bet;
}
/*
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
        if(hand->value[i]==0){                  // hand value of 0 is "Ace"
            hand->card[i]="Ace";                // value corrected below
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
            hand->value[i]+=1;                  // pip cards have face value
        }else{
            hand->value[i]=0;                   // 10s and face cards value 0
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
*/
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
void makeResult(Result result){
    for(short i=0;i<result.getRndTot();i++){
        if(result.round[i].getBetType()==result.round[i].getResult()){
            result.addWin();
        }else if(result.round[i].getBetType()!=result.round[i].getResult()){
            result.addLoss();
        }
    }
}
void prntResult(Result *result){
    cout<<"\n\nTotal Rounds: "<<result->rndTot<<endl;
    cout<<"Won bets: "<<result->wins<<endl;
    cout<<"Lost bets: "<<result->losses<<endl;
}
void binData(Round round[],Result *result,ofstream &outRnd, ofstream &outRes,
        char rounds[],char results[]){
    outRes.open(results,ios::binary|ios::out);

    outRes.write((char*)&result->rndTot,sizeof(short));
    outRes.write((char*)&result->wins,sizeof(short));
    outRes.write((char*)&result->losses,sizeof(short));
    
    outRnd.open(rounds,ios::binary|ios::out);
    for(short i=0;i<result->rndTot;i++){
        outRnd.write((char*)&round[i].rndNum,sizeof(short));
        outRnd.write((char*)&round[i].betType,sizeof(short));
        outRnd.write((char*)&round[i].result,sizeof(short));
        outRnd.write((char*)&round[i].banker->sum,sizeof(short));
        outRnd.write((char*)&round[i].player->sum,sizeof(short));
    }
}
void memClear(Round *round,Result *result){
    for(short i=0;i<result->rndTot;i++){
        delete round[i].player;
        delete round[i].banker;
    }
    delete []round;
    delete result;
}
short valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}