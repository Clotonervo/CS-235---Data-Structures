
#ifndef Vector_h
#define Vector_h

#include "Deque.h"
#include <string>

template<typename T>
class Vector {
private:
    Deque<T> container_;
public:
    Vector() {}
    ~Vector() {}
    
    void push_back(const T& value){
        container_.push_back(value);
        return;
    }
    
    void pop_back(){
        return container_.pop_back();
    }
    
    size_t size() const{
        return container_.size();
    }
    
    T& at(size_t index){
        return container_.at(index);
    }
    
    string toString() const {
        std::stringstream OSS;
        
        OSS << container_.toString();
        
        return OSS.str();
    }
    
};

#endif /* Vector_hpp */
