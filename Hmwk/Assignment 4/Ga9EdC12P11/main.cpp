
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 22, 2021, 7:04 PM
 * Purpose: Output Struct to binary file
 */

#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

struct DivReport{
    string divName;
    short quarter;
    float qSales;
};

void compEntry(DivReport[],string,const short);
void fileStore(DivReport[],const short);
float validation(float);

int main(int argc, char** argv) {
    const short SIZE=16;
    DivReport *report=new DivReport[SIZE];
    
    compEntry(report,"East",0);
    compEntry(report,"West",4);
    compEntry(report,"North",8);
    compEntry(report,"South",12);
    
    fileStore(report,SIZE);
    
    delete report;
    return 0;
}
void compEntry(DivReport report[],string divName,const short LOC){
    for(char i=LOC;i<LOC+4;i++){
        report[i].divName=divName;
        cout<<"Division Name: "<<divName<<endl;
        report[i].quarter=i-LOC+1;
        cout<<"for Quater "<<report[i].quarter<<"\n";
        cout<<"Enter Quarterly Sales: ";
        cin>>report[i].qSales;
        report[i].qSales=validation(report[i].qSales);
    }
}
void fileStore(DivReport report[],const short SIZE){
    ofstream outfile;
    outfile.open("output.bin",ios::binary);
    
    if(outfile.is_open()){
        for(char i=0;i<SIZE;i++){
            outfile.write((char*)&report[i].divName,sizeof(report[i].divName));
            outfile.write((char*)&report[i].quarter,sizeof(int));
            outfile.write((char*)&report[i].qSales,sizeof(float));
        }
    }
    
    outfile.close();
}
float validation(float entry){
    while(entry<0){
        cout<<"Please enter a value greater than 0:";
        cin>>entry;
    }
    return entry;
}