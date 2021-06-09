
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 13, 2021, 1:21 PM
 * Purpose: Project 2 Version 9, Final
 * Line Count: 1081 including classes
 */

#include <iostream>     // for input/output
#include <iomanip>      // for output formatting
#include <ctime>        // for rand function
#include <fstream>      // for binary file read/write
#include <vector>       // for STL vector stuff

#include "Hand.h"
#include "Banker.h"
#include "Player.h"
#include "Round.h"
#include "Result.h"

using namespace std;

// Enums
enum bets{PLAYER=1,BANKER,TIE};

// Function Prototypes
Result& prntPrior(Result*,char[],char[],char[],ifstream&,ifstream&,ifstream&);  // pull bin file data to print
vector<char> promptName();                          // prompt user for his name
short promptGame(const short,const short);          // determine rounds to play
float promptMoney();                                // prompt user for starting money value
void playBaccarat(Player*,Banker*,Round*);          // plays the game for a given round
short promptBet(const short,const short);           // determine user bet
float promptBetAmnt(const float);                   // prompt for amount to bet
void adjust$(Player*,Round*);                       // adjusts money values
void prntRound(Player*,Banker*,Round*);             // print round
void setResult(Player*,Result*);                    // set up data in Result object
void prntPlayer(Player*,Result*);                   // print some player data
void prntResult(Result*,Result*);                   // print results
void binData(Player*,Result*,ofstream&,ofstream&,ofstream&,char[],char[],char[]);// save to binary file
void memClear(Player*,Banker*);                     // clean up memory allocations
int valCheck(int,const int, const int);     // input validation 1
float valCheck(float,const float, const float);     // input validation 2

int main(int argc, char** argv)
{
    // seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // declare file and vars
    ifstream inPlay;
    ifstream inRnd;
    ifstream inRes;
    ofstream outPlay;
    ofstream outRnd;
    ofstream outRes;
    
    // initialize vars
    char rounds[]="GameRounds.bin";
    char results[]="GameResults.bin";
    char play[]="PlayerName.txt";
    //char runtime
    const short RNDMIN=1;
    const short RNDMAX=20;

    Result temp;
    Result *tempPtr = &temp;

    // pull from binary file and print Result and Round information
    Result pastResult(prntPrior(tempPtr,rounds,results,play,inRnd,inRes,inPlay));
    Result *pastRes = &pastResult;

    // determine games to play
    vector<char> name=promptName();
    short rndNumb=promptGame(RNDMIN,RNDMAX);
    // (ROUND COUNT OUT OF RANGE) substitute input validation for exception class 
    try{
        // and create objects
        Result result(rndNumb);                 // Result object
        Result *res=&result;                    // Result pointer for functions
        Player *player = new Player;            // Player object
        Banker *banker = new Banker;            // Banker object

        player->setName(name);
        player->setFMoney(promptMoney());       // set first money
        result.setPlayerS$(player->getMoney()); // store in result object

        for(short i=0;i<result.getRndTot();i++){
            // replaced by static counter
            playBaccarat(player,banker,result.round+i); // runs game until complete
        }

        setResult(player,res);                      // set Result object w/ data
        prntPlayer(player,res);                     // print player name
        prntResult(res,pastRes);                    // print Result object parts
        binData(player,res,outRnd,outRes,outPlay,rounds,results,play);  // output to binary file

        memClear(player,banker);                    // memory cleanup

    }catch(Result::BadRoundCount){
        cout<<"Error: Invalid round count entered. Exiting program...\n\n";
        inPlay.close();                             // close file input
        inRes.close();                              // close file input
        inRnd.close();                              // close file input
        outPlay.close();                            // close file output
        outRes.close();                             // close file output
        outRnd.close();                             // close file outpu
        return 1;
    }

    inPlay.close();                             // close file input
    inRes.close();                              // close file input
    inRnd.close();                              // close file input
    outPlay.close();                            // close file output
    outRes.close();                             // close file output
    outRnd.close();                             // close file output

    return 0;
}

Result& prntPrior(Result *temp,char rounds[],char results[],char play[],
                                        ifstream &inRnd,ifstream &inRes,ifstream &inPlay){
    short response=0;
    //Result result;
    Player player;
    Banker banker;
    
    inPlay.open(play,ios::in);
    inRnd.open(rounds,ios::binary|ios::in);
    inRes.open(results,ios::binary|ios::in);
    
    if(!inRnd){
        cout<<"No Round file to open. This must be the first run!\n";
    }else if(!inPlay){
        cout<<"No Player file to open. This must be the first run!\n";
    }else if(!inRes){
        cout<<"No Result file to open. This must be the first run!\n";
    }else{
        short tempRnd,tempWin,tempLoss,leng;
        float tempS$,tempE$;
        // read string from PlayerName file
        string name, s;
        while(inPlay>>s){
            name+=s;
            name+=" ";
        }
        
        // read in values from Results file
        inRes.read((char*)&tempRnd,sizeof(short));
        inRes.read((char*)&tempWin,sizeof(short));
        inRes.read((char*)&tempLoss,sizeof(short));
        inRes.read((char*)&tempS$,sizeof(float));
        inRes.read((char*)&tempE$,sizeof(float));
        // assign values to object          
        temp->setRndTot(tempRnd);
        temp->setWins(tempWin);
        temp->setLosses(tempLoss);
        temp->setPlayerS$(tempS$);
        temp->setPlayerE$(tempE$);

        cout<<"Last player name: "<<name<<endl;
        cout<<"Round total for the last game played: "
                <<temp->getRndTot()<<endl;
        cout<<"Total wins for last game: "<<temp->getWins()<<endl;
        cout<<"Total losses for last game: "<<temp->getLosses()<<endl;
        cout<<"Starting Money: $"<<fixed<<setprecision(2)<<temp->getPlayerS$()<<endl;
        cout<<"  Ending Money: $"<<temp->getPlayerE$()<<endl<<endl;

        short rndNum,betType,res,sumB,sumP;
        float payout;
        do{
            inRnd.seekg(0);
            cout<<"Choose a round, 1-"<<temp->getRndTot()<<", or 0 (Zero) to exit: ";
            cin>>response;            
            response=valCheck(response,0,temp->getRndTot());

            for(short i=0;i<response;i++){
                inRnd.read((char*)&rndNum,sizeof(short));
                inRnd.read((char*)&betType,sizeof(short));
                inRnd.read((char*)&res,sizeof(short));
                inRnd.read((char*)&sumB,sizeof(short));
                inRnd.read((char*)&sumP,sizeof(short));
                inRnd.read((char*)&payout,sizeof(float));
            }
            if(response!=0){
                temp->round->setRndNum(rndNum);
                temp->round->setBetType(betType);
                temp->round->setResult(res);
                temp->round->setSumBnkr(sumB);
                temp->round->setSumPlyr(sumP);
                temp->round->setPayout(payout);

                cout<<"For Round #"<<temp->round->getRndNum()<<":\n";
                if(temp->round->getBetType()==PLAYER){
                    cout<<"Player bet with ";
                }else if(temp->round->getBetType()==BANKER){
                    cout<<"Banker bet with ";
                }else{
                    cout<<"Tie bet with ";
                }
                if(temp->round->getResult()==PLAYER){
                    cout<<"player win.\n";
                }else if(temp->round->getResult()==BANKER){
                    cout<<"banker win.\n";
                }else{
                    cout<<"tie game.\n";
                }
                cout<<"Player sum: "<<temp->round->getSumPlyr()<<endl;
                cout<<"Banker sum: "<<temp->round->getSumBnkr()<<endl;
                cout<<"Round payout: "<<fixed<<setprecision(2)
                                    <<temp->round->getPayout()<<" dollars\n\n";
            }
        }while(response!=0);
        cin.ignore();
    }

    return *(temp);
}
vector<char> promptName(){
    string temp;
    vector<char> name;
    cout<<"What is your name: ";
    
    getline(cin, temp);
    
    
    
    
    
    for(short i=0;i<temp.size();i++){
        name.push_back(temp[i]);
    }
    
    cout<<endl<<endl;
    cout<<"Hello, "<<temp<<"!"<<endl;
    return name;
}
short promptGame(const short RNDMIN,const short RNDMAX){
    short rndNumb=0;
    cout<<"How many rounds of Bacarrat would you like to play: ";
    cin>>rndNumb;
    // input validation canceled, exception handling for this case
    return rndNumb;
}
float promptMoney(){
    float money=0;
    cout<<"How much money will you start out with: ";
    cin>>money;
    // input validation at assignment for object
    return money;
}
/////////////////////////////////////////////////////////////////////////
void playBaccarat(Player *player,Banker *banker,Round *round){
    round->setBetType( promptBet(PLAYER,TIE) );
    cout<<"You have $"<<fixed<<setprecision(2)<<player->getMoney()<<endl;
    round->setBetAmnt( promptBetAmnt(player->getMoney()) );

    Hand *polyTest[]={player,banker};           // little polymorphism for show
    for(short i=0;i<2;i++){
        polyTest[i]->dealCards();
    }
    
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
    // set result based on sum comparisons
    if(player->getSum() > banker->getSum()){
        round->setResult(PLAYER);
    }else if(player->getSum() < banker->getSum()){
        round->setResult(BANKER);
    }else{
        round->setResult(TIE);
    }
    // round object assignments for later binary output
    round->setSumPlyr(player->getSum());
    round->setSumBnkr(banker->getSum());
    // print results of that round
    adjust$(player,round);
    prntRound(player,banker,round);                           
}
/////////////////////////////////////////////////////////////////////////
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
float promptBetAmnt(const float MAX){
    float bet;
    cout<<"How much would you like to bet: ";
    cin>>bet;
    bet=valCheck(bet,0.00,MAX);
    return bet;
}
void adjust$(Player *player,Round *round){
    if(round->getBetType() != round->getResult()){
        player->setMoney(*(player) - round->getBetAmnt());
        round->setPayout(-round->getBetAmnt());
    }else{
        if(round->getResult()==PLAYER){
            player->setMoney(*(player) + round->getBetAmnt());       // Player bet win doubles
            round->setPayout(2*round->getBetAmnt());
        }else if(round->getResult()==BANKER){
            player->setMoney(*(player) + round->getBetAmnt() * .95); // Banker bet win -commission
            round->setPayout(1.95*round->getBetAmnt());
        }else{
            player->setMoney(*(player) + round->getBetAmnt() * 7);   // Tie bet win 8 to 1 payout
            round->setPayout(8*round->getBetAmnt());
        }
    }
}
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
        cout<<"Won Bet, payout of $"<<fixed<<setprecision(2)
                                            <<round->getPayout()<<endl;
    }else if(round->getBetType()!=round->getResult()){
        cout<<"Lost Bet, at a cost of $"<<fixed<<setprecision(2)
                                            <<-round->getPayout()<<endl;
    }
    cout<<"New total money available: $"<<fixed<<setprecision(2)
                                            <<player->getMoney()<<endl;;
    cout<<"Press Enter to Continue... ";
    cin.ignore();
    cin.get();
}
void setResult(Player *player, Result *result){
    result->setPlayerE$(player->getMoney());        // set final money value

    for(short i=0;i<result->getRndTot();i++){
        if(result->round[i].getBetType()==result->round[i].getResult()){
            result->addWin();                       // total wins and store
        }else if(result->round[i].getBetType()!=result->round[i].getResult()){
            result->addLoss();                      // total losses and store
        }
    }
}
void prntPlayer(Player *player,Result *result){
    vector<char> temp=player->getName();

    cout<<"\n\nPlayer name: ";
    for(short i=0;i<temp.size();i++){
        cout<<temp[i];
    }
    cout<<endl;
    
    cout<<"Average payout: "<<*(player)/result->getRndTot()<<endl;
}
void prntResult(Result *result,Result* pastRes){
    float avg, pastAvg;
    cout<<"\nTotal Rounds: "<<result->getRndTot()<<endl;
    cout<<"Won bets: "<<result->getWins()<<endl;
    cout<<"Lost bets: "<<result->getLosses()<<endl;
    cout<<"Starting Money: $"<<fixed<<setprecision(2)<<result->getPlayerS$()<<endl;
    cout<<"Ending Money: $"<<result->getPlayerE$()<<endl;
    
    if(pastRes->getRndTot()!=0){
        cout<<"---Compared with the prior game---\n";

        cout<<"Total Rounds: "<<pastRes->getRndTot()<<endl;
        cout<<"Won bets: "<<pastRes->getWins()<<endl;
        cout<<"Lost bets: "<<pastRes->getLosses()<<endl;
        cout<<"Starting Money: $"<<fixed<<setprecision(2)<<pastRes->getPlayerS$()<<endl;
        cout<<"Ending Money: $"<<pastRes->getPlayerE$()<<endl<<endl;
    }
    
}
void binData(Player *player,Result *result,ofstream &outRnd,ofstream &outRes,ofstream &outPlay,
                                                        char rounds[],char results[],char play[]){
    
    vector<char> temp=player->getName();
    short leng=temp.size();
    char output[leng];
    for(short i=0;i<leng;i++){
        output[i]=temp[i];
    }
    outPlay.open(play,ios::out);
    //outPlay.write((char*)&leng,sizeof(short));
    for(short i=0;i<leng;i++){
        outPlay<<temp[i];
    }
    
    outRes.open(results,ios::binary|ios::out);
    short tempTot=result->getRndTot();
    short tempWins=result->getWins();
    short tempLosses=result->getLosses();
    float tempS$=result->getPlayerS$();
    float tempE$=result->getPlayerE$();

    outRes.write((char*)&tempTot,sizeof(short));
    outRes.write((char*)&tempWins,sizeof(short));
    outRes.write((char*)&tempLosses,sizeof(short));
    outRes.write((char*)&tempS$,sizeof(float));
    outRes.write((char*)&tempE$,sizeof(float));
    
    // temporary variables for assignment and binary output
    short tempRndNum,tempBetType,tempResult,tempSumB,tempSumP;
    float tempPayout;
    
    outRnd.open(rounds,ios::binary|ios::out);
    for(short i=0;i<tempTot;i++){
        // temp variable assignment
        tempRndNum=result->round[i].getRndNum();
        tempBetType=result->round[i].getBetType();
        tempResult=result->round[i].getResult();
        tempSumB=result->round[i].getSumBnkr();
        tempSumP=result->round[i].getSumPlyr();
        tempPayout=result->round[i].getPayout();
        // file output using temp variables
        outRnd.write((char*)&tempRndNum,sizeof(short));
        outRnd.write((char*)&tempBetType,sizeof(short));
        outRnd.write((char*)&tempResult,sizeof(short));
        outRnd.write((char*)&tempSumB,sizeof(short));
        outRnd.write((char*)&tempSumP,sizeof(short));
        outRnd.write((char*)&tempPayout,sizeof(float));
    }
}
void memClear(Player *player,Banker *banker){
    delete player;
    delete banker;
}
int valCheck(int value,const int MIN,const int MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}
float valCheck(float value,const float MIN,const float MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}