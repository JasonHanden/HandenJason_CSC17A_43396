
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 22, 2021, 4:43 PM
 * Purpose: Sentence Filter
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string data;
    
    ifstream inText;
    ofstream outText;
    
    inText.open("input.txt");
    outText.open("output.txt");
    
    getline(inText,data);
    
    if(inText.is_open()){
        for(unsigned short i=0;i<data.size();i++){
            if(i==0||data[i-2]==46){
                if(data[i]>=65&&data[i]<=90){
                    continue;
                }else if(data[i]>=97&&data[i]<=122){
                    data[i]-=32;
                }else{
                    continue;
                }
            }else if(data[i]>=65&&data[i]<=90){
                data[i]+=32;
            }else{
                continue;
            }
        }
    }else{
        cout<<"Opening input file failed. Exiting...\n";
    }
    
    outText<<data;
    
    inText.close();
    outText.close();
    
    return 0;
}