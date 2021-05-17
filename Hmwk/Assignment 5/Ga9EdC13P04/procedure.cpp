
/* 
 * File:   procedure.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 4:14 PM
 * Purpose: Procedure class file
 */

#include "procedure.h"
using namespace std;

Procedure::Procedure(string pName,string pDate,string dName,float charg){
    proName=pName;
    proDate=pDate;
    docName=dName;
    charges=charg;
}
string Procedure::getProName(){
    return proName;
}
void Procedure::setProName(string pName){
    proName=pName;
}
string Procedure::getProDate(){
    return proDate;
}
void Procedure::setProDate(string pDate){
    proDate=pDate;
}
string Procedure::getDocName(){
    return docName;
}
void Procedure::setDocName(string dName){
    docName=dName;
}
float Procedure::getCharges(){
    return charges;
}
void Procedure::setCharges(float charg){
    charges=charg;
}