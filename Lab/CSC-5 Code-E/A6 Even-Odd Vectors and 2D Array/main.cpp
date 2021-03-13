
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on March 12, 2021, 4:29 PM
 * Purpose: Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */


//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip>
#include <valarray> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    short size,temp;
    char j=0,k=0;
    cout<<"Input the number of integers to input.\n";
    cin>>size;
    
    cout<<"Input each number.\n";
    for(char i=0; i<size; i++){
        cin>>temp;
        
        if(temp%2==0){
        
            even.push_back(temp);
        }else{
        
            odd.push_back(temp);
        }
    }
    
}
void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    char j=0;
    for(char i=0; i<even.size(); i++){
        array[i][j]=even[i];
    }
    j=1;
    for(char i=0; i<odd.size(); i++){
        array[i][j]=odd[i];
    }
}
void prntVec(vector<int> even, vector<int> odd,int width){
    short output=0;
    bool evnDone=false,oddDone=false;
    
    if(even.size()>odd.size()){
        output=even.size();
    }else{
        output=odd.size();
    }
    if(even.size()==0){
        evnDone=true;
    }else if(odd.size()==0){
        oddDone=true;
    }
    even.push_back(-1);
    odd.push_back(-2);
    cout<<setw(width)<<"Vector"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
    for(char i=0; i<output; i++){
        
        if(even[i]==-1){
            evnDone=true;
        }else if(odd[i]==-2){
            oddDone=true;
        }
        
        if(evnDone){
            cout<<setw(width*3)<<odd[i]<<endl;
        }else if(oddDone){
            cout<<setw(width*2)<<even[i]<<"          "<<endl;
        }else{
            cout<<setw(width*2)<<even[i]<<setw(width)<<odd[i]<<endl;
        }
        
    }
}
void prntAry(const int array[][COLMAX],int evnSize,int oddSize,int width){
    char output=0;
    bool evnDone=false,oddDone=false;
    if(evnSize>oddSize){
        output=evnSize;
    }else{
        output=oddSize;
    }
    
    
    cout<<setw(width)<<"Array"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
    for(char i=0; i<output; i++){
        
        if(i==evnSize){
            evnDone=true;
        }
        if(i==oddSize){
            oddDone=true;
        }
        
        if(evnDone){
            cout<<setw(width*3)<<array[i][1]<<endl;
        }else if(oddDone){
            cout<<setw(width*2)<<array[i][0]<<"          "<<endl;
        }else if(!evnDone && !oddDone){
            cout<<setw(width*2)<<array[i][0]<<setw(width)<<array[i][1]<<endl;
        }else{
            cout<<setw(width*3)<<endl;
        }
        
    }
}