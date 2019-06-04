
#include "Cr.h"

//------------------------------- Constructors -------------------------------------
Cr::Cr(){
    courseRoom = "none";
    setCourseName("none");
}

Cr::Cr(string newCourseName, string room){
    courseRoom = room;
    setCourseName(newCourseName);
}

//------------------------------- Getters  -------------------------------------

string Cr::getRoom() const{
    
    return courseRoom;
}

//------------------------------- ToString and Operation Override -------------------------------------
string Cr::toString() const{
    stringstream OSS;
    
    OSS << "cr(" << getRoom() << "," << getCourseName() << ")";
    
    return OSS.str();
}

ostream& operator<< (ostream& os, const Cr& myclass){
    
    os << myclass.toString();
    
    return os;
}
