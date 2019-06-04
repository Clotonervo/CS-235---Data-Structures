#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**************** Base Class = Student ******************/

class Student {
public:
    Student(string initialName = "No Name") {
        name = initialName;
    }
    
    virtual void ToStr(){
        
       // for (int i=0; i < stuff.size(); i++){
            cout << name << " is an undergraduate student." << endl;
      //  }
        
        // Enter definition for a virtual ToStr member function here.
        return;
    }
    
protected:
    string name;
};

/**************** Derived Class = Grad Student ******************/

class GradStudent : public Student {
public:
    GradStudent(string realName, string rArea){
        name = realName;
        researchArea = rArea;
    };
    
    virtual void ToStr(){
       // for (int i=0; i < thing.size(); i++){
            cout << name <<" is a graduate student researching the area of " << researchArea << "." << endl;
      //  }
    }
    // Enter definition for a virtual ToStr member function here.
    
private:
    string researchArea;
};

/******************************** Main Class ***********************************/

int main() {
    string usrOption;
    string inpName;
    string inpResearch;
    vector<Student*> classMembers;
    
    do {
        cout << "Option: ";
        cin >> usrOption;
        cout << endl;
        if (usrOption == "print") {
           
            for (int i=0; i < classMembers.size(); i++){
                classMembers.at(i)->ToStr();
            }
            // Enter code here to print each member pointed to from classMembers using their respective ToStr member functions.            }
        }
        
        else if (usrOption == "add") {
            cout << "Name: ";
            cin >> inpName;
            cout << endl;
            cout << "If grad student enter a one word research area, else enter \"NO\": ";
            cin >> inpResearch;
            cout << endl;
           
            if (inpResearch == "NO"){
                
                Student* single = new Student(inpName);
                classMembers.push_back(single);
                
                for (int i=0; i < classMembers.size(); i++){
                    cout << classMembers.at(i);
                }
            }
            else {
                GradStudent* newGrad = new GradStudent(inpName, inpResearch);
                classMembers.push_back(newGrad);
                
                for (int i=0; i < classMembers.size(); i++){
                    cout << classMembers.at(i);
                }
            }
        }
    } while (usrOption != "quit");
    return 0;
}
