
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 13, 2021, 10:56 PM
 * Purpose: 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

int read(char array[][COLMAX],int &rowDet){
    char i=0,j=0;
    int colDet=0;
    char temp[COLMAX];
    cin.ignore();
    for(i=0; i<rowDet; i++){
        cin.getline(temp, COLMAX);
        if(strlen(temp)>colDet){
            colDet=strlen(temp);
        }
        for(j=0; j<=strlen(temp); j++){
            array[i][j]=temp[j];
        }
    }
    return colDet;
}
void sort(char array[][COLMAX], int rowIn, int colIn, const char replace[], const char with[]){
        
    char temp[colIn];
    for(char i=0; i<(rowIn); i++){
        for(char j=1; j<(rowIn-i); j++){
            if(strcmp(array[j-1], array[j],replace,with)>0){
                //cout<<"Swapping\n";
                for(char k=0; k<colIn; k++){
                    temp[k] = array[j-1][k];
                }
                for(char k=0; k<colIn; k++){
                    array[j-1][k] = array[j][k];
                }
                for(char k=0; k<colIn; k++){
                    array[j][k] = temp[k];
                }
            }
        }
    }
}
void print(const char array[][COLMAX], int rowIn, int colIn){
    
    string temp;
    char i=0,j=0;
    for(i=0; i<rowIn; i++){
        
        temp=array[i];    
        cout<<temp<<endl;
    }
}

int strcmp(char a[],char b[],const char replace[],const char with[]){
    
    char searchA[255];    
    short i;
    char j,temp,swap=0;
    bool diff=false;
    for(i=0;i<256;i++){
        searchA[i]=i;
    }
    
    
    for(j=0;j<strlen(replace);j++){
        bool rep=false,wit=false;
        for(i=0;i<256;i++){
            
            if(searchA[i]==replace[j]&&rep==false){
                searchA[i]=with[j];
                rep=true;
            }
            else if(searchA[i]==with[j]&&wit==false){
                searchA[i]=replace[j];
                wit=true;
            }
            
        }    
    }
    
    i=0; j=0;
    for(char k=0;k<100;k++){
        for(i=0;i<256;i++){
            if(a[j]==searchA[i]&&b[j]==searchA[i]){
                j++;
            }else if(a[j]==searchA[i]){
                return -1;
            }else if(b[j]==searchA[i]){
                return 1;
            }
        }
    }
    return 0;
}