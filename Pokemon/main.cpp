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
#include "Map.h"
#include "Set.h"
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
    
    
    while (in){
        string line;
        getline(in, line);
        out << line;
        
    }
    return 0;
}
