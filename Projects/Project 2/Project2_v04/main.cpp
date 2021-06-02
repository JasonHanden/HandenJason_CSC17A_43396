
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 13, 2021, 1:21 PM
 * Purpose: Project 2 Version 4, Fixing up functions
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
void playBaccarat(Player*,Banker*,Round*);            // plays the game for a given round
short promptBet(const short,const short);           // determine user bet

//float promptBetAmnt();                            // prompt for amount to bet

//void dealCards(Hand*);                            // deal cards (including extra) and sum
//void writeCards(Hand*);                           // write card name to string
void prntRound(Player*,Banker*,Round*);               // print round
void setResult(Result*);                             // set up data in Result object
void prntResult(Result*);                            // print results
void binData(Result*,ofstream&,ofstream&,char[],char[]);// save to binary file
void memClear(Player*,Banker*);
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
    Result *res=&result;
    Player *player = new Player;
    Banker *banker = new Banker;
    /*
    for(short i=0;i<rndNumb;i++){
        Hand *player=new Hand;
        round[i].player=player;                 // assign pointers to rounds  
        Hand *banker=new Hand;
        round[i].banker=banker;                 // assign pointers to rounds
    }
    */

    cout<<result.getRndTot()<<endl;

    for(short i=0;i<result.getRndTot();i++){
        //cout<<"Start of loop #"<<i<<endl;
        result.round[i].setRndNum(i+1);
        playBaccarat(player,banker,result.round+i);                  // runs game until complete
        cout<<"End of loop ";
    }
    
    cout<<"Out of FOR loop";

    setResult(res);

    prntResult(res);
    binData(res,outRnd,outRes,rounds,results);
    
    inRes.close();                              // close file input
    inRnd.close();                              // close file input
    outRes.close();                             // close file output
    outRnd.close();                             // close file output



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
void playBaccarat(Player *player,Banker *banker,Round *round){
    round->setBetType( 1 );
    
    //promptBet(PLAYER,TIE) );
    //round->setBetAmnt( promptBetAmnt() );
    player->dealCards();
    banker->dealCards();
    
    // if player's sum less than 6, draw third card, add to sum
    if(player->getNatural()==false&&banker->getNatural()==false){
        if(player->getSum()<6){
            player->drawThird();
        }
    }
    
    // run through banker conditions for drawing
    if(player->getNatural()==false&&banker->getNatural()==false){
        if(player->getHit()==false&&banker->getSum()<6){
            banker->trueHit();
        }else if(player->getHit()==false&&banker->getSum()>5){
            // banker stands
        }else if(banker->getSum()<3){
            banker->trueHit();
        }else if(player->getHit()==true&&banker->getSum()==3
                &&player->getValue(2)!=8){
            banker->trueHit();
        }else if(player->getHit()==true&&banker->getSum()==4
                &&player->getValue(2)>1&&player->getValue(2)<8){
            banker->trueHit();
        }else if(player->getHit()==true&&banker->getSum()==5
                &&player->getValue(2)>3&&player->getValue(2)<8){
            banker->trueHit();
        }else if(player->getHit()==true&&banker->getSum()==6
                &&player->getValue(2)>5&&player->getValue(2)<8){
            banker->trueHit();
        }
    }
    if(player->getSum() > banker->getSum()){
        round->setResult(PLAYER);
    }else if(player->getSum() < banker->getSum()){
        round->setResult(BANKER);
    }else{
        round->setResult(TIE);
    }

    prntRound(player,banker,round);                           // print results of that round

    cout<<"Back to playBaccarat\n";
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
float promptBetAmnt(){

}
*/

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
void prntRound(Player *player,Banker *banker,Round *round){
    const short WIDTH=25;
    
    cout<<"*****\n";
    cout<<setw(WIDTH)<<left<<"Player"<<setw(WIDTH)<<"Banker"<<endl;
    cout<<setw(WIDTH)<<left<<player->getCard(0)
            <<setw(WIDTH)<<left<<banker->getCard(0)<<endl;
    cout<<setw(WIDTH)<<left<<player->getCard(1)
            <<setw(WIDTH)<<left<<banker->getCard(1)<<endl;

    if(player->getHit()==true){
        cout<<setw(WIDTH)<<left<<player->getCard(2);
        if(banker->getHit()==true){
            cout<<setw(WIDTH)<<left<<banker->getCard(2);
        }
        cout<<endl;
    }else if(banker->getHit()==true){
        cout<<setw(WIDTH)<<" "<<setw(WIDTH)<<left<<banker->getCard(2)<<endl;
    }
    
    cout<<setw(WIDTH-5)<<left<<"Sum: "<<player->getSum()<<"    "
            <<setw(WIDTH-5)<<left<<"Sum: "<<banker->getSum()<<endl;
    if(player->getSum() > banker->getSum()){
        cout<<setw(WIDTH)<<left<<"WINNER"<<endl;
    }else if(player->getSum() < banker->getSum()){
        cout<<setw(WIDTH)<<"  "<<setw(WIDTH)<<left<<"WINNER"<<endl;
    }else{
        cout<<setw(WIDTH)<<left<<"TIE"<<setw(WIDTH)<<left<<"TIE"<<endl;
    }
    if(round->getBetType()==round->getResult()){
        cout<<"  Won Bet!\n";
    }else if(round->getBetType()!=round->getResult()){
        cout<<"  Lost Bet!\n";
    }
    cout<<"Press Enter to Continue... ";
    cin.ignore();
    cin.get();

    cout<<"After CIN.GET and all\n";
}
void setResult(Result *result){
    for(short i=0;i<result->getRndTot();i++){
        if(result->round[i].getBetType()==result->round[i].getResult()){
            result->addWin();
        }else if(result->round[i].getBetType()!=result->round[i].getResult()){
            result->addLoss();
        }
    }
}
void prntResult(Result *result){
    cout<<"\n\nTotal Rounds: "<<result->getRndTot()<<endl;
    cout<<"Won bets: "<<result->getWins()<<endl;
    cout<<"Lost bets: "<<result->getLosses()<<endl;
}
void binData(Result *result,ofstream &outRnd, ofstream &outRes,
        char rounds[],char results[]){
    outRes.open(results,ios::binary|ios::out);

    short tempTot=result->getRndTot();
    short tempWins=result->getWins();
    short tempLosses=result->getLosses();

    outRes.write((char*)&tempTot,sizeof(short));
    outRes.write((char*)&tempWins,sizeof(short));
    outRes.write((char*)&tempLosses,sizeof(short));
    
    short tempRndNum,tempBetType,tempResult,tempSumB,tempSumP;


    outRnd.open(rounds,ios::binary|ios::out);
    for(short i=0;i<result->getRndTot();i++){
        tempRndNum=result->round[i].getRndNum();
        tempBetType=result->round[i].getBetType();
        tempResult=result->round[i].getResult();
        tempSumB=result->round[i].getSumBnkr();
        tempSumP=result->round[i].getSumPlyr();

        outRnd.write((char*)&tempRndNum,sizeof(short));
        outRnd.write((char*)&tempBetType,sizeof(short));
        outRnd.write((char*)&tempResult,sizeof(short));
        outRnd.write((char*)&tempSumB,sizeof(short));
        outRnd.write((char*)&tempSumP,sizeof(short));
    }
}
void memClear(Player *player,Banker *banker){
    
    delete player;
    delete banker;
}
short valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}