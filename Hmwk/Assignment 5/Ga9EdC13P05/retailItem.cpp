/* 
 * File:   retailItem.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 5:24 PM
 * Purpose: retail item source file
 */

#include "retailItem.h"
using namespace std;

RetailItem::RetailItem(string des,short un,float pr){
    descrip=des;
    units=un;
    price=pr;
}
string RetailItem::getDescrip(){
    return descrip;
}
void RetailItem::setDescrip(string des){
    descrip=des;
}
short RetailItem::getUnits(){
    return units;
}
void RetailItem::setUnits(short un){
    units=un;
}
float RetailItem::getPrice(){
    return price;
}
void RetailItem::setPrice(float pr){
    price=pr;
}