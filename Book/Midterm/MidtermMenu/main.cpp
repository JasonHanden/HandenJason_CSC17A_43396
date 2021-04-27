
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 26, 2021, 6:28 PM
 * Purpose: 
 */

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

void menu();

void prblm1();
struct Account1{
    string name;
    string address;
    char accNumb[6]={0,0,0,0,0,0};
    float begBal=0;
    float chckOut=0;
    float deposIn=0;
};
void input(Account1*);
float balanceCalc(Account1*);
float overdraw(float);
void output(Account1*,float);
void accNumbCheck(char[]);

void prblm2();
struct EmployeeData{
    string name;
    float hrsWrkd;
    float ratePay;
    float amount;
    string amntEng;
};
bool input(EmployeeData[],char);
void calcs(EmployeeData[],char);
void output(EmployeeData[],char);

void prblm3();

void prblm4();
void input4(char[]);
void encrypt(char[],short[]);
void decrypt(char[],short[]);
void output4(char[]);
void output4(short[]);
void inValidation(char*);

void prblm5();

void prblm6();

void prblm7();
struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};
Primes *factor(int);
void prntPrm(Primes *);


int main(int argc, char** argv) {
    //Declare Variables
    short choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case 1:{prblm1();break;}
            case 2:{prblm2();break;}
            case 3:{prblm3();break;}
            case 4:{prblm4();break;}
            case 5:{prblm5();break;}
            case 6:{prblm6();break;}
            case 7:{prblm7();break;}
            default: cout<<"Exiting Menu..."<<endl;
        }
    }while(choice>=1&&choice<=7);
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu:"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
    cout<<"Type 8 to Exit"<<endl<<endl;
}

// PROBLEM 1 BEGIN
void prblm1(){
    float balance;
    Account1 *account1=new Account1;
    
    input(account1);
    balance=balanceCalc(account1);
    output(account1,balance);

    delete account1;
}
void input(Account1 *account1){
    float temp=0;
    
    cin.ignore();
    cout<<"Please enter your name: ";
    getline(cin,account1->name);
    
    cout<<"Please enter your address: ";
    getline(cin,account1->address); 
    
    cout<<"Please enter your account number: ";
    cin>>account1->accNumb;
    accNumbCheck(account1->accNumb);
    
    cout<<"Please enter the account balance at the beginning of the month: ";
    cin>>account1->begBal;
    
    cout<<"Please enter the checks written out this month: \n";
    cout<<"(Enter -1 to continue...)";
    do{
        cin>>temp;
        if(int(temp)!=-1){
            account1->chckOut+=temp;
        }
    }while(int(temp)!=-1);
    cout<<"Please enter the deposits to the account this month: \n";
    cout<<"(Enter -1 to continue...)";
    do{
        cin>>temp;
        if(int(temp)!=-1){
            account1->deposIn+=temp;
        }
    }while(int(temp)!=-1);
    
}
float balanceCalc(Account1 *account1){
    float balance=account1->begBal;
    balance+=account1->deposIn;
    balance-=account1->chckOut;
    cout<<"Current balance: "<<fixed<<setprecision(2)<<balance<<" dollars.\n";
    if( int(balance*100)<0 ){
        balance=overdraw(balance);
    }
    return balance;
}
float overdraw(float balance){
    cout<<"It looks like your account has been overdrawn!\n"
        <<"A $20 fee is being added...\n";
    balance-=20;
    cout<<"Balance updated to: "<<fixed<<setprecision(2)<<balance<<" dollars.\n";
    return balance;
}
void output(Account1 *account1,float balance){
    cout<<"Account information:\n"
        <<"Name: "<<account1->name<<endl
        <<"Address: "<<account1->address<<endl
        <<"Account Number: "<<account1->accNumb<<endl
        <<"Account Balance at Month Beginning: "<<fixed<<setprecision(2)<<account1->begBal<<" dollars.\n"
        <<"Total of Checks Written: "<<account1->chckOut<<" dollars.\n"
        <<"Total Account1 Deposits: "<<account1->deposIn<<" dollars.\n"
        <<"Current Account Balance (including fees): "<<balance<<" dollars.\n";
}
void accNumbCheck(char accNumb[]){
    bool numbs,length;

    do{
        numbs=true; length=true;
        
        if(accNumb[5]!=0){
            length=false;
        }
        for(char i=0;i<5;i++){
            if(accNumb[i]<=47||accNumb[i]>=58){
                numbs=false;
            }
        }
        if(numbs==false||length==false){
            for(char i=0;i<6;i++){
                accNumb[i]=0;
            }
            cout<<"Please enter a valid 5-digit account number: ";
            cin>>accNumb;
        }
    }while(numbs==false||length==false);
}
// PROBLEM 1 END


// PROBLEM 2 BEGIN
void prblm2(){
    bool repeat=true;
    char counter=0;
    short size=50;
    EmployeeData *data=new EmployeeData[size];

    cin.ignore();
    while(repeat){
        repeat=input(data,counter);
        //if(repeat) 
            counter++;
    }
    
    calcs(data,counter);

    output(data,counter-1);
    
    delete []data;
}
bool input(EmployeeData data[],char counter){
    cout<<"To escape entry, enter negative hours worked or pay rate.\n"
        <<"Please enter employee's name: ";
    getline(cin,data[counter].name);
    
    cout<<"Please enter the hours worked: ";
    cin>>data[counter].hrsWrkd;
    if(data[counter].hrsWrkd<0){
        return false;
    }
    cout<<"Please enter the pay rate: ";
    cin>>data[counter].ratePay;
    if(data[counter].ratePay<0){
        return false;
    }
    cin.ignore();
    return true;
}
void calcs(EmployeeData data[],char counter){
    float temp;
    for(char i=0;i<counter;i++){
        if(data[i].hrsWrkd>50){
            temp=data[i].hrsWrkd-50;
            data[i].amount=40*data[i].ratePay*1;
            data[i].amount+=10*data[i].ratePay*2;
            data[i].amount+=temp*data[i].ratePay*3;
        }else if(data[i].hrsWrkd>40){
            temp=data[i].hrsWrkd-40;
            data[i].amount=40*data[i].ratePay*1;
            data[i].amount+=temp*data[i].ratePay*2;
        }else{
            data[i].amount=data[i].hrsWrkd*data[i].ratePay;
        }

        //-------------------------------------------------------------------------------------------
        // Code borrowed in part from "RomanNumeralConversionToArabic" in CSC-17A Spring 2021 Github 
        //-------------------------------------------------------------------------------------------
        unsigned int n2Cnvrt=int(data[i].amount);
        unsigned int temp1=long(data[i].amount*1000);
        
        if(temp1%10>=5){
            temp1+=10;
        }
        temp1/=10;
        unsigned short nDeci=temp1%100; 

        
        if(n2Cnvrt>=0 && n2Cnvrt<10000){
            //Process or map Inputs to Outputs
            //Determine 1000's, 100's, 10's, 1's
            unsigned char n1000s,n100s,n10s,n1s,nTenths,nHundrs;
            n1000s=n2Cnvrt/1000;    //Shift 3 places to the left
            n100s=n2Cnvrt%1000/100; //Remainder of division of 1000 then shift 2 left
            n10s=n2Cnvrt%100/10;    //Remainder of division of 100 then shift 1 left
            n1s=n2Cnvrt%10;         //Remainder of division by 10
            nTenths=nDeci%100/10;   //Remainder of division by 100 then shift 1 left for tenths
            nHundrs=nDeci%10;       //Remainder of division by 10 for hundredths

            //Output the number of 1000's in Roman Numerals
            data[i].amntEng=(n1000s==9?"Nine Thousand ":
                             n1000s==8?"Eight Thousand ":
                             n1000s==7?"Seven Thousand ":
                             n1000s==6?"Six Thousand ":
                             n1000s==5?"Five Thousand ":
                             n1000s==4?"Four Thousand ":
                             n1000s==3?"Three Thousand ":
                             n1000s==2?"Two Thousand ":
                             n1000s==1?"One Thousand ":"");

            //Output the number of 100's
            //Using the Ternary Operator
            data[i].amntEng+=(n100s==9?"Nine Hundred ":
                              n100s==8?"Eight Hundred ":
                              n100s==7?"Seven Hundred ":
                              n100s==6?"Six Hundred ":
                              n100s==5?"Five Hundred ":
                              n100s==4?"Four Hundred ":
                              n100s==3?"Three Hundred ":
                              n100s==2?"Two Hundred ":
                              n100s==1?"One Hundred ":"");

            //Output the number of 10's

            data[i].amntEng+=(n10s==9?"Ninety":
                              n10s==8?"Eighty":
                              n10s==7?"Seventy":
                              n10s==6?"Sixty":
                              n10s==5?"Fifty":
                              n10s==4?"Forty":
                              n10s==3?"Thirty":
                              n10s==2?"Twenty":"");
                              
            if(n10s==1){
                data[i].amntEng+=(n1s==9?"Nineteen":
                                  n1s==8?"Eighteen":
                                  n1s==7?"Seventeen":
                                  n1s==6?"Sixteen":
                                  n1s==5?"Fifteen":
                                  n1s==4?"Fourteen":
                                  n1s==3?"Thirteen":
                                  n1s==2?"Twelve":
                                  n1s==1?"Eleven":"Ten");
            }else{
                if(n10s>1 && n1s>0){
                    data[i].amntEng+="-";
                }
                data[i].amntEng+=(n1s==9?"Nine":
                                  n1s==8?"Eight":
                                  n1s==7?"Seven":
                                  n1s==6?"Six":
                                  n1s==5?"Five":
                                  n1s==4?"Four":
                                  n1s==3?"Three":
                                  n1s==2?"Two":
                                  n1s==1?"One":"");
            }
            if(nTenths>0||nHundrs>0){
                data[i].amntEng+=" and ";    
            }
            data[i].amntEng+=(nTenths==9?"Ninety":
                              nTenths==8?"Eighty":
                              nTenths==7?"Seventy":
                              nTenths==6?"Sixty":
                              nTenths==5?"Fifty":
                              nTenths==4?"Forty":
                              nTenths==3?"Thirty":
                              nTenths==2?"Twenty":"");
                              
            if(nTenths==1){
                data[i].amntEng+=(nHundrs==9?"Nineteen":
                                  nHundrs==8?"Eighteen":
                                  nHundrs==7?"Seventeen":
                                  nHundrs==6?"Sixteen":
                                  nHundrs==5?"Fifteen":
                                  nHundrs==4?"Fourteen":
                                  nHundrs==3?"Thirteen":
                                  nHundrs==2?"Twelve":
                                  nHundrs==1?"Eleven":"Ten");
            }else{
                if(nTenths>1 && nHundrs>0){
                    data[i].amntEng+="-";
                }else{
                    data[i].amntEng+=" ";
                }
                data[i].amntEng+=(nHundrs==9?"Nine ":
                                  nHundrs==8?"Eight ":
                                  nHundrs==7?"Seven ":
                                  nHundrs==6?"Six ":
                                  nHundrs==5?"Five ":
                                  nHundrs==4?"Four ":
                                  nHundrs==3?"Three ":
                                  nHundrs==2?"Two ":
                                  nHundrs==1?"One ":"");
            }
            if(nTenths>0||nHundrs>0){
                data[i].amntEng+="Hundredths";    
            }
            data[i].amntEng+=" Dollars.";
            
        }
        //-------------------//
        // End Borrowed Code //
        //-------------------//
    }


}
void output(EmployeeData data[],char counter){

    for(char i=0;i<counter;i++){       
        cout<<"--------------------------------------------------------------------------------------------------\n"
            <<"Mark Sort Inc.\n"
            <<"1234 Boulevard Way\n"
            <<"Riverside, CA 92507\n";
        cout<<"Name:"<<setw(25)<<right<<data[i].name<<"    Amount: $"<<setw(9)<<left<<fixed<<setprecision(2)<<data[i].amount<<endl;
        cout<<"Amount: "<<data[i].amntEng<<endl;
        cout<<"Signature:  X____________________\n";
        cout<<"--------------------------------------------------------------------------------------------------\n";
    }
}
// PROBLEM 2 END

// PROBLEM 3 BEGIN
void prblm3(){
    cout<<"Problem 3 is included elsewhere in this assignment.\nPlease view it there...\n";
}
// PROBLEM 3 END

// PROBLEM 4 BEGIN
void prblm4(){
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
    }else{

    }
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
            cin.ignore();
            cout<<"Please enter a valid 4-digit string, 0-7: ";
            cin>>data;
        }
    }while(numbs==false||length==false);
}
// PROBLEM 4 END

// PROBLEM 5 BEGIN
void prblm5(){
    cout<<"The highest n for n! for the following data types:\n"
        <<" char              n=5\n"
        <<" unsigned char     n=5\n"
        <<" short             n=7\n"
        <<" unsigned short    n=8\n"
        <<" int               n=12\n"
        <<" unsigned int      n=12\n"
        <<" float             n=13\n"
        <<" double            n=22\n";
}
// PROBLEM 5 END

// PROBLEM 6 BEGIN
void prblm6(){
    cout<<"See attached image for work:\n"
        <<"  2.875(base10) = 10.111(base2), 2.7(base8), 2.E(base16)\n"
        <<"  2.875(base10) to NASA format: 5C0000FE \n\n"
        <<"  .1796875(base10) = .0010111(base2), .134(base8), .2E(base16)\n"
        <<"  .1796875(base10) to NASA format: 5C000002 \n\n"
        <<"  -2.875(base10) = -10.111(base2), -2.7(base8), -2.E(base16)\n"
        <<"  -2.875(base10) to NASA format: A40000FE \n\n"
        <<"  -.1796875(base10) = -.0010111(base2), -.134(base8), -.2E(base16)\n"
        <<"  -.1796875(base10) to NASA format: A4000002 \n\n"
        <<"  59999901(NASA) = 1.4(base10)\n"
        <<"  59999902(NASA) = 2.8(base10)\n"
        <<"  A66667FE(NASA) = -2.8(base10)\n";
}
// PROBLEM 6 END

// PROBLEM 7 BEGIN
void prblm7(){
    int data=0;
    while(data<2){
        cout<<"Please enter a value between 2 and 10,000: ";
        cin>>data;
    }
    
    Primes *primes=factor(data);
    
    cout<<data<<" = ";
    prntPrm(primes);
    

    delete primes->prime;
    delete primes;
}
Primes *factor(int input){
    char power;
    char counter=0;
    Primes *primes=new Primes;
    Prime *prime = new Prime[7];
    primes->prime=prime;

    for(short i=2;i<10000;i++){
        power=0;
        if(input%i==0){
            while(input%i==0){
                input/=i;
                power++;
            }
            primes->prime[counter].prime=i;
            primes->prime[counter].power=power;
            counter++;
        }
    }   
    primes->nPrimes=counter;
    return primes;
}
void prntPrm(Primes *primes){
    for(char i=0;i<primes->nPrimes;i++){
        cout<<primes->prime[i].prime<<"^"<<short(primes->prime[i].power);
        if(i+1<primes->nPrimes){
            cout<<" * ";
        }
    }
}