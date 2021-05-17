
/* 
 * File:   procedure.h
 * Author: Jason Handen
 * Created on May 15, 2021, 4:14 PM
 * Purpose: Procedure header file
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>
using namespace std;

class Procedure{
    private:
        string proName;
        string proDate;
        string docName;
        float charges;
    public:
        Procedure(string,string,string,float);
        string getProName();
        void setProName(string);
        string getProDate();
        void setProDate(string);
        string getDocName();
        void setDocName(string);
        float getCharges();
        void setCharges(float);
};


#endif /* PROCEDURE_H */

