
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 24, 2021, 7:23 PM
 * Purpose: Checking Account1 Balance
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Account1{
    string name;
    string address;
    char accNumb[6]={0,0,0,0,0,0};
    float begBal=0;
    float chckOut=0;
    float *eachChk;
    float deposIn=0;
    float *eachDep;
};

void input(Account1*);
float balanceCalc(Account1*);
float overdraw(float);
void output(Account1*,float);
void accNumbCheck(char[]);

int main(int argc, char** argv) {

    float balance;
    Account1 *account1=new Account1;
    
    input(account1);
    balance=balanceCalc(account1);
    output(account1,balance);

    delete account1->eachChk;
    delete account1->eachDep;
    delete account1;
    return 0;
}

void input(Account1 *account1){
    float temp=0;
    short size=0;
    
    cout<<"Please enter your name: ";
    getline(cin,account1->name);
    
    cout<<"Please enter your address: ";
    getline(cin,account1->address); 
    
    cout<<"Please enter your account number: ";
    cin>>account1->accNumb;
    accNumbCheck(account1->accNumb);
    
    cout<<"Please enter the account balance at the beginning of the month: ";
    cin>>account1->begBal;
    
    cout<<"Please enter the number of checks written out this month: ";
    cin>>size;
    float *eachChk=new float[size];
    account1->eachChk=eachChk;
    
    for(short i=0;i<size;i++){
        cout<<"Enter Check #"<<i+1<<": $";
        cin>>account1->eachChk[i];
        account1->chckOut+=account1->eachChk[i];
    }
    
    cout<<"Please enter the number of deposits this month: ";
    cin>>size;
    float *eachDep=new float[size];
    account1->eachDep=eachDep;
    
    for(short i=0;i<size;i++){
        cout<<"Enter Deposit #"<<i+1<<": $";
        cin>>account1->eachDep[i];
        account1->deposIn+=account1->eachDep[i];
    }
    
}
float balanceCalc(Account1 *account1){
    float balance=account1->begBal;
    balance+=account1->deposIn;
    balance-=account1->chckOut;
    cout<<"Current balance: "<<fixed<<setprecision(2)<<balance<<" dollars.\n";
    if( int(balance*100)<0 ){
        balance=overdraw(balance);
    }
    return balance;
}
float overdraw(float balance){
    cout<<"It looks like your account has been overdrawn!\n"
        <<"A $20 fee is being added...\n";
    balance-=20;
    cout<<"Balance updated to: "<<fixed<<setprecision(2)<<balance<<" dollars.\n";
    return balance;
}
void output(Account1 *account1,float balance){
    cout<<"Account information:\n"
        <<"Name: "<<account1->name<<endl
        <<"Address: "<<account1->address<<endl
        <<"Account Number: "<<account1->accNumb<<endl
        <<"Account Balance at Month Beginning: "<<fixed<<setprecision(2)<<account1->begBal<<" dollars.\n"
        <<"Total of Checks Written: "<<account1->chckOut<<" dollars.\n"
        <<"Total Account Deposits: "<<account1->deposIn<<" dollars.\n"
        <<"Current Account Balance (including fees): "<<balance<<" dollars.\n";
}
void accNumbCheck(char accNumb[]){
    bool numbs,length;

    do{
        numbs=true; length=true;
        
        if(accNumb[5]!=0){
            length=false;
        }
        for(char i=0;i<5;i++){
            if(accNumb[i]<=47||accNumb[i]>=58){
                numbs=false;
            }
        }
        if(numbs==false||length==false){
            for(char i=0;i<6;i++){
                accNumb[i]=0;
            }
            cout<<"Please enter a valid 5-digit account number: ";
            cin>>accNumb;
        }
    }while(numbs==false||length==false);
}