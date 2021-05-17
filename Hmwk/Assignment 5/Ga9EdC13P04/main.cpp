
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 3:43 PM
 * Purpose: Patient charges main file
 */

#include <iostream>
#include <iomanip>

#include "procedure.h"
#include "patient.h"

using namespace std;

void prntPro(Procedure,short);

int main(int argc, char** argv) {
    
    float totalCh=0;
    Patient pat("Jane","Johnson","Doe","1234 Apple Ave.","Riverview","AR",
                        "72110","(123)123-4567","John Doe","(123)234-5678");
    
    Procedure pro1("Physical Exam","05/15/2021","Dr. Irvine",250.00);
    Procedure pro2("X-ray","05/15/2021","Dr. Jamison",500.00);
    Procedure pro3("Blood test","05/15/2021","Dr. Smith",200.00);
    
    totalCh+=pro1.getCharges();
    totalCh+=pro2.getCharges();
    totalCh+=pro3.getCharges();
    
    //pull patient information
    string *name=pat.getName();
    string *locale=pat.getLocale();
    string phnNumb=pat.getPhnNumb();
    string *emerCon=pat.getEmerCon();
    //print patient information
    cout<<"Patient's Name: "<<name[0]<<" "<<name[1]<<" "<<name[2]<<endl;
    cout<<"Patient's Address: "<<locale[0]<<endl;
    cout<<setw(19)<<""<<locale[1]<<", "<<locale[2]<<" "<<locale[3]<<endl;
    cout<<"Patient's Phone Number: "<<phnNumb<<endl;
    cout<<"Patient's Emergency Contact: "<<emerCon[0]<< " at "<<emerCon[1]<<endl;
    
    prntPro(pro1,1);
    prntPro(pro2,2);
    prntPro(pro3,3);
    
    cout<<"\n\nCharges for three (3) procedures total: $"<<totalCh;
    
    return 0;
}

void prntPro(Procedure pro,short numb){
    
    cout<<"\n*****\n";
    cout<<"Procedure #"<<numb<<": "<<pro.getProName()<<endl;
    cout<<"Date: "<<pro.getProDate()<<endl;
    cout<<"Doctor: "<<pro.getDocName()<<endl;
    cout<<"Charge: $"<<fixed<<setprecision(2)<<pro.getCharges();
    
}