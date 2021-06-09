/* 
 * File:   SavingsAccount.cpp
 * Author: Jason Handen
 * Created on June 6, 2021, 8:57 PM
 * Purpose: Savings Account source file
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

static float SavingsRecursive=0;

SavingsAccount::SavingsAccount(float st$){
    if(st$<0){
        Balance=st$;
        SavingsRecursive=Balance;
    }else{
        Balance=0;
    }
    FreqWithDraw=0;
    FreqDeposit=0;
}
void  SavingsAccount::Transaction(float m){
    if(m>0){
        Balance+=SavingsAccount::Deposit(m);
        FreqDeposit++;
    }else{
        Balance+=SavingsAccount::Withdraw(m);
        FreqWithDraw++;
    }
    SavingsRecursive=Balance;
}
float SavingsAccount::Total(float savint,int time){
    float amnt=Balance;
    for(int i=0;i<time;i++){
        amnt*=(1+savint);
    }
    return amnt;
}
float SavingsAccount::TotalRecursive(float savint,int time){
    if(time==0){
        return SavingsRecursive;
    }else{
        SavingsRecursive*=(1+savint);
        time--;
        SavingsAccount::TotalRecursive(savint,time);
    }
}
void  SavingsAccount::toString(){
    cout<<"Balance="<<Balance<<endl;
    cout<<"WithDraws="<<FreqWithDraw<<endl;
    cout<<"Deposits="<<FreqDeposit<<endl;
}

float SavingsAccount::Withdraw(float value){
    if(value>Balance){
        cout<<"WithDraw not Allowed\n";
        return 0;
    }else{
        return -value;
    }
}
float SavingsAccount::Deposit(float value){
    return value;
}