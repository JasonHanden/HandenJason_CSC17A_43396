/* 
 * File:   Prob3TableInherited.h
 * Author: Jason Handen
 * Created on June 4, 2021, 8:01 PM
 * Purpose: Inherited Header File
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
        T *augTable;                                  //Augmented Table with sums
    public:
        Prob3TableInherited(char *,int,int);          //Constructor
        ~Prob3TableInherited(){delete []augTable;};  //Destructor
        const T *getAugTable(){return augTable;}; 
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char *filename,int rows,int cols)
:Prob3Table<T>::Prob3Table(filename,rows,cols){
    Prob3Table<T>::calcTable();
    
    augTable = new T[(rows+1)*(cols+1)];
    
    for(short i=0;i<rows;i++){          // fill most of Aug array
        for(short j=0;j<cols;j++){
            augTable[i*(cols+1)+j]=Prob3Table<T>::table[i*cols+j];
        }
        augTable[i*(cols+1)+rows+1]=Prob3Table<T>::rowSum[i];
    }
    for(short j=0;j<cols;j++){          // fill colSum data to bottom of augArray
        augTable[(cols+1)*(rows)+j]=Prob3Table<T>::colSum[j];
    }
    augTable[(cols+1)*(rows+1)-1]=Prob3Table<T>::grandTotal;
}


#endif /* PROB3TABLEINHERITED_H */

