/* 
 * File:   patient.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 3:57 PM
 * Purpose: Patient source file
 */

#include "patient.h"

using namespace std;

Patient::Patient(string first,string middle,string last,string address,string city,
        string state,string zip,string numb,string emerNm,string emerPhn){
    name[0]=first;
    name[1]=middle;
    name[2]=last;
    
    locale[0]=address;
    locale[1]=city;
    locale[2]=state;
    locale[3]=zip;
    
    phnNumb=numb;
    
    emerCon[0]=emerNm;
    emerCon[1]=emerPhn;
}
        
string* Patient::getName(){
    return name;               //returns pointer to array
}
void Patient::setName(string first,string middle,string last){
    name[0]=first;
    name[1]=middle;
    name[2]=last;
}
string* Patient::getLocale(){
    return locale;             //returns pointer to array
}
void Patient::setLocale(string address,string city,string state,string zip){
    locale[0]=address;
    locale[1]=city;
    locale[2]=state;
    locale[3]=zip;
}
string Patient::getPhnNumb(){
    return phnNumb;             //returns string
}
void Patient::setPhnNumb(string numb){
    phnNumb=numb;
}
string* Patient::getEmerCon(){
    return emerCon;            //returns pointer to array
}
void Patient::setEmerCon(string emerNm,string emerPhn){
    emerCon[0]=emerNm;
    emerCon[1]=emerPhn;
}