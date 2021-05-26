
/* 
 * File:   gradedactivity.h
 * Author: Jason Handen
 * Created on May 25, 2021, 6:41 PM
 * Purpose: Graded Activity header file
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity{
    protected:
        float score;
    public:
        GradedActivity();
        virtual ~GradedActivity();
        GradedActivity(float);
        float getScore();
        void setScore(float);
        virtual char getLetterGrade();
};


#endif /* GRADEDACTIVITY_H */

