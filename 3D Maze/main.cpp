#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Maze.h"
using namespace std;

int main(int argc, const char * argv[]) {
    VS_MEM_CHECK;                           //allowing memory checker thingy
    
    if (argc < 3){
        cout << "Please provide name of input and output files" << endl;
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in){
        cout << "Unable to open " << argv[1] << " for input" << endl;
        return 1;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out){
        in.close();
        cout << "Unable to open " << argv[2] << " for output" << endl;
    }
    //------------------------------------------------------------------------------------
    int mazeHeight = 0;
    int mazeWidth = 0;
    int mazeDepth = 0;
    
    in >> mazeHeight;
    in >> mazeWidth;
    in >> mazeDepth;
    
    Maze puzzle(mazeHeight, mazeWidth, mazeDepth);          //creating dimentions for maze
    
    int tempHeight = 0;
    int tempWidth = 0;
    int tempDepth = 0;
    
    while (in){
        string line;
        getline(in, line);
        istringstream oneLine(line);
        int value = 6;

        if (oneLine >> value){
            puzzle.setValue(tempHeight, tempWidth, tempDepth, value);
            tempWidth++;
            while (oneLine >> value){
                puzzle.setValue(tempHeight, tempWidth, tempDepth, value);       //setting value of maze
                tempWidth++;
            }
            tempWidth = 0;
            tempHeight++;
            if (tempHeight == mazeHeight){
                tempHeight = 0;
                tempDepth++;
            }
        }
    }
    out << "Solve Maze: " << endl;
    out << puzzle.toString();
    if(puzzle.find_maze_path()){                //solving and outputting the maze
        out << endl << "Solution: " << endl;
        out << puzzle.toString();
    }
    else {
        out << endl << "No Solution Exists!" << endl;
    }
    
    return 0;
}
