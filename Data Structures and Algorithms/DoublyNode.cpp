//
//  DoublyNode.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <stdio.h>
#pragma once

template <typename T> class DNode {
    
public:
    T data;
    
    DNode<T>* next;
    
    DNode<T>* previous;
    
    DNode() {
        next = NULL;
        previous = NULL;
    }
    
    DNode(T data) {
        this->data = data;
        next = NULL;
        previous = NULL;
    }
    
};
