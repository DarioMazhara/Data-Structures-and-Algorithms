//
//  DLinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/5/22.
//

#include <stdio.h>
#include "DoublyNode.cpp"
#include <iostream>
using namespace std;
template <typename T> class DLinkedList {
public:
    DNode<T>* head;
    
    DNode<T>* tail;
    
    DLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    //adds element to end
    void add(DNode<T>* add) {
    
        if (head == NULL) {
            head = add;
            return;
        }
        if (tail == NULL) {
            tail = add;
            head->next = tail;
            tail->previous = head;
            return;
        }
        
        tail->next = add;
        add->previous = tail;
        tail = add;
        
    }
    
    void insert(DNode<T>* insert, double index) {
        if (head == NULL) {
            head = insert;
            return;
        }
        if (tail == NULL) {
            tail = insert;
            head->next = tail;
            tail->previous = head;
            return;
        }
        
        DNode<T>* temp = head;
        
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        
        DNode<T>* next = temp->next;
        temp->next = insert;
        next->previous = insert;
        insert->next = next;
        insert->previous = temp;
    }
    
    void deletenode(DNode<T>* remove) {
        
        if (remove == head) {
            head = head->next;
            head->previous = NULL;
            return;
        }
        
        if (remove == tail) {
            tail = tail->previous;
            tail->next = NULL;
            return;
        }
        
        DNode<T>* temp = head;
        
        while (temp->next != remove) {
            temp = temp->next;
        }
        
        //temp will be remove->previous
        
        DNode<T>* next = temp->next->next;
        
        temp->next = next;
        next->previous = temp;
        
        remove->next = NULL;
        remove->previous = NULL;
        
    }
    
    int get_elements() {
        DNode<T>* temp = head;
        
        int i = 1;
        while (temp != tail) {
            temp = temp->next;
            i++;
        }
        return i;
    }
    
    //reverse list; first node becomes last node, last becomes first
    void reverse() {
        DNode<T>** head_ref = &head;
        DNode<T>* temp = NULL;
        DNode<T>* curr = *head_ref;
        
        while (curr != NULL) {
            temp = curr->next;
            curr->next = curr->previous;
            curr->previous = temp;
            curr = curr->previous;
        }
        
        *head_ref = temp->previous;
        head = *head_ref;
    }
    
    void print() {
        
        DNode<T>* temp = head;
        
        while (temp != NULL) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
};
