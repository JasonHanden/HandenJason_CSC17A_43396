
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 2:41 PM
 * Purpose: Structure demo
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Sales{
    float saleQua[4];
    float saleTot;
    float averQua;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
Sales prompt(Sales,string);
Sales process(Sales);
void print(Sales);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    string name;
    Sales north,west,east,south;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    name="North";
    north=prompt(north,name);
    north=process(north);
    print(north);
    cout<<endl;
    
    name="West";
    west=prompt(west,name);
    west=process(west);
    print(west);
    cout<<endl;
    
    name="East";
    east=prompt(east,name);
    east=process(east);
    print(east);
    cout<<endl;
    
    name="South";
    south=prompt(south,name);
    south=process(south);
    print(south);
        
    //Exit stage right!
    
    return 0;
}

Sales prompt(Sales div,string name){
    cout<<name<<endl;
    
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>div.saleQua[0];
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>div.saleQua[1];
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>div.saleQua[2];
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>div.saleQua[3];
    return div;
}
Sales process(Sales div){
    for(char i=0;i<4;i++){
        div.saleTot+=div.saleQua[i];
    }
    div.averQua=div.saleTot/4;
    return div;
}
void print(Sales div){
    cout<<"Total Annual sales:$"
            <<fixed<<setprecision(2)<<div.saleTot<<endl;
    cout<<"Average Quarterly Sales:$"
            <<div.averQua;
}