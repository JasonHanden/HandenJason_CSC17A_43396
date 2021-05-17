/* 
 * File:   inventory.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 6:30 PM
 * Purpose: Inventory source file
 */

#include <iostream>
#include "inventory.h"
using namespace std;

Inventory::Inventory(){
    itemNum=0;
    quant=0;
    cost=0;
    totCost=0;
}
Inventory::Inventory(short i,short q,float c){
    itemNum=valCheck(i);
    quant=valCheck(q);
    cost=valCheck(c);
    Inventory::setTotCost();
}
short Inventory::getItemNum(){
    return itemNum;
}
void Inventory::setItemNum(short i){
    itemNum=valCheck(i);
}
short Inventory::getQuant(){
    return quant;
}
void Inventory::setQuant(short q){
    quant=valCheck(q);
}
float Inventory::getCost(){
    return cost;
}
void Inventory::setCost(float c){
    cost=valCheck(c);
}
float Inventory::getTotCost(){
    return totCost;
}
void Inventory::setTotCost(){
    totCost=cost * (float)quant;
}

short Inventory::valCheck(short value){
    const short MIN=0;
    while(value<MIN){
        cout<<"Please choose a valid entry Zero or greater: ";
        cin>>value;
    }
    return value;
}