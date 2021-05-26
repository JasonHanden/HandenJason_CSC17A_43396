
/* 
 * File:   gradedactivity.cpp
 * Author: Jason Handen
 * Created on May 25, 2021, 6:41 PM
 * Purpose: Graded Activity source file
 */

#include "gradedactivity.h"

GradedActivity::GradedActivity(){
    score = 0;
}
GradedActivity::~GradedActivity(){};

GradedActivity::GradedActivity(float s){
    score = s;
}
float GradedActivity::getScore(){
    return score;
}
void GradedActivity::setScore(float s){
    score = s;
}

char GradedActivity::getLetterGrade(){
    return 'z';
};