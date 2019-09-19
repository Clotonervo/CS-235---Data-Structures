
/*
 What else to do:
 - Clean up code a bit
 - Check for magic numbers
 - Figure out the rest of the crap you gotta do to turn it in
 - Check and see if the bonus is ok with code copying and pasting
 */


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
#include <string>
#include <iomanip>
using namespace std;


/****************************************** GET AVERAGE FUNCTION ****************************************/
double GetAverageScore(double** exam, int students, int index) {
    double average = 0.0;
    double sum = 0;
    
    for (int i = 0; i < students; i++) {
        
        sum += exam[i][index];
    }
                                                                                                        //this function gets the average of an exam
    average = sum / students;
    
    return average;
}

/************************************** MAIN *********************************************************/
int main(int argc, char* argv[]) {
    
    
    int const GRADE_SPACING = 6;
    int const NAME_SPACING = 20;
    int const DECIMAL = 1;
    int const NO_DECIMAL = 0;
    
    VS_MEM_CHECK               // enable memory leak check
    
    
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 1;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
    }
    
    /*-------------------------------------- SETTING UP THE ARRAYS -----------------------------------------------------------------------*/
    int numStudents;
    int numExames;
    
    in >> numStudents;
    in >> numExames;                                                    //initial number of students and exams
    in.ignore(numeric_limits<int>::max(), '\n');
    
    string *studentNames = new string[numStudents];
    double **studentScores = new double*[numStudents];                 //setting up array of scores
    
    for (int i = 0; i < numStudents; i++) {
        
        studentScores[i] = new double[numExames];
    }
    
    int i = 0;
    /*------------------------------------------- INITIALIZING ------------------------------------------------------------------*/
    
    while (i < numStudents) {
        string studentLine;
        getline(in, studentLine);
        size_t p = 0;                                                      //getting data from file
        while (!isdigit(studentLine[p])) {
            
            p++;
        }
        int const BEGINNING = 0;
        
        string nameLine = studentLine.substr(BEGINNING, p);
        string scoresLine = studentLine.substr(p);                         //splitting up the data into parts
        istringstream iss(scoresLine);
        
        for (int j = 0; j < numExames; j++) {
            
            iss >> studentScores[i][j];                                     //initializing score array
        }
        
        studentNames[i] = nameLine;                                         //initializing name array
        i++;
    }
    
    /*----------------------------------------------- EXAM AVERAGES -------------------------------------------------------------------------*/
    int const A_LOWER = 15;
    int const B_LOWER = 5;
    int const C_LOWER = 5;
    int const D_LOWER = 15;
    int const EXAM_INDEX_FIX = 1;
    
    out << "Exam Averages:" << endl;
    
    for (int i = 0; i < numExames; i++) {
        double examAverage = 0;
        
        examAverage = GetAverageScore(studentScores, numStudents, i);
        
        out << "Exam " << (i + EXAM_INDEX_FIX) << " average =" << fixed << setprecision(DECIMAL) << examAverage << setw(GRADE_SPACING);
        
        int gradeCounterA = 0;
        int gradeCounterB = 0;
        int gradeCounterC = 0;                                 //grade counters
        int gradeCounterD = 0;
        int gradeCounterE = 0;
        
        for (int j = 0; j < numStudents; j++) {
            
            if ((studentScores[j][i] >= examAverage + A_LOWER)) {
                gradeCounterA++;
            }
            
            else if ((studentScores[j][i] < examAverage + A_LOWER) && (studentScores[j][i] > examAverage + B_LOWER)) {
                gradeCounterB++;
            }                                                                                                           //getting the number of different grades
            
            else if ((studentScores[j][i] <= examAverage + B_LOWER) && (studentScores[j][i] >= examAverage - C_LOWER)) {
                gradeCounterC++;
            }
            
            else if ((studentScores[j][i] > examAverage - D_LOWER) && (studentScores[j][i] < examAverage - C_LOWER)) {
                gradeCounterD++;
            }
            
            else if ((studentScores[j][i] <= examAverage - D_LOWER)) {
                gradeCounterE++;
            }
        }
        
        out << gradeCounterA << "(A)" << setw(GRADE_SPACING) << gradeCounterB << "(B)" << setw(GRADE_SPACING) << gradeCounterC << "(C)" << setw(GRADE_SPACING) << gradeCounterD << "(D)" << setw(GRADE_SPACING) << gradeCounterE << "(E)" << endl;
    }                                                                                           //grade number output
    
    /*------------------------------------------------STUDENT EXAM GRADES-----------------------------------------------------------------*/
    out << "Student Exam Grades:" << endl;
    
    for (int i = 0; i < numStudents; i++) {
        
        out << setw(NAME_SPACING) << studentNames[i];
        double examAverage = 0.0;
        
        for (int j = 0; j < numExames; j++) {
            
            examAverage = GetAverageScore(studentScores, numStudents, j);
            out << fixed << setprecision(NO_DECIMAL) << setw(GRADE_SPACING) << studentScores[i][j];
            
            if ((studentScores[i][j] >= examAverage + A_LOWER)) {
                out << "(A)";
            }
            
            else if ((studentScores[i][j] < examAverage + A_LOWER) && (studentScores[i][j] > examAverage + B_LOWER)) {
                out << "(B)";                                                                                         //getting grade for individual test
            }
            
            else if ((studentScores[i][j] <= examAverage + B_LOWER) && (studentScores[i][j] >= examAverage - C_LOWER)) {
                out << "(C)";
            }
            
            else if ((studentScores[i][j] > examAverage - D_LOWER) && (studentScores[i][j] < examAverage - C_LOWER)) {
                out << "(D)";
            }
            
            else if ((studentScores[i][j] <= examAverage - D_LOWER)) {
                out << "(E)";
            }
            
            out << setw(GRADE_SPACING);
        }
        
        out << endl;
    }
    
    /*--------------------------------------------------------------BONUS------------------------------------------------------*/
    out << "**BONUS**" << endl;
    
    double classAverage = 0.0;
    double classSum = 0.0;
    
    for (int i = 0; i < numExames; i++) {
        
        classSum += GetAverageScore(studentScores, numStudents, i);
    }
    classAverage = classSum / numExames;
    
    out << "Class average: " << fixed << setprecision(DECIMAL) << classAverage << endl;                //getting class average
    out << "Student Final Exam Grade:" << endl;
    
    for (int i = 0; i < numStudents; i++) {
        double studentSum = 0.0;
        double studentAverage = 0.0;
        
        for (int j = 0; j < numExames; j++) {
            
            studentSum += studentScores[i][j];                                                          //getting student average
        }
        
        studentAverage = studentSum / numExames;
        out << setw(NAME_SPACING) << studentNames[i];
        out << setw(GRADE_SPACING) << studentAverage;
        
        if ((studentAverage >= classAverage + A_LOWER)) {
            out << "(A)";
        }
        
        else if ((studentAverage < classAverage + A_LOWER) && (studentAverage > classAverage + B_LOWER)) {
            out << "(B)";                                                                                         //resulting grade
        }
        
        else if ((studentAverage <= classAverage + B_LOWER) && (studentAverage >= classAverage - C_LOWER)) {
            out << "(C)";
        }
        
        else if ((studentAverage > classAverage - D_LOWER) && (studentAverage < classAverage - C_LOWER)) {
            out << "(D)";
        }
        
        else if ((studentAverage <= classAverage - D_LOWER)) {
            out << "(E)";
        }
        
        out << endl;
    }
    
    /*------------------------------------------- Deleting all the memory stuff --------------------------------------------*/
    
    for (int i = 0; i < numStudents; ++i)
    {
        delete[] studentScores[i];
    }                                                                                                   //preventing memory leakage
    delete[] studentScores;
    delete[] studentNames;
    
    return 0;
}



