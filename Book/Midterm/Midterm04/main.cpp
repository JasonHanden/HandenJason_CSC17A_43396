
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 25, 2021, 11:22 PM
 * Purpose: Encryption and Decryption
 */

#include <iostream>

using namespace std;

void input4(char[]);
void encrypt(char[],short[]);
void decrypt(char[],short[]);
void output4(char[]);
void output4(short[]);
void inValidation(char*);



int main(int argc, char** argv) {

    short response;
    cout<<"Choose 1 for encryption, 2 for decryption, 3 to exit: ";
    cin>>response;

    if(response==1){
        char data[5]={0,0,0,0,0};
        short shift[4];
        input4(data);
        encrypt(data,shift);
        output4(data);
    }else if(response==2){
        char data[5]={0,0,0,0,0};
        short shift[4];
        input4(data);
        decrypt(data,shift);
        output4(shift);
    }
    
    return 0;
}

void input4(char data[]){
    cout<<"Please enter the string of four digits to encrypt/decrypt, 0-7: ";
    cin>>data;
    inValidation(data);
}
void encrypt(char data[],short shift[]){
    for(char i=0;i<4;i++){
        shift[i]=data[i]-48;
        shift[i]+=5;
        shift[i]%=8;
    }
    data[0]=shift[2]+48;
    data[1]=shift[3]+48;
    data[2]=shift[0]+48;
    data[3]=shift[1]+48;
}
void decrypt(char data[],short shift[]){
    shift[2]=data[0]-48;
    shift[3]=data[1]-48;
    shift[0]=data[2]-48;
    shift[1]=data[3]-48;
    
    for(char i=0;i<4;i++){
        if(shift[i]<5){
            shift[i]+=8;
        }
        shift[i]-=5;
    }
}
void output4(char data[]){
    cout<<"The resultant array is: ";
    for(char i=0;i<4;i++){
        cout<<(data[i]);
    }
}
void output4(short shift[]){
    cout<<"The resultant array is: ";
    for(char i=0;i<4;i++){
        cout<<(shift[i]);
    }
}
void inValidation(char data[]){
    bool numbs,length;

    do{
        numbs=true; length=true;
        
        if(data[4]!=0){
            length=false;
        }
        for(char i=0;i<4;i++){
            if(data[i]<=47||data[i]>=56){
                numbs=false;
            }
        }
        if(numbs==false||length==false){
            for(char i=0;i<5;i++){
                data[i]=0;
            }
            cout<<"Please enter a valid 4-digit string, 0-7: ";
            cin>>data;
        }
    }while(numbs==false||length==false);
}