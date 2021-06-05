/* 
 * File:   Result.h
 * Author: Jason Handen
 * Created on May 31, 2021, 6:22 PM
 * Purpose: Result header file
 */

#ifndef RESULT_H
#define RESULT_H

#include "Round.h"

class Result{
    private:
        short rndTot=-1;
        short wins=0;
        short losses=0;
        float playerS$=0;
        float playerE$=0;
    public:
        Round *round;
        class BadValueEx{};
        class BadRoundCount{};

        Result();
        Result(short);
        Result(Result&);
        ~Result();
        
        short getRndTot();
        short getWins();
        short getLosses();
        float getPlayerS$();
        float getPlayerE$();

        void setRndTot(short);
        void setWins(short);
        void setLosses(short);
        void setPlayerS$(float);
        void setPlayerE$(float);
        void addWin();
        void addLoss();

        template<class T> void valCheck(T,const short,const short);
        template<class T> void valCheck(T,const short);
};

#endif /* RESULT_H */