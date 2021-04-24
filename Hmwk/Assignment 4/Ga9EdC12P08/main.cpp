
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 22, 2021, 5:25 PM
 * Purpose: Arrays and Files
 */

#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

void arrayToFile(string,int[],const short);
void arrayClear(int[],const short);
void fileToArray(string,int[],const short);

int main(int argc, char** argv) {
    string flName="array.bin";
    const short SIZE=10;
    int array[]={ 1,10,100,1000,10000,2,20,200,2000,20000 };
    
    cout<<"Int array to be stored as a binary file:\n";
    for(char i=0;i<10;i++){
        cout<<array[i]<<" ";
        if((i+1)%5==0){
            cout<<endl;
        }
    }
    
    cout<<"Storing to binary file...\n";
    arrayToFile(flName,array,SIZE);
    
    cout<<"Clearing array...\n";
    arrayClear(array,SIZE);
    cout<<"Int array after being cleared:\n";
    for(char i=0;i<10;i++){
        cout<<array[i]<<" ";
        if((i+1)%5==0){
            cout<<endl;
        }
    }
    
    cout<<"Reading from file...\n";
    fileToArray(flName,array,SIZE);
    
    cout<<"Int array from binary file:\n";
    for(char i=0;i<10;i++){
        cout<<array[i]<<" ";
        if((i+1)%5==0){
            cout<<endl;
        }
    }
    
    return 0;
}


void arrayToFile(string flName,int array[],const short SIZE){
    ofstream outfile;
    outfile.open(flName,ios::binary);
    if(outfile.is_open()){
        for(char i=0;i<SIZE;i++){
            outfile.write((char*)&array[i],sizeof(int));
        }
    }else{
        cout<<"Fatal Error. Exiting...\n";
        exit;
    }
    outfile.close();
}
void arrayClear(int array[],const short SIZE){
    for(char i=0;i<SIZE;i++){
        array[i]=0;
    }
}
void fileToArray(string flName,int array[],const short SIZE){
    int temp;
    ifstream infile;
    infile.open(flName,ios::binary);
    if(infile.is_open()){
        for(char i=0;i<SIZE;i++){
            infile.read((char*)&array[i],sizeof(int));
        }
    }else{
        cout<<"Fatal Error. Exiting...\n";
        exit;
    }
    infile.close();
}