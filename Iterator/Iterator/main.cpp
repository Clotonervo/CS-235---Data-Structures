//MAIN


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <fstream>
#include "MyArray.h"
using namespace std;


/*************************************** MAIN *************************************************/
int main(int argc, char * argv[]){
    VS_MEM_CHECK               // enable memory leak check
    
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
    
    //------------------------------------ Creating the Array and Ouputting ---------------------------------
    
    MyArray<int> numbers(MAX_ARRAY_SIZE);
    
    int i;
    while (in >> i){
        numbers.push_back(i);
    }
    
    out << numbers << endl << endl;
    
    //----------------------------------- Outputting using Operator Override ----------------------------------------
 
    out << "SEQUENTIAL" << endl;
    MyArray<int>::Iterator iter1 = numbers.begin();
    out << "iter1: " << iter1 << endl;
    for (; iter1 != numbers.end(); ++iter1){
        out << *iter1 << ' ';
    }
    out << endl << endl;
    
    //------------------------------------------------ BONUS ---------------------------------------------------------
    out << "PRIME (Bonus)" << endl;
    MyArray<int>::Iterator iter2 = numbers.begin(PRIME);
    for (; iter2 != numbers.end(); ++iter2){
        out << *iter2 << ' ';
    }
    out << endl << endl;
    
    
    out << "COMPOSITE (Bonus)" << endl;
    MyArray<int>::Iterator iter3 = numbers.begin(COMPOSITE);
    for (; iter3 != numbers.end(); ++iter3){
        out << *iter3 << ' ';
    }
    out << endl << endl;
    
    return 0;
}
