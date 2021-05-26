
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 3:54 PM
 * Purpose: Inheritance example
 */

#include <iostream>
#include "employee.h"
#include "productionworker.h"
using namespace std;

void prntEmp(Employee);
void prntProd(ProductionWorker);

int main(int argc, char** argv) {
    // driver function
    string name, hireDt;
    int numb, shift;
    float payRt;
    
    
    cout<<"Enter Employee Name: ";
    cin>>name;
    cout<<"Enter Employee Number: ";
    cin>>numb;
    cout<<"Enter Employee Hire Date: ";
    cin>>hireDt;
    
    Employee emp(name,numb,hireDt);
    
    cout<<"Enter Production Worker Shift (1 for day, 2 for night): ";
    cin>>shift;
    cout<<"Enter Production Worker Pay Rate: $";
    cin>>payRt;
            
    ProductionWorker prod(name,numb,hireDt,shift,payRt);
            
    cout<<"Employee Object from constructor:\n";
    prntEmp(emp);
    
    cout<<"Production Worker Object from constructor, same base content:\n";
    prntProd(prod);
    
    return 0;
}

void prntEmp(Employee emp){
    cout<<"Employee Name: "<<emp.getName()<<endl;
    cout<<"Employee Number: "<<emp.getNumb()<<endl;
    cout<<"Hire Date: "<<emp.getHireDt()<<endl<<endl;
}
void prntProd(ProductionWorker prod){
    cout<<"Production Worker Name: "<<prod.getName()<<endl;
    cout<<"Production Worker Number: "<<prod.getNumb()<<endl;
    cout<<"Hire Date: "<<prod.getHireDt()<<endl;
    cout<<"Production Worker Shift: ";
    if(prod.getShift()==1)
        cout<<"Day"<<endl;
    else
        cout<<"Night"<<endl;
    cout<<"Production Worker Pay Rate: $"<<prod.getPayRt()<<endl<<endl;
}