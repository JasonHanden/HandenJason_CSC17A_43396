
/* 
 * File:   main.cpp
 * Author: Jason Handen
 * Created on May 15, 2021, 6:28 PM
 * Purpose: Problem 06 main file
 */

#include <iostream>
#include <iomanip>
#include "inventory.h"

using namespace std;

void prntInventory(Inventory,string);

int main(int argc, char** argv) {

    string type="With default constructor: ";
    Inventory item1;
    prntInventory(item1,type);
    
    cout<<"*****\n";
    
    type="With constructor arguments: ";
    Inventory item2(2,5,12.50);
    prntInventory(item2,type);
    
    return 0;
}

void prntInventory(Inventory item,string type){
    cout<<type<<endl;
    cout<<"Item Number: "<<item.getItemNum()<<endl;
    cout<<"Item Quantity: "<<item.getQuant()<<endl;
    cout<<"Item Cost per Unit: $"<<fixed<<setprecision(2)<<item.getCost()<<endl;
    cout<<"Inventory Total Cost: $"<<item.getTotCost()<<endl;
}