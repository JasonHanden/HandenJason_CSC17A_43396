
/* 
 * File:   productionworker.h
 * Author: Jason Handen
 * Created on May 25, 2021, 4:10 PM
 * Purpose: Production worker header
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "employee.h"

class ProductionWorker:public Employee{
    private:
        int shift;
        float payRt;
    public:
        ProductionWorker();
        ProductionWorker(int,float);
        ProductionWorker(string,int,string,int,float);
        int getShift();
        float getPayRt();
        void setShift(int);
        void setPayRt(int);
};

#endif /* PRODUCTIONWORKER_H */

