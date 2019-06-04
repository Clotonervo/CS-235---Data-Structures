//This class basically contains all the student information

#ifndef Snap_h
#define Snap_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;

class Snap : public Student{
public:
    Snap();
    Snap(string newStudentID, string newStudentName, string newStudentAddress, string newStudentPhone);
    
    string getStudentName() const;
    string getStudentAddress() const;
    string getStudentPhone() const;
    
    string toString() const;
    friend ostream& operator<<(ostream& os, const Snap& myClass);
    
private:
    string studentName;
    string studentAddress;
    string studentPhone;
    
};
#endif /* snaps_hpp */
