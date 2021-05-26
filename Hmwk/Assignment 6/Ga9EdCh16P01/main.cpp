
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 2:16 PM
 * Purpose: 
 */

#include <iostream>
#include <string>
#include "date.h"
using namespace std;

short valCheck(short,const short,const short);

int main(int argc, char** argv) {
    
    short month,day,year,response;
    Date date;
    
    cout<<"Enter a date as MM DD YYYY: ";
    cin>>month>>day>>year;
    try{
        date.setDate(month,day,year);
        
        cout<<"How would you like the day displayed?\n"
            <<"1. MM/DD/YYYY\n"
            <<"2. Month DD, YYYY\n"
            <<"3. DD Month YYYY\n";
        cin>>response;
        response=valCheck(response,1,3);

        switch(response){
            case 1:date.dtNumb();break;
            case 2:date.dtMonth();break;
            case 3:date.dtDay();break;
        }

    }
    catch(Date::InvalidDay){
        cout<<"Error: An invalid day was entered.\n";
    }
    catch(Date::InvalidMonth){
        cout<<"Error: An invalid month was entered.\n";
    }
        
    return 0;
}

short valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}