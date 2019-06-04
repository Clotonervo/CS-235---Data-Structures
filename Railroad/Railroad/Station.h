
#ifndef Station_h
#define Station_h

#include <string>
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

template <typename T>
class Station {
private:
    Vector<T> train_;
    Stack<T> stack_;
    Queue<T> queue_;
    T turnTableCar_;
    bool empty;
    
public:
    Station(){
        empty = true;
    }
    ~Station() {}
    
    string addCar(T& value) {
        if (empty){
            empty = false;
            turnTableCar_ = value;
            return "OK";
        }
        else{
            return "Turntable Occupied!";
        }
    }
    
    string removeCar(){
        if (empty){
            return "Turntable Empty!";
        }
        else {
            empty = true;
            train_.push_back(turnTableCar_);
         //   std::cout << "Queue: " << queue_.toString() << std::endl;
           // std::cout << "Stack: " << stack_.toString() << std::endl;
           // std::cout << "Train: " <<  train_.toString() << std::endl;
            
            return "OK";
        }
    }
    
    string topCar(){
        if (empty){
            return "Turntable Empty!";
        }
        else {
            return turnTableCar_;
        }
    }
    
    string addStack(){
        if (empty){
            return "Turntable Empty!";
        }
        else {
            empty = true;
            stack_.push(turnTableCar_);
         //   std::cout << "Queue: " << queue_.toString() << std::endl;
        //    std::cout << "Stack: " << stack_.toString() << std::endl;
            return "OK";
        }
    }
    
    string removeStack(){
        if (stack_.empty()){
            return "Stack is empty!";
        }
        else if (!empty){
            return "Turntable Occupied!";
        }
        else {
            empty = false;
            turnTableCar_ = stack_.top();
            stack_.pop();
            return "OK";
        }
    }
    
    T topStack(){
        return stack_.top();
    }
    
    size_t sizeStack(){
        return stack_.size();
    }
    
    string addQueue(){
        if(empty){
            return "Turntable Empty";
        }
        else{
            empty = true;
            queue_.push(turnTableCar_);
            return "OK";
        }
    }
    
    string removeQueue(){
        if (queue_.empty()){
            return "Queue is empty!";
        }
        else if (!empty){
            return "Turntable Occupied!";
        }
        else {
            empty = false;
            turnTableCar_ = queue_.top();
            queue_.pop();

            return "OK";
        }
    }
    
    T topQueue(){
        return queue_.top();
    }
    
    size_t sizeQueue(){
        return queue_.size();
    }
    
    string find(int trainName){
        bool found = false;
        std::stringstream OS;
        
        if (trainName == turnTableCar_){
            OS << "Turntable";
            return OS.str();
        }
        for (unsigned int i = 0; i < queue_.capacity(); i++){
            if (trainName == queue_.at(i)){
                found = true;
                OS << "Queue[" << i << "]";
                return OS.str();
            }
        }
        for (unsigned int i = 0; i < stack_.size(); i++){
            if (trainName == stack_.at(i)){
                found = true;
                OS << "Stack[" << i << "]";
                return OS.str();
            }
        }
        for (unsigned int i = 0; i < train_.size(); i++){
            if (trainName == train_.at(i)){
                found = true;
                OS << "Train[" << i << "]";
                return OS.str();
            }
        }

        return "Not Found!";
    }
    
    
    string toString() const {
        std::stringstream OS;
        OS << train_.toString();
        
        return OS.str();
    }
    
};




#endif /* Station_h */
