/* 
 * File:   date.h
 * Author: Jason Handen
 * Created on May 15, 2021, 2:41 PM
 * Purpose: date class implementation file
 */

#include "date.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void Date::setDate(short month,short day,short year){
    date[0]=Date::valCheck(month,1,12);
    date[1]=Date::valCheck(day,1,31);
    date[2]=Date::valCheck(year,-10000,10000);
}
short Date::valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}
void Date::strSet(){
    switch(date[0]){
        case 1: mnthStr="January";break;
        case 2: mnthStr="February";break;
        case 3: mnthStr="March";break;
        case 4: mnthStr="April";break;
        case 5: mnthStr="May";break;
        case 6: mnthStr="June";break;
        case 7: mnthStr="July";break;
        case 8: mnthStr="August";break;
        case 9: mnthStr="September";break;
        case 10: mnthStr="October";break;
        case 11: mnthStr="November";break;
        case 12: mnthStr="December";break;
    }
}
void Date::dtNumb(){
    printf("%d/%d/%d\n",date[0],date[1],date[2]);
}
void Date::dtMonth(){
    Date::strSet();
    cout<<mnthStr;
    printf(" %d, %d\n",date[1],date[2]);
}
void Date::dtDay(){
    Date::strSet();
    cout<<date[1]<<" "<<mnthStr<<" "<<date[2];
}