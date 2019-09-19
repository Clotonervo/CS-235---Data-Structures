//


#include "Csg.h"

//------------------------------- Constructors -------------------------------------
Csg::Csg(){
    setStudentID("none");
    studentGrade = "none";
    setCourseName("none");
}

Csg::Csg(string courseStudentID, string courseGrade, string newCourseName){
    setStudentID(courseStudentID);
    studentGrade = courseGrade;
    setCourseName(newCourseName);
}

//------------------------------- Getters -------------------------------------
string Csg::getStudentGrade() const{
    
    return studentGrade;
}

//------------------------------- ToString and Operator Override -------------------------------------
string Csg::toString() const{
    stringstream OSS;
    
    OSS << "csg(" << getCourseName() << "," << getStudentID() << "," << getStudentGrade() << ")";
    
    return OSS.str();
}

ostream& operator<< (ostream& os, const Csg& myclass){
    
    os << myclass.toString();
    
    return os;
}
