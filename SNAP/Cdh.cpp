//
//  Cdh.cpp
//  SNAP
//
//  Created by Sam Hopkins on 5/8/18.
//  Copyright © 2018 Sam Hopkins. All rights reserved.
//

#include "Cdh.h"

//------------------------------- Constructors -------------------------------------
Cdh::Cdh(){
    day = "none";
    time = "none";
    setCourseName("none");
}

Cdh::Cdh(string courseDay, string courseTime, string newCourseName){
    day = courseDay;
    time = courseTime;
    setCourseName(newCourseName);
}

//------------------------------- Getters  -------------------------------------
string Cdh::getDay() const{
    
    return day;
}

string Cdh::getTime() const{
    
    return time;
}

//------------------------------- ToString and Operator Override -------------------------------------
string Cdh::toString() const{
    stringstream OSS;
    
    OSS << "cdh(" << getCourseName() << "," << getDay() << "," << getTime() << ")";
    
    return OSS.str();
}

ostream& operator<< (ostream& os, const Cdh& myclass){
    
    os << myclass.toString();
    
    return os;
}
