/* 
 * File:   patient.h
 * Author: jason
 * Created on May 15, 2021, 3:45 PM
 * Purpose: Patient header file
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient{
    private:
        string name[3]; //first, middle, last name
        string locale[4]; //address, city, state, ZIP
        string phnNumb; //phone number
        string emerCon[2]; //emergency contact name, phone number
    public:
        Patient(string,string,string,string,string,string,string,string,
                                                                string,string);
        string* getName();
        void setName(string,string,string);
        string* getLocale();
        void setLocale(string,string,string,string);
        string getPhnNumb();
        void setPhnNumb(string);
        string* getEmerCon();
        void setEmerCon(string,string);
};


#endif /* PATIENT_H */

