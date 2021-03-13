
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 12, 2021, 10:57 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int [][COLMAX],int &,int &){
    
}
void sum(const int [][COLMAX],int,int,int[][COLMAX]){
    
}
void print(const int [][COLMAX],int,int,int){
    
}