//
//  Stack.h
//  Railroad
//
//  Created by Sam Hopkins on 5/31/18.
//  Copyright © 2018 Sam Hopkins. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "Deque.h"
#include <string>

template<typename T>
class Stack {
private:
    Deque<T> container_;
public:
    Stack() {}
    ~Stack() {}
    
    void push(T& value){
        container_.push_front(value);
        return;
    }
    
    void pop(){
        container_.pop_front();
        return;
    }
    
    T& top(){
        return container_.front();
    }
    
    size_t size(){
        return container_.size();
    }
    
    T& at(size_t index){
        return container_.at(index);
    }
    
    bool empty(){
        return container_.empty();
    }
    
    string toString() const {
        return container_.toString();
    }
};

#endif /* Stack_h */
