/* 
 * File:   Prob2Sort.h
 * Author: Jason Handen
 * Created on June 3, 2021, 4:54 PM
 * Purpose: Problem 2 header file
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

#include <cstddef>
#include <iostream>
using namespace std;

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
    private:
        int *index;                                 //Index that is utilized in the sort
    public:
        Prob2Sort(){index=NULL;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T* sortArray(const T*,int,bool);            //Sorts a single column array
        T* sortArray(const T*,int,int,int,bool);    //Sorts a 2 dimensional array represented as a 1 dim array
}; 

template<class T>
T* Prob2Sort<T>::sortArray(const T *array,int row,bool asc){     //only one column to sort
    
    T *newArray = new T[row];           //array to sort
    index = new int[row];

    for(short i=0;i<row;i++){
        index[i]=i;                         //fill index array with unchanged indexes
    }
    
    int temp;
    if(asc==false){
        for(short i=0;i<row-1;i++){         //inspiration from CSC-17A
            for(short j=i+1;j<row;j++){
                if(array[index[i]]<array[index[j]]){
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
                }
            }
        }
    }else{
        for(short i=0;i<row-1;i++){         //inspiration from CSC-17A
            for(short j=i+1;j<row;j++){
                if(array[index[i]]>array[index[j]]){
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
                }
            }
        }
    }
    
    for(short i=0;i<row;i++){
        newArray[i]=array[index[i]];
    }

    return newArray;
}
template<class T>
T* Prob2Sort<T>::sortArray(const T *array,int row,int col,int colSort,bool asc){
    
    colSort--;
    T *newArray = new T[row*col];           //array to sort
    index = new int[row];

    for(short i=0;i<row;i++){
        index[i]=i;                         //fill index array with unchanged indexes
    }

    int temp;
    if(asc==false){
        for(short i=0;i<row-1;i++){         //inspiration from CSC-17A
            for(short j=i+1;j<row;j++){
                if(array[index[i]*col+colSort]<array[index[j]*col+colSort]){
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
                }
            }
        }
    }else{
        for(short i=0;i<row-1;i++){         //inspiration from CSC-17A
            for(short j=i+1;j<row;j++){
                if(array[index[i]*col+colSort]>array[index[j]*col+colSort]){
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
                }
            }
        }
    }

    for(short i=0;i<row;i++){
        for(short j=0;j<col;j++){
            newArray[i*col+j]=array[index[i]*col+j];
        }
    }
    
    return newArray;
}

#endif /* PROB2SORT_H */

