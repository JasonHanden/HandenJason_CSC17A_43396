
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
void selectionSort(string[], const char);
void swap(string&, string&);
short binarySearch(string[], const char, string);

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
    string search;
    
    selectionSort(names, NUMB);     // sort array to prepare for binary search
    cout<<"The sorted names are: "<<endl;
    for(char i=0; i<NUMB; i++){
        cout<<names[i]<<endl;
    }
    
    cout<<"Enter a name for which to search: ";       // search for a name
    getline(cin,search);
    place=binarySearch(names, NUMB, search);
    
    if(place!=-1){      // name found
        cout<<"That name is found at position "<<place<<endl;
    }else{              // name not found
        cout<<"That name is not found."<<endl;
    }
    return 0;
}
// sorts names in ascending alphabetical order
void selectionSort(string names[], const char NUMB){
    char minIn;         // minimum index
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
// searches the sorted name array for user-entered string
short binarySearch(string names[], const char NUMB, string str){
    short position=-1;
    char first=0,
         middle,
         last=NUMB-1;
    bool found=false;
    
    while(!found&&first<=last){
        middle=(first+last)/2;
        if(names[middle]==str){         // name found at middle
            found=true;
            position=middle;
        }else if(names[middle]>str){    // name lower than middle
            last=middle-1;
        }else{
            first=middle+1;             // name higher than middle
        }
    }
    return position;
}