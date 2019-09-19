// MAIN


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include "Cr.h"
#include "Cdh.h"
#include "Snap.h"
#include "Csg.h"
using namespace std;


//**************************************** MAIN ***********************************************************
int main(int argc, const char * argv[]) {
    
    VS_MEM_CHECK               // enable memory leak check
    
    if (argc < 3){
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    
    if (!in){
        cerr << "Unable to open " << argv[1] << " for input";
        return 1;                                                                   //the classic argc and argv files set up
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    
    if (!out){
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
    }
    
    //--------------------------------------------- Getting info --------------------------------------------------
    vector<Cr> crs;
    vector<Csg> csgs;
    vector<Cdh> cdhs;                                               //vectors of various classes
    vector<Snap> snaps;
    
    out << "Input Strings:" << endl;
    
    for (string line; getline(in, line);){                                      //reading in from files and assigning them to classes and vectors
        try{                                        //where the try starts
            if ("cr(" == line.substr(0, 3)){
                
                out << line << endl;
                
                string courseName = line.substr(3, line.find(',') - 3);
                line = line.substr(line.find(',') + 1);
                string room = line.substr(0, line.find(')'));
                crs.push_back(Cr(courseName, room));
                
                
            }
        
            else if ("csg(" == line.substr(0,4)){
                
                out << line << endl;
                
                string courseName = line.substr(4, line.find(',') - 4);
                line = line.substr(line.find(',') + 1);
                string studentID = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);                                             //i group these little sections for a cleaner look
                string studentGrade = line.substr(0, line.find(')'));
                csgs.push_back(Csg(studentID, studentGrade, courseName));
                
            }
        
            else if ("snap(" == line.substr(0,5)){
                
                out << line << endl;
                
                string studentID = line.substr(5, line.find(',') - 5);
                line = line.substr(line.find(',') + 1);
                string nameStudent = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string addressStudent = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string studentPhone = line.substr(0, line.find(')'));
                snaps.push_back(Snap(studentID, nameStudent, addressStudent, studentPhone));
                
            }
        
            else if ("cdh(" == line.substr(0,4)){
                
                out << line << endl;
                
                string courseName = line.substr(4, line.find(',') - 4);
                line = line.substr(line.find(',') + 1);
                string courseDay = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string courseTime = line.substr(0, line.find(')'));
                cdhs.push_back(Cdh(courseDay, courseTime, courseName));
                
            }
            
            else {
                throw (line);                                                   //error checking with the try/throw
            }
        }
        
        catch (string line) {                                                   //the catch
            cout << "Input error: Invalid input" << endl;
            out << line.substr(0, line.length() - 1) << " ** Undefined " << line << endl;
        }
    }
    
    //-------------------------------- Outputting vectors using ToString and Operation Override -----------------------------------------
    out << endl << "Vectors:" << endl;
    
    for (unsigned int i = 0; i < snaps.size(); i++){
        
        out << snaps[i] << endl;
    }
    
    for (unsigned int i = 0; i < csgs.size(); i++){                             //each using the toString function found in each class
                                                                                //each is using the operation override found in the class .cpp files
        out << csgs[i] << endl;
    }
    
    for (unsigned int i = 0; i < cdhs.size(); i++){
        
        out << cdhs[i] << endl;
    }
    
    for (unsigned int i = 0; i < crs.size(); i++){
        
        out << crs[i] << endl;
    }

    //--------------------------------------------- Course Grades --------------------------------------------------
    out << endl << "Course Grades: " << endl;
    
    for (unsigned int i = 0; i < crs.size(); i++){                                  //the number of courses
        for (unsigned int j = 0; j < csgs.size(); j++){
            if (csgs[j].getCourseName() == crs[i].getCourseName()){                 //getting the course name
                
                out << csgs[j].getCourseName() << " ";
                
                for (unsigned int k = 0; k < cdhs.size(); k++){
                    if (cdhs[k].getCourseName() == crs[i].getCourseName()){         //getting the days of one course
                        
                        out << cdhs[k].getDay();
                    }
                }
                out << ", " << crs[i].getRoom() << " ";                             //getting the room
                
                for (unsigned int k = 0; k < snaps.size(); k++){
                    if (csgs[j].getStudentID() == snaps[k].getStudentID()){
                        
                        out << snaps[k].getStudentName() << " " << snaps[k].getStudentID() << ", " << csgs[j].getStudentGrade() << endl;    //assigning it to a student
                    }
                }
            }
        }
        out << endl;
    }
  
    //--------------------------------------------- Student Schedules --------------------------------------------------
    out << "Student Schedules: " << endl;
    
    for (unsigned int i = 0; i < snaps.size(); i++){         //this gets fairly sticky but ill guide you through it
        
        out << snaps[i].getStudentName() << ", " << snaps[i].getStudentID() << ", " << snaps[i].getStudentAddress() << ", " << snaps[i].getStudentPhone() << endl;
                                                                                                    //^^ this is simply the student information
        for (unsigned int j = 0; j < csgs.size(); j++){                                             //number of grades
            if (snaps[i].getStudentID() == csgs[j].getStudentID()){
                
                out << "  " << csgs[j].getCourseName() << " ";                              //getting course name
                
                int timeCounter = 0;                                                        //this makes sure you only get all the days, yet the time only once
                
                for (unsigned int k = 0; k < cdhs.size(); k++){
                    if (csgs[j].getCourseName() == cdhs[k].getCourseName()){            //getting all the days of the course
                        
                        out << cdhs[k].getDay();
                    }
                }
                for (unsigned int k = 0; k < cdhs.size(); k++){
                    if ((csgs[j].getCourseName() == cdhs[k].getCourseName()) && (timeCounter == 0)){    //where we get the time only once, using timeCounter
                        
                        out << " " << cdhs[k].getTime() << ", ";
                        timeCounter++;
                    }
                }
                for (unsigned int k = 0; k < crs.size(); k++){
                    if (crs[k].getCourseName() == csgs[j].getCourseName()){                             //getting the room of the course
                        
                        out << crs[k].getRoom() << endl;
                    }
                }
            }
        }
        out << endl;
    }

    return 0;                                       //end of main
}
