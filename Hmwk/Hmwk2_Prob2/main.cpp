/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 26, 2021, 7:37 PM
 * Purpose: 
 */
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

int main(){
    //your code here
    int arySize=0;
    int *intP=getData(arySize);
    prntDat(intP, arySize);
    
    float *floatP=median(intP, arySize);
    prntMed(floatP);
    
    delete []intP;
    delete []floatP;
    return 0;
}

int *getData(int &arySize){
    cin>>arySize;
    int *intAry = new int(arySize);
    for(char i=0; i<arySize; i++){
        cin>>*(intAry+i);
    }
    return intAry;
}
void prntDat(int *intAry,int arySize){
    for(char i=0; i<arySize; i++){
        cout<<*(intAry+i);
        if(i<arySize-1){
            cout<<" ";
        }
    }
    cout<<"\n";
}
float *median(int *intAry, int arySize){
    float *fltAry = new float(arySize+2);
    *(fltAry+0)=arySize+2;
    
    int *intTemp = new int(arySize);
    for(char i=0; i<arySize; i++){
        *(intTemp+i)=*(intAry+i);
    }
    
    int temp;
    bool swap=false;
    do{
        for(char i=1;i<arySize;i++){
            if(*(intTemp+i-1)>*(intTemp+i)){
                temp=*(intTemp+i-1);
                *(intTemp+i-1)=*(intTemp+i);
                *(intTemp+i)=temp;
                swap=true;
            }else{
                swap=false;
            }
        }
    }while(swap==true);
    
    if(arySize%2==0){
        *(fltAry+1)=(float(*(intTemp+arySize/2-1))+float(*(intTemp+arySize/2)))/2;
    }else if(arySize%2==1){
        *(fltAry+1)=*(intTemp+(arySize/2));
    } 
    
    for(char i=0; i<arySize; i++){
        *(fltAry+i+2)=*(intAry+i);
    }
    return fltAry;
}
void prntMed(float *fltAry){
    
    cout<<fixed<<setprecision(0)<<*(fltAry+0);
    
    for(char i=1; i<*(fltAry+0); i++){
        cout<<" "<<fixed<<setprecision(2)<<*(fltAry+i);
        std::cout.flush();
    }
}