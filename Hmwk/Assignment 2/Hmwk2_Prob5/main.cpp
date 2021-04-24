
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 27, 2021, 12:55 PM
 * Purpose: 
 */

#include <iostream>
using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(int argc, char** argv) {
    int row=0,col=0;
    
    int **arr=getData(row,col);
    prntDat(arr,row,col);
    
    int prntSum=sum(arr,row,col);
    cout<<prntSum;
    
    destroy(arr,row,col);
    return 0;
}
int **getData(int &row,int &col){
    cin>>row>>col;
    int **arr=new int*[row];
    for(char i=0;i<row;i++){
        arr[i]=new int[col];
    }
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    return arr;
}
void prntDat(const int * const *arr,int row,int col){
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            cout<<arr[i][j];
            if(j<col-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int sum(const int * const *arr,int row,int col){
    int accum=0;
    for(char i=0;i<row;i++){
        for(char j=0;j<col;j++){
            accum+=arr[i][j];
        }
    }
    return accum;
}
void destroy(int **arr,int row,int col){
    for(char i=0;i<row;i++){
        delete []arr[i];
    }
    delete []arr;
}