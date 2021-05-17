/* 
 * File:   numbers.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 7:44 PM
 * Purpose: numbers class source file
 */

#include <string>
#include <iostream>
#include "numbers.h"
using namespace std;


static const string vals[10]={
    "zero","one","two","three","four","five","six","seven","eight","nine"
};
static const string special[10]{
    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
            "seventeen","eighteen","nineteen"
};
static const string tens[9]{
    "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};


Numbers::Numbers(short value){
    number=Numbers::valCheck(value,0,9999);
}
void Numbers::prep(){
    prntStr="";
    short n1000s=number/1000;
    short n100s =number%1000/100;
    short n10s  =number%100/10;
    short n1s   =number%10;
    
    if(n1000s>0){
        for(short i=1;i<10;i++){
            if(n1000s==i){
                prntStr+=vals[i];
            }
        }
        prntStr+=" thousand ";
    }
    if(n100s>0){
        for(short i=1;i<10;i++){
            if(n100s==i){
                prntStr+=vals[i];
            }
        }
        prntStr+=" hundred ";
    }
    if(n10s>1){
        for(short i=2;i<10;i++){
            if(n10s==i){
                prntStr+=tens[i-2];
            }
        }
        if(n1s>0){
            prntStr+="-";
            for(short i=1;i<10;i++){
                if(n1s==i){
                    prntStr+=vals[i];
                }
            }
        }
    }else if(n10s==1){
        for(short i=0;i<9;i++){
            if(n1s==i){
                prntStr+=special[i];
            }
        }
    }else{
        for(short i=0;i<10;i++){
            if(n1s==i){
                prntStr+=vals[i];
            }
        }
    }
}
void Numbers::print(){
    Numbers::prep();
    cout<<number<<" is: "<<prntStr<<endl;
}

short Numbers::valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}