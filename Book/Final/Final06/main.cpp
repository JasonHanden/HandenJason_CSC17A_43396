
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on June 7, 2021, 6:32 PM
 * Purpose: 
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    
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
    unsigned char   valA=0x0F;      //3.75 -> WD 8, BP 2        1 byte
    unsigned short  valB=0xB333;    //0.7  -> WD 16, BP 16      2 bytes
    unsigned int    valC=0x00B3CCCD;//89.9 -> WD 24, BP 17      4 bytes, 3 used
    
    unsigned int prodA = valA*7;
    prodA>>=2;
    unsigned int prodB = valB*7;
    prodB>>=16;
    unsigned int prodC = valC*7;
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
    
    return 0;
}


