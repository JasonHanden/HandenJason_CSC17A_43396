
/* 
 * File:   productionworker.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 4:10 PM
 * Purpose: Production worker source
 */

#include <string>
#include "productionworker.h"
using namespace std;

ProductionWorker::ProductionWorker(){
    
}
ProductionWorker::ProductionWorker(int shft,float rt){
    shift=shft;
    payRt=rt;
}
ProductionWorker::ProductionWorker(string nm,int nb,string hrdt,
                                                        int shft,float rt){
    name=nm;
    numb=nb;
    hireDt=hrdt;
    shift=shft;
    payRt=rt;
}
int ProductionWorker::getShift(){
    return shift;
}
float ProductionWorker::getPayRt(){
    return payRt;
}
void ProductionWorker::setShift(int shft){
    shift=shft;
}
void ProductionWorker::setPayRt(int rt){
    payRt=rt;
}