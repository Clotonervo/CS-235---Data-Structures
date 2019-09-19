//Course info

#ifndef Course_h
#define Course_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Course{
public:
    Course();
    Course(string newCourseName);
    
    string getCourseName() const;
    
    void setCourseName(string newCourseName);
    
    virtual string toString() const;
    
private:
    string courseName;
    
};
#endif /* Course_hpp */
