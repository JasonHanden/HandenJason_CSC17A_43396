
/* 
 * File:   employee.h
 * Author: Jason Handen
 * Created on May 25, 2021, 3:55 PM
 * Purpose: Employee header file
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee{
    protected:
        string name;
        int numb;
        string hireDt;
    public:
        Employee();
        Employee(string,int,string);
        void setName(string);
        void setNumb(int);
        void setHireDt(string);
        string getName();
        int getNumb();
        string getHireDt();
};



#endif /* EMPLOYEE_H */

