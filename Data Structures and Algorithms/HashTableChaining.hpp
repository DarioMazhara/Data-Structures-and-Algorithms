//
//  HashTable_Using_LinkedList.hpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/5/22.
//

#ifndef HashTableChaining_hpp
#define HashTableChaining_hpp

#include <stdio.h>
#include "LinkedList.cpp"
#include "Node.cpp"
#include <array>

//Chaining hashtable

template <typename T> class HashTable {
public:
    HashTable(); //default constructor
    HashTable(int); //one parameter constructor
    
    
    
    void insert(Node<T>*);
    void remove(Node<T>*);
    void print();
    
    int hash(int x) {
        return (x%buckets);
    }
    
private:
    int buckets;
    LinkedList<T>* table[];
    
};
#endif /* HashTableChaining_hpp */
