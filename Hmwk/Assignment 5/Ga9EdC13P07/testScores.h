/* 
 * File:   testScores.h
 * Author: Jason Handen
 * Created on May 15, 2021, 7:17 PM
 * Purpose: Test scores header file
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores{
    private:
        float scores[3];
        float average;
    public:
        TestScores(float,float,float);
        float getAverage();
};

#endif /* TESTSCORES_H */

