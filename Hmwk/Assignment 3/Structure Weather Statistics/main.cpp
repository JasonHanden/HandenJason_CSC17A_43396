
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 3:38 PM
 * Purpose: Weather Stat enum
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MnthDat{
    string month;
    short rainFl;
    short tempHi;
    short tempLow;
    short tempAvg;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
MnthDat input(MnthDat);
float process(MnthDat[],short&,short&,float&);
void print(MnthDat[],short,short,float,float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MnthDat data[12];
    float avgRain=0,yrAvTmp=0;
    short indexLw=0,indexHi=0;
    //Initialize Variables
    for(char i=0;i<12;i++){
        data[i]=input(data[i]);
    }
    //Process or map Inputs to Outputs
    yrAvTmp=process(data,indexLw,indexHi,avgRain);
    //Display Outputs
    print(data,indexLw,indexHi,yrAvTmp,avgRain);
    //Exit stage right!
    return 0;
}

MnthDat input(MnthDat data){
    cin>>data.month>>data.rainFl>>data.tempLow>>data.tempHi;
    return data;
}
float process(MnthDat data[],short &indexLw,short &indexHi,float &avgRain){
    short yrLwTmp=140,yrHiTmp=-100;
    float avgTemp=0;
    for(char i=0;i<12;i++){
        
        data[i].tempAvg=(data[i].tempHi+data[i].tempLow)/2;
        
        if(yrLwTmp>data[i].tempLow){
            yrLwTmp=data[i].tempLow;
            indexLw=i;
        }
        if(yrHiTmp<data[i].tempHi){
            yrHiTmp=data[i].tempHi;
            indexHi=i;
        }
        avgTemp+=data[i].tempAvg;
        avgRain+=data[i].rainFl;
    }
    avgRain/=12;
    return avgTemp/12;
}
void print(MnthDat data[],short indexLw,short indexHi,
                                            float yrAvTmp,float avgRain){
    cout<<"Average Rainfall "<<fixed<<setprecision(1)<<avgRain<<" inches/month\n";
    cout<<"Lowest  Temperature "<<data[indexLw].month<<"  "
                            <<data[indexLw].tempLow<<" Degrees Fahrenheit\n";
    cout<<"Highest Temperature "<<data[indexHi].month<<"  "
                            <<data[indexHi].tempHi<<" Degrees Fahrenheit\n";
    cout<<"Average Temperature for the year "<<fixed<<setprecision(0)
                                            <<yrAvTmp<<" Degrees Fahrenheit\n";
}