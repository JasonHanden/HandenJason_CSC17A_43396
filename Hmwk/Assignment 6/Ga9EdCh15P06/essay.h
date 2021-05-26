/* 
 * File:   essay.h
 * Author: Jason Handen
 * Created on May 25, 2021, 6:57 PM
 * Purpose: Essay class header file
 */

#ifndef ESSAY_H
#define ESSAY_H

#include "gradedactivity.h"
#include <string>
using namespace std;

class Essay:public GradedActivity{
    private:
        float grammar;
        float spelling;
        float length;
        float content;
    public:
        Essay(float,float,float,float);
        char getLetterGrade();
        float getGram();
        float getSpel();
        float getLeng();
        float getCont();
        float valCheck(float,const short,const short,string);
};


#endif /* ESSAY_H */

