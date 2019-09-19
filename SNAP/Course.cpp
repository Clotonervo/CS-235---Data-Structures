
#include "Course.h"

//------------------------------- Constructors -------------------------------------
Course::Course(){
    courseName = "none";
}

Course::Course(string newCourseName){
    courseName = newCourseName;
}

//------------------------------- Getters  -------------------------------------

string Course::getCourseName() const{
    
    return courseName;
}

//------------------------------- Setters  -------------------------------------
void Course::setCourseName(string newCourseName){
    
    courseName = newCourseName;
    
    return;
}

//------------------------------- ToString -------------------------------------
string Course::toString() const{
    stringstream OSS;
    
    OSS << getCourseName();
    
    return OSS.str();
}
