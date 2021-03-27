
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 26, 2021, 10:24 PM
 * Purpose: 
 */

#include <iostream>

using namespace std;

int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

int main(){
    //your code here
    int arySize=0;
    
    int *origArr=getData(arySize);
    int *sToLArr=sort(origArr, arySize);
    prntDat(sToLArr,arySize);
    cout<<endl;
    
    int *lToSArr=reverse(sToLArr,arySize);
    prntDat(lToSArr,arySize);
            
    delete []origArr;
    delete []sToLArr;
    delete []lToSArr;
    return 0;
}

int *getData(int &arySize){
    short temp=0,index=0;
    cin>>arySize;
    int *origArr = new int(arySize);
    while(cin>>temp){
        *(origArr+index)=temp;
        index++;
    }
    return origArr;
}
int *sort(const int *origArr,int arySize){
    int *sToLArr = new int(arySize);
    int temp;
    
    for(char i=0;i<arySize;i++){
        *(sToLArr+i)=*(origArr+i);
    }
    
    for(char j=0;j<arySize;j++){
        for(char i=1;i<arySize;i++){
            if(*(sToLArr+i-1)>*(sToLArr+i)){
                temp=*(sToLArr+i-1);
                *(sToLArr+i-1)=*(sToLArr+i);
                *(sToLArr+i)=temp;
            }
        }
    }
    return sToLArr;
}
int *reverse(const int *sToLArr,int arySize){
    int *lToSArr = new int(arySize);
    int temp;
    
    for(char i=0;i<arySize;i++){
        *(lToSArr+i)=*(sToLArr+i);
    }
    
    for(char j=0;j<arySize;j++){
        for(char i=1;i<arySize;i++){
            if(*(lToSArr+i-1)<*(lToSArr+i)){
                temp=*(lToSArr+i-1);
                *(lToSArr+i-1)=*(lToSArr+i);
                *(lToSArr+i)=temp;
            }
        }
    }
    
    return lToSArr;
}
void prntDat(const int *array, int arySize){
    for(char i=0;i<arySize;i++){
        cout<<*(array+i);
        std::cout.flush();
        if(i<arySize-1){
            cout<<" ";
        }
    }
}