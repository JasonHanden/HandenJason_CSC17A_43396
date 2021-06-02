/* 
 * File:   Round.h
 * Author: Jason Handen
 * Created on May 30, 2021, 9:14 PM
 * Purpose: Round header file
 */

#ifndef ROUND_H
#define ROUND_H


class Round{
    private:
        short rndNum;
        short betType;
        float betAmnt;
        short sumPlyr;
        short sumBnkr;
        short result;
        float payout;
    public:
        enum bets{PLAYER=1,BANKER,TIE};
        class BadValueEx{};

        Round();
        static short getCount();
        bool compBetResult();
        
        short getRndNum();
        short getBetType();
        float getBetAmnt();
        short getSumPlyr();
        short getSumBnkr();
        short getResult();
        float getPayout();
        
        void setRndNum(short);
        void setBetType(short);
        void setBetAmnt(float);
        void setSumPlyr(short);
        void setSumBnkr(short);
        void setResult(short);
        void setPayout(float);

        template<class T> void valCheck(T,const short,const short);
        template<class T> void valCheck(T,const short);
};

#endif /* ROUND_H */