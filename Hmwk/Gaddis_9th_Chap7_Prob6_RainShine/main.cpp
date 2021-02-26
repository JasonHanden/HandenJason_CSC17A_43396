
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 21, 2021, 10:17 PM
 * Purpose: Read from file and Display data
 */

#include <iostream>
#include <fstream>
#include <string>

void count(short[], short[], char);

using namespace std;

int main(){
    char inArray[3][30];        // input array for weather conditions
    short all[]={0,0,0};        // for all months, elements: Rain, Cloudy, Sunny
    short june[]={0,0,0};       // for June, elements: Rain, Cloudy, Sunny
    short july[]={0,0,0};       // for July, elements: Rain, Cloudy, Sunny
    short aug[]={0,0,0};        // for August, elements: Rain, Cloudy, Sunny
    string maxRmon="June";                      // for maximum rain month
    const string months[]={"July", "August"};   // for maximum rain month
    short maxR;                                 // for maximum rain number
    char option;                                // for count call later
    ifstream infile("RainOrShine.txt");         // input file stream
    
    if(!infile){        // check file open status
        cout <<"Error accessing file RainOrShine.txt!\nTerminating...";
        return 1;
    }
    else{               // read from file to inArray
        for(char i=0, j=0; i<3; j++){
            if(j==30){  // keep in bounds of 2d array
                j=0;
                i++;
            }
            infile >>inArray[i][j]; // read from file to 2d array
        }
        infile.close();
    }
    for(char i=0, j=0; i<3; j++){
        if(j==30){      // keep in bounds of 2d array
                j=0;
                i++;
        }
        if(i==3)        // break out if beginning assignment from non-elements
                break;
        
        if(inArray[i][j]=='R'){         // function call for Rainy
            option=0;
            if(i==0)                    // row 0, june for assign
                count(all, june, option);
            else if(i==1)               // row 1, july for assign
                count(all, july, option);
            else                        // row 2, august for assign
                count(all, aug, option);
        }else if(inArray[i][j]=='C'){   // function call for Cloudy
            option=1;
            if(i==0)
                count(all, june, option);
            else if(i==1)
                count(all, july, option);
            else 
                count(all, aug, option);
        }else{                          // function call for Sunny
            option=2;
            if(i==0)
                count(all, june, option);
            else if(i==1)
                count(all, july, option);
            else 
                count(all, aug, option);
        }
    }
    maxR=june[0];                       // determine max month and assign
    if(july[0]>maxR){
        maxRmon=months[0];
        maxR=july[0];
    }
    else if(aug[0]>maxR){
        maxRmon=months[1];
        maxR=aug[0];
    }
    
    // output results
    cout <<"June:   " <<june[0] <<" rainy days.\n";
    cout <<"        " <<june[1] <<" cloudy days.\n";
    cout <<"        " <<june[2] <<" sunny days.\n\n";
    
    cout <<"July:   " <<july[0] <<" rainy days.\n";
    cout <<"        " <<july[1] <<" cloudy days.\n";
    cout <<"        " <<july[2] <<" sunny days.\n\n";
    
    cout <<"August: " <<aug[0] <<" rainy days.\n";
    cout <<"        " <<aug[1] <<" cloudy days.\n";
    cout <<"        " <<aug[2] <<" sunny days.\n\n";
    
    cout <<"All months: " <<all[0] <<" rainy days.\n";
    cout <<"            " <<all[1] <<" cloudy days.\n";
    cout <<"            " <<all[2] <<" sunny days.\n\n";
    
    cout <<maxRmon <<" had the most days with rainfall at " <<maxR <<" days.\n";
    return 0;
}

// func to increment month and all arrays for given char & option
void count(short all[], short month[], char option){
    all[option]++;
    month[option]++;
}