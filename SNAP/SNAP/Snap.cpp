
#include "Snap.h"

//------------------------------- Constructors -------------------------------------
Snap::Snap(){
    setStudentID("none");
    studentName = "none";
    studentAddress = "none";
    studentPhone = "none";
}

Snap::Snap(string newStudentID, string newStudentName, string newStudentAddress, string newStudentPhone){
    setStudentID(newStudentID);
    studentName = newStudentName;
    studentAddress = newStudentAddress;
    studentPhone = newStudentPhone;
}

//------------------------------- Getters  -------------------------------------
string Snap::getStudentName() const{
    
    return studentName;
}

string Snap::getStudentAddress() const{
    
    return studentAddress;
}

string Snap::getStudentPhone() const{
    
    return studentPhone;
}

//------------------------------- ToString and Operation Override -------------------------------------
string Snap::toString() const{
    stringstream OSS;
    
    OSS << "snap(" << getStudentID() << "," << getStudentName() << "," << getStudentAddress() << "," << getStudentPhone() << ")";
    
    return OSS.str();
}

ostream& operator<< (ostream& os, const Snap& myclass){
    
    os << myclass.toString();
    
    return os;
}
