//
//  Node.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <stdio.h>
#pragma once

template <typename T> class Node {
public:
    T data;
    Node* next;
    
    Node() {
        next = NULL;
    }
    
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};


