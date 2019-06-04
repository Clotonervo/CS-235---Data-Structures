
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
#include "LinkedList.h"
using namespace std;

/*************************************** MAIN *************************************************/
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
    
    //------------------------------------ Creating Linked List ---------------------------------
    string line, item1;
    getline(in, line);
    istringstream iss(line);
    iss >> item1;
    
    //___________________________________________________________________________ Int Part
    if (item1 == "INT"){
        out << "INT [INT]" << endl;
        LinkedList<int> intList;
        
        while (in){
            string function;
            in >> function;
            
/********************* Head ****************************/
            if (function == "insertHead"){
                int nodeData = 0;
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (intList.insertHead(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************** Tail ***************************/
            else if (function == "insertTail"){
                int nodeData = 0;
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (intList.insertTail(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************* After X ****************************/
            else if (function == "insertAfter"){
                int nodeData = 0;
                int matchNode = 0;
                in >> matchNode >> nodeData;
                out << function << " " << matchNode << " " << nodeData << " ";
                
                if (intList.insertAfter(matchNode, nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/************************ Size *************************/
            else if (function == "size"){
                out << function << " ";
                out << intList.size() << endl;
            }
            
/******************* Print List (toString) ******************************/
            else if (function == "printList"){
                out << function << " " << intList.printList() << endl;
            }
            
/******************* At () ******************************/
            else if (function == "at"){
                int index = 0;
                in >> index;
                out << function << " " << index << " ";
                out << intList.at(index) << endl;
            }
            
/********************* Remove ****************************/
            else if (function == "remove"){
                int nodeData = 0;
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (intList.remove(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************** Clear ***************************/
            else if (function == "clear"){
                out << function << " ";
                
                if (intList.clear()){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
        }
        intList.~LinkedList();              //Destructor (freeing up memory)
    }
    
    //___________________________________________________________________________ String Part
    else {
        out << "STRING [STRING]" << endl;
        LinkedList<string> strList;
        
        while (in){
            string function;
            in >> function;
            
/********************* Head ****************************/
            if (function == "insertHead"){
                string nodeData = "none";
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (strList.insertHead(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************** Tail ***************************/
            else if (function == "insertTail"){
                string nodeData = "none";
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (strList.insertTail(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************* After X ****************************/
            else if (function == "insertAfter"){
                string nodeData = "none";
                string matchNode = "none";
                in >> matchNode >> nodeData;
                out << function << " " << matchNode << " " << nodeData << " ";
                
                if (strList.insertAfter(matchNode, nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/************************ Size *************************/
            else if (function == "size"){
                out << function << " ";
                out << strList.size() << endl;
            }
            
/******************* Print List (toString) ******************************/
            else if (function == "printList"){
                out << function << " " << strList.printList() << endl;
            }
            
/******************* At () ******************************/
            else if (function == "at"){
                try {
                    int index = 0;
                    in >> index;
                    out << function << " " << index << " ";
                    out << strList.at(index) << endl;
                }
                catch (...) {
                    out << endl;
                    std::cerr << "Out of Range error" << '\n';
                }
            }
            
/********************* Remove ****************************/
            else if (function == "remove"){
                string nodeData = "none";
                in >> nodeData;
                out << function << " " << nodeData << " ";
                
                if (strList.remove(nodeData)){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            
/********************** Clear ***************************/
            else if (function == "clear"){
                out << function << " ";
                
                if (strList.clear()){
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
        }
        strList.~LinkedList();              //Destructor (freeing up memory)
    }
    
    return 0;
}
