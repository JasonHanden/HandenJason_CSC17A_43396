
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on June 7, 2021, 7:58 PM
 * Purpose: 
 */

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

using namespace std;

int main(int argc, char** argv) {
    
    short response=1;
    while(response>0&&response<7){
        cout<<"\nChoose a problem to view, 1-6 or 7 to exit:\n";
        cin>>response;
        if(response==1){
            prob1();
        }else if(response==2){
            prob2();
        }else if(response==3){
            prob3();
        }else if(response==4){
            prob4();
        }else if(response==5){
            prob5();
        }else if(response==6){
            prob6();
        }else{
            cout<<"\nExiting program...\n";
        };
    }
    
    return 0;
}

void prob1(){
    cout<<"Problem 1: Random Numbers\n";
    
    char n=5;
    char rndseq[]={18,33,56,79,124};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
void prob2(){
    cout<<"Problem 2: Sorting\n";
    
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
        {
            cout<<zc[i*16+j];
        }
    }
    delete []zc;
    cout<<endl;
}
void prob3(){
    cout<<"Problem 3: Table and Augmented Table\n";
    
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    
    
    /*
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    */
    
    
    // I changed the driver program code to exactly match the examples
    // provided in the Final17A.txt file. I wanted the right justify
    // columns to align properly. I hope you will not mind.
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<setw(6)<<naugT[i*cols+j];
        }
        cout<<endl;
    }
    cout<<endl;
     
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<setw(6)<<augT[i*(cols+1)+j];
        }
        cout<<endl;
    }
}
void prob4(){
    cout<<"Problem 4: SavingsAccount class\n";
    
    srand(time(0));

    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}
void prob5(){
    cout<<"Problem 5: Employee class\n";

    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}
void prob6(){
    cout<<"Problem 6: Conversion and Binary Scaling\n";
    
    cout<<"See attached image and code below for work.\n\n";

    cout<<"3.75 base10 = 11.11 base2 = 3.6 base8 = 3.C base16\n";
    cout<<" 0.7 base10 = 0.1(0110)repeating base2 = 0.5(4631)repeating base8 = "
            <<"B(3)repeating base16\n";
    cout<<"89.9 base10 = 1011001.1(1100)repeating base2 = "
            <<"131.7(1463)repeating base8 = 59.E(6)repeating base16\n\n";
    
    cout<<"3.75 base10 = 78000002 NASA base16\n";
    cout<<" 0.7 base10 = 59999900 NASA base16\n";
    cout<<"89.9 base10 = 59E66607 NASA base16\n\n";
    
    ////////////////////////////////////////////////////////////////////////////
    unsigned char   valA=0x0F;      //3.75 -> WD 8,  BP 2       1 byte
    unsigned short  valB=0xB333;    //0.7  -> WD 16, BP 16      2 bytes
    unsigned int    valC=0x00B3CCCD;//89.9 -> WD 24, BP 17      4 bytes, 3 used
    const unsigned char val7=0x07;  //7    -> WD 8,  BP 0       1 byte
    
    unsigned int prodA = valA*val7;
    prodA>>=2;
    unsigned int prodB = valB*val7;
    prodB>>=16;
    unsigned int prodC = valC*val7;
    prodC>>=17;
    ////////////////////////////////////////////////////////////////////////////
    
    cout<<"3.75 base10 * 7 base10 = "<<setw(3)<<prodA
                    <<" (Integer result using scaled binary)\n";
    cout<<" 0.7 base10 * 7 base10 = "<<setw(3)<<prodB
                    <<" (Integer result using scaled binary)\n";
    cout<<"89.9 base10 * 7 base10 = "<<setw(3)<<prodC
                    <<" (Integer result using scaled binary)\n\n";
    
    cout<<"3.75 base10 = 40700000 IEEE 754\n";
    cout<<" 0.7 base10 = 3F333333 IEEE 754\n";
    cout<<"89.9 base10 = 42B3CCCD IEEE 754\n";
}