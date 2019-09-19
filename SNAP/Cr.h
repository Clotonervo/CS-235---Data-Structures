//Course, room

#ifndef Cdh_h
#define Cdh_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Course.h"
using namespace std;

class Cr : public Course{
public:
    Cr();
    Cr(string room, string courseName);
    
    string getRoom() const;

    string toString() const;
    friend ostream& operator<<(ostream& os, const Cr& myClass);
    
private:
    string courseRoom;
    
};
#endif /* cr_h */
