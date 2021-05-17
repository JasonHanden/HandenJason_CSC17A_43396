
/* 
 * File:   retailItem.h
 * Author: Jason Handen
 * Created on May 15, 2021, 5:24 PM
 * Purpose: retail item header file
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>
using namespace std;

class RetailItem{
    private:
        string descrip;
        short units;
        float price;
    public:
        RetailItem(string,short,float);
        string getDescrip();
        void setDescrip(string);
        short getUnits();
        void setUnits(short);
        float getPrice();
        void setPrice(float);
};


#endif /* RETAILITEM_H */

