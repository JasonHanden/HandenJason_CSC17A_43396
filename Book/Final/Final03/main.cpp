
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on June 4, 2021, 7:54 PM
 * Purpose: Problem 3 Driver main
 */

#include <iostream>
#include <iomanip>
//#include "Prob3Table.h"
#include "Prob3TableInherited.h"

using namespace std;

int main(int argc, char** argv) {

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
    
    
    
    return 0;
}