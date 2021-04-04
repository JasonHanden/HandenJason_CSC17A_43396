
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 7:22 PM
 * Purpose: Structure Testing
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
struct Drink{
    string name;
    float cost;
    short numRem;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
string prompt(Drink[]);
short calc(Drink[],string);
short check(short);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    bool escape=false;
    short profit=0;
    
    //Initialize Variables
    Drink drinks[5];
    drinks[0].name="Cola";
    drinks[1].name="Root Beer";
    drinks[2].name="Lemon-Lime";
    drinks[3].name="Grape Soda";
    drinks[4].name="Cream Soda";
    for(char i=0;i<3;i++){
        drinks[i].cost=0.75;
    }
    for(char i=3;i<5;i++){
        drinks[i].cost=0.80;
    }
    for(char i=0;i<5;i++){
        drinks[i].numRem=20;
    }
    
    //Process or map Inputs to Outputs
    do{
        string response=prompt(drinks);
        if(response=="Quit"){
            escape=true;
            break;
        }else{
            profit+=calc(drinks,response);
        }
    //Display Outputs
    }while(escape==false);
    
    cout<<profit<<endl;
    
    //Exit stage right!
    return 0;
}

string prompt(Drink drinks[]){
    string response;
    for(char i=0;i<5;i++){
        cout<<setw(11)<<left<<drinks[i].name<<short(drinks[i].cost*100)
                <<setw(4)<<right<<drinks[i].numRem<<endl;
    }
    cout<<"Quit"<<endl;
    
    getline(cin,response);
    return response;
}
short calc(Drink drinks[],string response){
    short paid=0;
    cin>>paid;
    cin.ignore();
    paid=check(paid);
    
    bool match=false;
    short index=-1;
    for(char i=0;i<5;i++){
        if(response==drinks[i].name){
            index=i;
            break;
        }
    }
    if(drinks[index].cost>paid){
        cout<<"Not enough paid. Exiting...\n";
        return 0;
    }else{
        drinks[index].numRem-=1;
        cout<<paid-short(drinks[index].cost*100)<<endl;
    }
    return short(drinks[index].cost*100);
}
short check(short value){
    bool ready;
    if(value<0||value>100){
        ready=false;
    }else{
        ready=true;
    }
    while(ready==false){
        cout<<"Enter new value:";
        cin>>value;
        if(value<0||value>100){
            ready=false;
        }else{
            ready=true;
        }
    }
    return value;
}