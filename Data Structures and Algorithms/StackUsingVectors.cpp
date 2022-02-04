//
//  StackUsingVectors.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <stdio.h>
#include <vector>

using namespace std;

template <class T, class Container = vector<T>> class Stack {
    typedef Container vector;
public:
    T value;
    Container container;
    
    Stack() {
        
    }
    
    bool empty() const {
        return container.empty();
    }
    
    void push(const T& element) {
        container.push_back(element);
    }
    
    void pop() {
        container.pop_back();
    }
    
    int size() const{
        return container.size();
    }
    
    const T top() {
        return container.back();
    }
    
    
};
