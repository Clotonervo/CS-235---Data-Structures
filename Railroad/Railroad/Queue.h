//
//  Queue.h
//  Railroad
//
//  Created by Sam Hopkins on 5/31/18.
//  Copyright © 2018 Sam Hopkins. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "Deque.h"
#include <string>

template<typename T>
class Queue {
private:
    Deque<T> containerQ;
public:
    Queue() {}
    ~Queue() {}
    
    void push(T& value){
        containerQ.push_back(value);
        return;
    }
    
    void pop(){
        containerQ.pop_front();
        return;
    }
    
    T& top(){
        return containerQ.front();
    }
    
    size_t size(){
        return containerQ.size();
    }
    
    T& at(size_t index){
        return containerQ.at(index);
    }
    
    bool empty(){
        return containerQ.empty();
    }
    size_t capacity(){
        return containerQ.storage();
    }
    
    string toString() const {
        return containerQ.toString();
    }
};

#endif /* Queue_h */
