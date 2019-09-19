//This class contains grades, studentID, and course info. It is derived from both the Student and Course parent classes

#ifndef Csg_h
#define Csg_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Course.h"
#include "Student.h"
using namespace std;

class Csg : public Student, public Course{
public:
    
    Csg();
    Csg(string courseStudentID, string courseGrade, string newCourseName);
    
    string getStudentGrade() const;
    
    string toString() const;
    friend ostream& operator<<(ostream& os, const Csg& myClass);

private:
    string studentGrade;
    
};
#endif /* csg_h */
