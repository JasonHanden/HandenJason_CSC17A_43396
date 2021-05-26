/* 
 * File:   employee.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 3:54 PM
 * Purpose: Employee source file
 */

#include <string>
#include <valarray>
#include "employee.h"
using namespace std;


Employee::Employee(){
    
}
Employee::Employee(string nm,int nb,string hrdt){
    name=nm;
    numb=nb;
    hireDt=hrdt;
}
void Employee::setName(string nm){
    name=nm;
}
void Employee::setNumb(int nb){
    numb=nb;
}
void Employee::setHireDt(string hrdt){
    hireDt=hrdt;
}
string Employee::getName(){
    return name;
}
int Employee::getNumb(){
    return numb;
}
string Employee::getHireDt(){
    return hireDt;
}