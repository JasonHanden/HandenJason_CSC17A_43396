
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 13, 2021, 4:56 PM
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}
int  srch1(const char sntnce[],const char pattern[],int start){
    int index=-1,fndCnt=0;
    string sntnceS(sntnce);
    string pattrnS(pattern);
    for(char i=start; i<sntnceS.size(); i++){
        fndCnt=0;
        if(sntnce[i]==pattern[0]){
            for(char j=0;j<pattrnS.size(); j++){
                if(sntnce[i+j]==pattern[j]){
                    if(j==0){
                        index=i;
                    }
                    fndCnt++;
                }
            }
        }
        if(fndCnt==pattrnS.size()){
            return index;
        }
    }
    return -1;
}
void srchAll(const char sntnce[],const char pattern[],int match[]){
    string sntnceS(sntnce);
    
    int indxFnd,start=0,matchIn=0;
    for(char i=0; i<sntnceS.size(); i++){
        indxFnd=srch1(sntnce,pattern,start);
        if(indxFnd!=-1){
            start=indxFnd;
            match[matchIn]=indxFnd;
            matchIn++;
        }
        start++;
    }
    match[matchIn]=-1;
}
void print(const char outAry[]){
    cout<<outAry<<endl;
}
void print(const int match[]){
    if(match[0]==-1){
        cout<<"None\n";
        return;
    }
    char i=0;
    while(match[i]!=-1){
        cout<<match[i]<<endl;
        i++;
    }
}