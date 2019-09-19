
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include "Station.h"
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
    Station<unsigned int> station;
    
    while (in){
        string line;
        getline(in, line);
        unsigned int train;
        
        if ("Add:stat" == line.substr(0,8)){
            cout << line.substr(0, line.length() - 1) << " ";
            line = line.substr(line.find(' ') + 1, line.length());
            istringstream temp(line);
            temp >> train;
            cout << station.addCar(train) << endl;;
        }
        else if ("Remove:stat" == line.substr(0,11)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.removeCar() << endl;
        }
        else if ("Add:stack" == line.substr(0,9)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.addStack() << endl;
        }
        else if ("Remove:stack" == line.substr(0,12)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.removeStack() << endl;
        }
        else if ("Top:stack" == line.substr(0,9)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.topStack() << endl;
        }
        else if ("Add:queue" == line.substr(0,9)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.addQueue() << endl;
        }
        else if ("Remove:queue" == line.substr(0,12)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.removeQueue() << endl;
        }
        else if ("Top:queue" == line.substr(0,9)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.topQueue() << endl;
        }
        else if ("Size:stack" == line.substr(0,10)){
            cout << line.substr(0,10) << " ";
            cout << station.sizeStack() << endl;
        }
        else if ("Size:queue" == line.substr(0,10)){
            cout << line.substr(0,10) << " ";
            cout << station.sizeQueue() << endl;
        }
        else if ("Find:" == line.substr(0,5)){
            cout << line.substr(0,6) << " ";
            line = line.substr(5,line.length());
            istringstream find(line);
            int value;
            find >> value;
            cout << station.find(value) << endl; 
        }

        
        
        
        
        
        
        
        else if ("Train:" == line.substr(0,6)){
            cout << line.substr(0, line.length() - 1) << " ";
            cout << station.toString() << endl;
        }
        else {
            continue;
        }
    }
    
    
    return 0;
}
