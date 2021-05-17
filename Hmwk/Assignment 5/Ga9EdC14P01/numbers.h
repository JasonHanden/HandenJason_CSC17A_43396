/* 
 * File:   numbers.h
 * Author: Jason Handen
 * Created on May 15, 2021, 7:44 PM
 * Purpose: numbers class header file
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include<string>
using namespace std;

class Numbers{
    private:
        short number;
        string prntStr;
    public:
        Numbers(short);
        void prep();
        void print();
        short valCheck(short,const short,const short);
};

#endif /* NUMBERS_H */

