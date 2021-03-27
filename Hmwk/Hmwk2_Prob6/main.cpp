
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 27, 2021, 1:53 PM
 * Purpose: 
 */

#include <iostream>
using namespace std;

int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

int main(int argc, char** argv) {
    int arySize=0;
    
    int *inPtr=getData(arySize);
    int *augPtr=augment(inPtr,arySize);
    
    prntAry(inPtr,arySize);
    cout<<endl;
    prntAry(augPtr,arySize+1);
    
    delete []inPtr;
    delete []augPtr;
    return 0;
}

int *getData(int &arySize){
    int temp,index=0;
    cin>>arySize;
    
    int *inAry=new int(arySize);
    while(cin>>temp){
        *(inAry+index)=temp;
        index++;
    }
    return inAry;
}
int *augment(const int *arr,int arySize){
    int *augArr=new int(arySize+1);
    *(augArr+0)=0;
    for(char i=0;i<arySize;i++){
        *(augArr+i+1)=*(arr+i);
    }
    return augArr;
}
void prntAry(const int *arr,int arySize){
    for(char i=0;i<arySize;i++){
        cout<<*(arr+i);
        cout.flush();
        if(i<arySize-1){
            cout<<" ";
        }
    }
}