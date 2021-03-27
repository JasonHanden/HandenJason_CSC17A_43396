
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 27, 2021, 2:11 PM
 * Purpose: 
 */

#include <iostream>
using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(int argc, char** argv) {
    int row,col;
    
    int **inPtr=getData(row,col);
    printDat(inPtr,row,col);
    cout<<endl;
    
    int **augPtr=augment(inPtr,row,col);
    printDat(augPtr,row+1,col+1);
    
    destroy(inPtr,row);
    destroy(augPtr,row+1);
    return 0;
}

int **getData(int &row,int &col){
    cin>>row>>col;
    int **inAry=new int*[row];
    for(char i=0;i<row;i++){
        inAry[i]=new int[col];
    }
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            cin>>inAry[i][j];
        }
    }
    return inAry;
}
void printDat(const int * const *arr,int row,int col){
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            cout<<arr[i][j];
            cout.flush();
            if(j<col-1){
                cout<<" ";
            }
        }
        if(i<row-1){
            cout<<endl;
        }
    }
}
int **augment(const int * const *inAry,int row,int col){
    int augRow=row+1, augCol=col+1;
    
    int **augAry=new int*[augRow];
    for(char i=0;i<augRow;i++){
        augAry[i]=new int[augCol];
    }
    for(char i=0;i<augRow;i++){
        augAry[i][0]=0;
    }
    for(char j=0;j<augCol;j++){
        augAry[0][j]=0;
    }
    
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            augAry[i+1][j+1]=inAry[i][j];
        }
    }
    return augAry;
}
void destroy(int **arr,int row){
    for(char i=0;i<row;i++){
        delete []arr[i];
    }
    delete []arr;
}
