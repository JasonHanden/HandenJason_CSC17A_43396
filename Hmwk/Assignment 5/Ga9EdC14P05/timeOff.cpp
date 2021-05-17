/* 
 * File:   timeOff.h
 * Author: Jason Handen
 * Created on May 16, 2021, 4:33 PM
 * Purpose: TimeOff source file
 */

#include "timeOff.h"
using namespace std;


TimeOff(){
    // no action by default
}
void TimeOff::setMxSckDy(short sickDay){
    mxSckDy.setNumHour(sickDay);
}
short TimeOff::getMxSckDy(){
    return mxSckDy.getNumDays();
}
void TimeOff::setSckTake(short sickTk){
    sckTake.setNumHour(sickTk);
}
short TimeOff::getSckTake(){
    return sckTake.getNumDays();
}
void TimeOff::setVacMax(short max){
    max=valCheck(max,0,240);
    vacMax.setNumHour(max);
}
short TimeOff::getVacMax(){
    return vacMax.getNumDays();
}
void TimeOff::setVacTakn(short vac){
    vacTakn.setNumHour(vac);
}
short TimeOff::getVacTakn(){
    return vacTakn.getNumDays();
}
void TimeOff::setUnpMax(short unpM){
    unpMax.setNumHour(unpM);
}
short TimeOff::getUnpMax(){
    return unpMax.getNumDays();
}
void TimeOff::setUnpTakn(short unpT){
    unpTakn.setNumHour(unpT);
}
short TimeOff::getUnpTakn(){
    return unpTakn.getNumDays();
}

short TimeOff::valCheck(short value,const short MIN,const short MAX){
    while(value<MIN || value>MAX){
        cout<<"Please choose a valid entry between "<<MIN<<" and "<<MAX<<": ";
        cin>>value;
    }
    return value;
}