/* 
 * File:   Prob3Table.h
 * Author: Jason Handen
 * Created on June 4, 2021, 7:58 PM
 * Purpose: Template Header file
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Prob3Table
{
    protected:
        int rows;                                 //Number of rows in the table
        int cols;                                 //Number of cols in the table
        T *rowSum;                                //RowSum array
        T *colSum;                                //ColSum array
        T *table;                                 //Table array
        T grandTotal;                             //Grand total
        void calcTable();                         //Calculate all the sums
    public:
        Prob3Table(char *,int,int);               //Constructor then Destructor
        ~Prob3Table(){delete []table;delete []rowSum;delete []colSum;};
        const T *getTable(){return table;};
        const T *getRowSum(){return rowSum;};
        const T *getColSum(){return colSum;};
        T getGrandTotal(){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char *filename,int r,int c){
    rows=r;
    cols=c;
    table = new T[rows*cols];
    rowSum = new T[rows];
    colSum = new T[cols];
    
    ifstream inFile;
    inFile.open(filename,ios::in);
    
    short counter=0;                    // fill table w data from file
    while(inFile>>table[counter]){
        counter++;
    }
}
    
    
template<class T>
void Prob3Table<T>::calcTable(){
    grandTotal=0;
    for(short i=0;i<rows;i++){          // fill rowSum array
        rowSum[i]=0;
        for(short j=0;j<cols;j++){
            rowSum[i]+=table[i*cols+j];
            grandTotal+=table[i*cols+j];
        }
    }
    for(short i=0;i<cols;i++){          // fill colSum array
        colSum[i]=0;
        for(short j=0;j<rows;j++){
            colSum[i]+=table[j*cols+i];
        }
    }
}


#endif /* PROB3TABLE_H */

