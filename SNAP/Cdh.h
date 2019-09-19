//Course, day, hour

#ifndef Cr_h
#define Cr_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Course.h"
using namespace std;

class Cdh : public Course{
public:
    Cdh();
    Cdh(string courseDay, string courseTime, string newCourseName);
    
    string getDay() const;
    string getTime() const;
    
    
    string toString() const;
    friend ostream& operator<<(ostream& os, const Cdh& myClass);

private:
    string day;
    string time;
    
};
#endif /* Cr_h */
