/* 
 * File:   inventory.h
 * Author: Jason Handen
 * Created on May 15, 2021, 6:30 PM
 * Purpose: Inventory header file
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using namespace std;

class Inventory{
    private:
        short itemNum;
        short quant;
        float cost;
        float totCost;
    public:
        Inventory();
        Inventory(short,short,float);
        short getItemNum();
        void setItemNum(short);
        short getQuant();
        void setQuant(short);
        float getCost();
        void setCost(float);
        float getTotCost();
        void setTotCost();
        short valCheck(short);
};


#endif /* INVENTORY_H */

