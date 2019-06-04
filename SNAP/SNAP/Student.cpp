//Student.cpp

#include "Student.h"

//------------------------------- Constructors -------------------------------------
Student::Student(){
    studentID = "none";
}

//------------------------------- Getters -------------------------------------
string Student::getStudentID() const{
    
    return studentID;
}

//------------------------------- Setters -------------------------------------
void Student::setStudentID(string ID){
    
    studentID = ID;
    
    return;
}

//------------------------------- ToString -------------------------------------
string Student::toString() const{
    stringstream OSS;
    
    OSS << getStudentID();
    
    return OSS.str();
}
