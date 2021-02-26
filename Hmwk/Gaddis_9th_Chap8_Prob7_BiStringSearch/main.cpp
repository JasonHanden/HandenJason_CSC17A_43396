
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on February 24, 2021, 10:09 PM
 * Purpose: Binary String Search
 */

#include <iostream>
#include <string>

using namespace std;

// function prototypes
void selectionSort(string[], char);
void swap(string&, string&);
short binarySearch(string[], char);

int main() {
    const char NUMB=20;
    string names[NUMB]={"Collins, Bill","Smith, Bart","Allen, Jim",
                        "Griffin, Jim","Stamey, Marty","Rose, Geri",
                        "Taylor, Terri","Johnson, Jill","Allison, Jeff",
                        "Looney, Joe","Wolfe, Bill","James, Jean",
                        "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                        "Javens, Renee","Harrison, Rose","Setzer, Cathy",
                        "Pike, Gordon","Holland, Beth"};
    short place;
    
    selectionSort(names, NUMB);        // sort array to prepare for binary search
    cout<<"The sorted names are: "<<endl;
    for(char i=0; i<NUMB; i++){
        cout<<names[i]<<endl;
    }
    
    place=binarySearch(names, NUMB);
    
    if(place!=-1){
        cout<<"That name is found at position "<<place<<endl;
    }else{
        cout<<"That name is not found."<<endl;
    }
    return 0;
}
void selectionSort(string names[], char NUMB){
    char minIn;        // minimum index
    string minVal;      // minimum string value
    
    for(char i=0; i<(NUMB-1); i++){
        minIn=i;
        minVal=names[i];
        for(char index=i+1; index<NUMB; index++){
            if(names[index]<minVal){
                minVal=names[index];
                minIn=index;
            }
        }
        swap(names[minIn], names[i]);
    }
}
// swaps str1 and str2 in memory
void swap(string& str1, string& str2){
    string temp=str1;
    str1=str2;
    str2=temp;
}
short binarySearch(string names[]){
    short position=-1;
    return position;
}