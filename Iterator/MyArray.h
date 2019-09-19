
#ifndef MyArray_h
#define MyArray_h

#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

enum myMode { SEQUENTIAL, PRIME, COMPOSITE, FIB };
#define MAX_ARRAY_SIZE    1000

template<typename T>
class MyArray {
private:
    T* tempArray;                                       //private members of MyArray
    int size;
public:
    MyArray(const int ARRAY_SIZE) {
        size = 0;
        tempArray = new T [ARRAY_SIZE];                   //creating memory for our array
    }
    ~MyArray(){
        delete tempArray;                                 //freeing up the memory
    }
    
    void push_back(T item) {
        tempArray[size++] = item;
    }
    
    //--------------------------------- NESTED CLASS: Iterator ------------------------------
    class Iterator {
    public:
        Iterator(T* vec) {
            this->vec = vec;
        }
        Iterator(T* vec, int size) {
            this->vec = vec;
            this->size = size;
        }
        Iterator(T* vec, int size, int pointer) {
            this->vec = vec;
            this->size = size;
            this->pointer = pointer;
        }
        Iterator(T* vec, int size, int pointer, int mode) {                 //various constructors for the different modes
            this->vec = vec;
            this->size = size;
            
            if (mode == PRIME){
                for (unsigned int i = 0; i < size; i++){
                    if (isPrime(vec[i])){
                        this->pointer = i;
                        this->index = i + 1;
                        this->mode = mode;
                        break;
                    }
                }
            }
            else if (mode == COMPOSITE){
                for (unsigned int i = 0; i < size; i++){
                    if (!isPrime(vec[i])){
                        this->pointer = i;
                        this->index = i + 1;
                        this->mode = mode;
                        break;
                    }
                }
                
            }
        }
        bool operator!=(const Iterator& other) const {
            return (pointer != other.pointer);
        }
        
        bool isPrime(int number){
            int i;
            if (number < 2) return false;
            for (i = 2; i < number; ++i){
                if (number % i == 0) return false;
            }
            return true;
        }
        Iterator& operator++() {
            //---------------------------------------------------- PRIME
            if (mode == PRIME){
                for (unsigned int i = index; i < size + 1; i++){
                    if (index == size){
                        pointer = size;
                        break;
                    }
                    else if ((index == size - 1) && (isPrime(vec[size -1]))){               //outputting the prime number section
                        pointer = size - 1;
                        index++;
                        break;
                    }
                    else if (isPrime(vec[i])){
                        pointer = i;
                        index++;
                        break;
                    }
                    else {
                        index++;
                    }
                }
            }
            //---------------------------------------------------- COMPOSITE
            else if (mode == COMPOSITE){
                for (unsigned int i = index; i < size + 1; i++){
                    if (index == size){
                        pointer = size;
                        break;
                    }
                    else if ((index == size - 1) && (!isPrime(vec[size -1]))){                  //outputting the composite section
                        pointer = size - 1;
                        index++;
                        break;
                    }
                    else if (!isPrime(vec[i])){
                        pointer = i;
                        index++;
                        break;
                    }
                    else {
                        index++;
                    }
                }
            }
            //---------------------------------------------------- SEQUENTIAL
            else {
                pointer = pointer + 1;
            }
            
            return *this;
        }
        T& operator*() const {
            return vec[pointer];
        }
        T& operator[](int i) const {
            return vec[i];
        }
        string toString() const {                               //my toString function
            stringstream os;
            if (mode == PRIME){
                os << "(Bonus)";
            }
            else if (mode == COMPOSITE){
                os << "(Bonus)";
            }
            
            else{
                os << "size=" << size << " index=" << pointer << " mode=" << mode;          //so right here in the first input its required, but not in the others
            }
            return os.str();
        }
        friend ostream& operator<< (ostream& os, const Iterator& iter) {
            
            os << iter.toString();
            
            return os;
        }
        
    private:
        T* vec;
        int size;               //private members of the Iterator class
        int pointer;
        int mode;
        int index = 0;
    };
    //----------------------------- ^^ End of Iterator class ^^ ---------------------------------------------
    
    Iterator begin() {
        return MyArray<T>::Iterator(tempArray,size,0);
    }
    Iterator begin(myMode mode) {
        return MyArray<T>::Iterator(tempArray,size, 0, mode);
    }
    
    Iterator end() {
        return MyArray<T>::Iterator(tempArray,size,size);
    }
    
    string toString() const {
        stringstream os;
        
        os << "MyArray" << endl;
        for (int i = 0; i < size; i++){
            os << tempArray[i] << " ";
            if ((i + 1) % 10 == 0){
                os << endl;
            }
        }
        
        return os.str();
    }
    friend ostream& operator<< (ostream& os, const MyArray<T>& myArray) {
        
        os << myArray.toString();
        
        return os;
    }
};

#endif /* MyArray_h */
