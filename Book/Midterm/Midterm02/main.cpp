
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on April 24, 2021, 9:31 PM
 * Purpose: Gross pay w/ structure
 */

#include <iostream>
#include <iomanip>


using namespace std;

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

int main(int argc, char** argv) {
    bool repeat=true;
    char counter=0;
    short size=50;
    EmployeeData *data=new EmployeeData[size];

    while(repeat){
        repeat=input(data,counter);
        //if(repeat) 
            counter++;
    }
    
    calcs(data,counter);

    output(data,counter-1);
    
    delete []data;
    return 0;
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