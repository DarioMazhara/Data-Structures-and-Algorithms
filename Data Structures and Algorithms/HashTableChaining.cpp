//
//  HashTable_Using_LinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/5/22.
//

#include "HashTableChaining.hpp"
#include "LinkedList.cpp"
#pragma once


template <class T>
HashTable<T>::HashTable(int buckets) {
    this->bucket = buckets;
    
//    this->table = new array<LinkedList<T>, this->buckets>();
    this->table = new LinkedList<T>[buckets];

}


template <class T>
void HashTable<T>::insert(Node<T>* insert) {
    int index = hash(insert->data);
    
    table[index]->add(insert);
}

template <class T>
void HashTable<T>::remove(Node<T>* insert) {
    int index = hash(insert->data);
    
    table[index].deletenode(insert);
    
}
template <class T>
void HashTable<T>::print() {
    
    
    for (int i = 0; i < buckets; i++) {
        std::cout << i << " " << table[i]->print() << endl;
    }
}
