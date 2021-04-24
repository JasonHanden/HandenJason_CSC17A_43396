
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 27, 2021, 12:26 AM
 * Purpose: 
 */

#include <iostream>
using namespace std;

int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

int main(){
    //your code here
    int arySize=0;
    
    int *inAry=getData(arySize);
    prntAry(inAry,arySize);
    cout<<endl;
    int *resAry=sumAry(inAry,arySize);
    prntAry(resAry,arySize);
    
    delete []inAry;
    delete []resAry;
    return 0;
}
int *getData(int &arySize){
    int temp, index=0;
    cin>>arySize;
    int *inAry=new int(arySize);
    
    while(cin>>temp){
        *(inAry+index)=temp;
        index++;
    }
    
    return inAry;
}
int *sumAry(const int *inAry,int arySize){
    int accum=0;
    int *resAry=new int(arySize);
    
    for(char i=0;i<arySize;i++){
        accum+=*(inAry+i);
        *(resAry+i)=accum;
    }
    
    return resAry;
}
void prntAry(const int *array,int arySize){
    for(char i=0;i<arySize;i++){
        cout<<*(array+i);
        cout.flush();
        if(i<arySize-1){
            cout<<" ";
        }
    }
}