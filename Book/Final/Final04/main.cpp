
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on June 6, 2021, 8:57 PM
 * Purpose: Problem 4 main file
 */

#include <iostream>
#include <ctime>
#include "SavingsAccount.h"
using namespace std;

int main(int argc, char** argv) {

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
    
    return 0;
}