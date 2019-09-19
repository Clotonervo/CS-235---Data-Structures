

#ifndef Deque_h
#define Deque_h

#include "DequeInterface.h"

template<typename T>
class Deque : public DequeInterface<T> {
private:
    size_t capacity;
    size_t numItems;
    size_t frontIndex;
    size_t rearIndex;
    T* data;
    void reallocate(){
        T* temp = new T[capacity * 2];
        int j = 0;
        for (size_t i = frontIndex; j < numItems; i = (i + 1) % capacity){
            temp[j] = data[i];
            j++;
        }
        capacity = capacity * 2;
        frontIndex = 0;
        rearIndex = numItems - 1;
        delete data;
        data = temp;
        }
    
public:
    static const size_t DEFAULT_CAPACITY = 4;

    Deque() {
        frontIndex = 0;
        numItems = 0;
        rearIndex = 0;
        data = new T[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
    }
    ~Deque() {
       // delete data;
    }
    
    /****************************** Insert item at front of deque *****************************/
    void push_front(const T& value){
        if (numItems == capacity){
            reallocate();
            
            frontIndex = (frontIndex - 1) % capacity;
            data[frontIndex] = value;
            numItems++;
          //  this->toString();
        }
        else if (frontIndex == 0 && rearIndex == 0 && empty()){
            data[frontIndex] = value;
            numItems++;
        }
        else{
            frontIndex = (frontIndex - 1) % capacity;
            data[frontIndex] = value;
            numItems++;
        }
    }
    
    /****************************** Insert item at rear of deque *****************************/
    void push_back(const T& value){
        if (numItems == capacity){
            reallocate();
            
            rearIndex = (rearIndex + 1) % capacity;
            data[rearIndex] = value;
            numItems++;
           // this->toString();
        }
        else if (rearIndex == 0 && frontIndex == 0 && empty()){
            data[rearIndex] = value;
            numItems++;
        }
        else {
            rearIndex = (rearIndex + 1) % capacity;
            data[rearIndex] = value;
            numItems++;
        }
    }
    
    /****************************** Remove the front item of the deque *****************************/
    void pop_front(){
        if (empty()){
            return;
        }
        else {
            frontIndex = (frontIndex + 1) % capacity;
            numItems--;
            return;
        }
    }
    
    /****************************** Remove the rear item of the deque *****************************/
    void pop_back(){
        if (empty()){
            return;
        }
        else {
            rearIndex = (rearIndex - 1) % capacity;
            numItems--;
            return;
        }
    }
    
    /****************************** Return the front item of the deque (Do not remove) *****************************/
    T& front(){
        return data[frontIndex];
    }
    
    /****************************** Return the rear item of the deque (Do not remove) *****************************/
    T& back(){
        return data[rearIndex];
    }
    
    /****************************** Return the number of items in the deque *****************************/
    size_t size() const{
        return numItems;
    }
    
    /****************************** Return true if deque is empty *****************************/
    bool empty() const{
        if (numItems == 0){
            return true;
        }
        else {
            return false;
        }
    }
    
    /****************************** Return item in deque at index (0 based) *****************************/
    T& at(size_t index) {
        return data[index];
    }
    
    /****************************** Return the capacity of the deque *****************************/
    size_t storage(){
        return capacity;
    }
    
    /****************************** Return the deque items *****************************/
    string toString() const{
        std::stringstream OSS;
        
        int j = 0;
        for (size_t i = frontIndex; j < numItems; i = (i + 1) % capacity){
            std::cout << data[i] << " ";
            j++;
        }
        return OSS.str();
    }
};

#endif /* Deque_h */

