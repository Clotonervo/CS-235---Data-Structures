//This class contains just the Student ID, and is able to get and set it as called

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student{
public:
    Student();
    
    string getStudentID() const;
    
    void setStudentID(string ID);
    
    virtual string toString() const;
    
private:
    string studentID;
    
};
#endif /* Student_hpp */
