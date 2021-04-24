
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 22, 2021, 8:32 PM
 * Purpose: 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

short readFile(string,string[]);
void transform(string[],const short);
void outFile(string,string[],const short);

int main(int argc, char** argv) {
    
    string data[20];
    
    short dataSz=readFile("input.txt",data);
    transform(data,dataSz);
    outFile("output.txt",data,dataSz);
    
    return 0;
}

short readFile(string flName,string data[]){
    string temp;
    short i=0;
    ifstream infile;
    infile.open(flName);
    
    if(infile.is_open()){
        while(getline(infile,temp)){
            data[i]=temp;
            i++;
        }
    }else{
        cout<<"Fatal Error. Exiting...\n";
        exit;
    }
    
    infile.close();
    return i+1;
}
void transform(string data[],const short SIZE){
    for(short i=0;i<SIZE;i++){
        for(short j=0;j<data[i].size();j++){
            data[i][j]-=10;
        }
    }
}
void outFile(string flName,string data[],const short SIZE){
    ofstream outfile;
    outfile.open(flName);
    
    if(outfile.is_open()){
        for(short i=0;i<SIZE;i++){
            outfile<<data[i]<<endl;
        }
    }else{
        cout<<"Fatal Error. Exiting...\n";
        exit;
    }
    
    outfile.close();
}