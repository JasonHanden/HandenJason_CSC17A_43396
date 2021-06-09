/* 
 * File:   Employee.cpp
 * Author: Jason Handen
 * Created on June 6, 2021, 11:19 PM
 * Purpose: Employee source file
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(char name[],char title[],float rate){
    for(char i=0;i<20;i++){
        MyName[i]=name[i];
    }
    for(char i=0;i<20;i++){
        JobTitle[i]=title[i];
    }
    
    if(rate>0&&rate<200){
        HourlyRate=rate;
    }else{
        cout<<"Unacceptable Hourly Rate\n";
        HourlyRate=0;
    }
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}
float  Employee::CalculatePay(float rate,int hours){
    GrossPay = Employee::getGrossPay(rate,hours);
    NetPay = Employee::getNetPay(GrossPay);
    return 0;
}
float  Employee::getGrossPay(float rate,int hours){
    float pay=0;
    if(hours>=60){
        pay=40*rate;
        pay+=10*(rate+rate/2);
        hours-=50;
        pay+=hours*rate*2;
    }else if(hours>=50){
        pay=40*rate;
        hours-=40;
        pay+=hours*(rate+rate/2);
    }else{
        pay=hours*rate;
    }
    return pay;
}
float  Employee::getNetPay(float gpay){
    float net=0;
    net=gpay-Employee::Tax(gpay);
    return net;
}
void   Employee::toString(){
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<" Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked
            <<" Gross Pay = "<<GrossPay<<" Net Pay = "<<NetPay<<endl;
}
int    Employee::setHoursWorked(int hours){
    if(hours>0&&hours<84){
        HoursWorked=hours;
    }else{
        cout<<"Unacceptable Hours Worked\n";
        HoursWorked=0;
    }
    return HoursWorked;
}
float  Employee::setHourlyRate(float rate){
    HourlyRate=rate;
    return HourlyRate;
}
float  Employee::Tax(float gpay){
    float tax=0;
    if(gpay>=1000){
        tax=500*.1;
        tax+=500*.2;
        gpay-=1000;
        tax+=gpay*.3;
    }else if(gpay>=500){
        tax=500*.1;
        gpay-=500;
        tax+=gpay*.2;
    }else{
        tax+=gpay*.1;
    }
    return tax;
}