
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 3, 2021, 4:29 PM
 * Purpose: Weather Stats Enum
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
enum Months:short{
    JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE
};

struct MnthDat{
    string month;
    float rainFl;
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
    MnthDat data[JUNE];
    float avgRain=0,yrAvTmp=0;
    short indexLw=0,indexHi=0;
    //Initialize Variables
    for(char i=0;i<JUNE;i++){
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
    cout<<"Enter the total rainfall for the month:\n";
    cin>>data.rainFl;
    
    cout<<"Enter the high temp:\n";
    cin>>data.tempHi;
    
    cout<<"Enter the low temp:\n";
    cin>>data.tempLow;
    
    return data;
}
float process(MnthDat data[],short &indexLw,short &indexHi,float &avgRain){
    short yrLwTmp=140,yrHiTmp=-100;
    float avgTemp=0;
    for(char i=0;i<JUNE;i++){    
        data[i].tempAvg=(data[i].tempHi + data[i].tempLow)/2;
    
        if(yrLwTmp>data[i].tempLow){
            yrLwTmp=data[i].tempLow;
            indexLw=i;
        }
        if(yrHiTmp<data[i].tempHi){
            yrHiTmp=data[i].tempHi;
            indexHi=i;
        }

        avgTemp+=data[i].tempHi;
        avgTemp+=data[i].tempLow;
        avgRain+=data[i].rainFl;
    }
    avgRain/=JUNE;
    return avgTemp/JUNE/2;
}
void print(MnthDat data[],short indexLw,short indexHi,
                                            float yrAvTmp,float avgRain){
    cout<<"Average monthly rainfall:"<<fixed<<setprecision(2)<<avgRain<<"\n";
    cout<<"High Temp:"<<data[indexHi].tempHi<<"\n";
    cout<<"Low Temp:"<<data[indexLw].tempLow<<"\n";
    cout<<"Average Temp:"<<setprecision(1)<<yrAvTmp;
}