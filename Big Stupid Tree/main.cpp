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
#include "BST.h"
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
    BST<int> tree;
    
    while (in){
        string function;
        in >> function;                                 //Getting input
        int value = 0;
        
        if (function == "Add"){             //add command
            in >> value;
            out << function << " " << value << " ";
            if(tree.addNode(value)){
                out << "True" << endl;
            }
            else {
                out << "False" << endl;
            }
        }
        else if (function == "PrintBST"){               //print command
            out << function;
            out << tree.toString() << endl;
        }
        else if (function == "Remove"){             //remove command
            in >> value;
            out << function << " " << value << " ";
            if (tree.removeNode(value)){
                out << "True" << endl;
            }
            else {
                out << "False" << endl;
            }
        }
        else if (function == "Clear"){                  //clear command
            out << function << " ";
            if (tree.clearTree()){
                out << "True" << endl;
            }
            else {
                out << "False" << endl;
            }
        }
  
    }
    

    return 0;
}
