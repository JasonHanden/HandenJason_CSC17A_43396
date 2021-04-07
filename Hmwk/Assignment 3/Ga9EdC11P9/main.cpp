
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 4, 2021, 12:26 PM
 * Purpose: Store Speaker Data
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Speaker{
    string name="none";
    string tele="0000000000";
    string topic="none";
    float fee=0.00;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bool menu(Speaker[],const short);
Speaker edit(Speaker);
void print(Speaker[],const short);

string check(string);
float check(float);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const short SIZE=10;
    bool escape=false;
    //Initialize Variables
    Speaker data[SIZE];
    //Process or map Inputs to Outputs
    do{
        escape=menu(data,SIZE);
    }while(escape==false);
    //Display Outputs
    
    //Exit stage right!
    return 0;
}

bool menu(Speaker data[],const short SIZE){
    short response;
    cout<<"Enter 0-9 to edit those elements.\n";
    cout<<"Enter 10 to print.\n";
    cout<<"Enter -1 exit the program.\n";
    cin>>response;
    while(response<-1||response>10){
        cout<<"Please enter a valid choice:";
        cin>>response;
    }
    if(response==-1){
        return true;
    }else if(response==10){
        print(data,SIZE);
    }else{
        data[response]=edit(data[response]);
    }
    return false;
}

Speaker edit(Speaker data){
    cout<<"Enter Name: ";
    cin.ignore();
    getline(cin,data.name);
    data.name=check(data.name);
    
    cout<<"Enter Telephone: ";
    getline(cin,data.tele);
    data.tele=check(data.tele);
    
    cout<<"Enter Topic: ";
    getline(cin,data.topic);
    data.topic=check(data.topic);
    
    cout<<"Enter Fee: $";
    cin>>data.fee;
    data.fee=check(data.fee);
    
    return data;
}

void print(Speaker data[],const short SIZE){
    for(char i=0;i<SIZE;i++){
        cout<<setw(11)<<left<<"Name: "<<data[i].name<<endl;
        cout<<setw(11)<<left<<"Telephone: "<<data[i].tele<<endl;
        cout<<setw(11)<<left<<"Topic: "<<data[i].topic<<endl;
        cout<<setw(11)<<left<<"Fee: $"<<fixed<<setprecision(2)<<data[i].fee
                <<endl<<endl;
    }
}


string check(string value){
    while(value==""){
        cout<<"Please enter a valid value: ";
        getline(cin,value);
    }
    return value;
}
float check(float value){
    while(value<0){
        cout<<"Please enter a valid value: ";
        cin>>value;
        cin.ignore();
    }
    return value;
}