
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 10:29 PM
 * Purpose: Movie Data Structure
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MovieData{
    string title;
    string direct;
    short yrRel;
    short runTime;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
short movSize();
MovieData input();
void print(MovieData);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    short size=movSize();
    MovieData data[size];
    //Process or map Inputs to Outputs
    for(char i=0;i<size;i++){
        data[i]=input();
    }
    //Display Outputs
    for(char i=0;i<size;i++){
        print(data[i]);
    }
    //Exit stage right!
    return 0;
}

short movSize(){
    short size;
    cout<<"This program reviews structures\n";
    cout<<"Input how many movies, the Title of the Movie, Director, "
            <<"Year Released, and the Running Time in (minutes).\n";
    cin>>size;
    return size;
}
MovieData input(){
    MovieData inData;
    
    cin.ignore();
    getline(cin,inData.title);
    getline(cin,inData.direct);
    
    cin>>inData.yrRel;
    cin>>inData.runTime;
    
    return inData;
}
void print(MovieData outData){
    cout<<endl;
    cout<<setw(11)<<left<<"Title:"<<outData.title<<endl;
    cout<<setw(11)<<left<<"Director:"<<outData.direct<<endl;
    cout<<setw(11)<<left<<"Year:"<<outData.yrRel<<endl;
    cout<<setw(11)<<left<<"Length:"<<outData.runTime<<endl;
}