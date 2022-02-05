//
//  CircularDoubleLinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/5/22.
//

#include <stdio.h>
#include <iostream>
#include "DoublyNode.cpp"

using namespace std;

template <typename T> class CircularDoubleLinkedList {
public:
    DNode<T>* head;
    DNode<T>* tail;
    
    CircularDoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
   
    //add to the end of linked list
    void add(DNode<T>* add) {
        if (head == NULL) {
            head = add;
            return;
        }
        if (tail == NULL) {
            tail = add;
            tail->previous = head;
            tail->next = head;
            head->next = tail;
            head->previous = tail;
            return;
        }
        
        
        tail->next = (add);
        head->previous = (add);
        (add)->previous = tail;
        (add)->next = head;
        tail = add;
    }
    
    //add node at index (so node at that index will be pushed one up
    void insert(DNode<T>* insert, int index) {
         if (head == NULL) {
                   head = insert;
                   return;
               }
               if (tail == NULL) {
                   tail = insert;
                   tail->previous = head;
                   tail->next = head;
                   head->next = tail;
                   head->previous = tail;
                   return;
               }
        
        DNode<T>* temp = head;
        
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        
        insert->next = temp->next;
        insert->next->previous = insert;
        temp->next = insert;
        insert->previous = temp;
        
    }
    
    void deletenode(DNode<T>* remove) {
        if (remove == head) {
            tail->next = head->next;
            head->next->previous = tail;
            head = head->next;
            return;
        }
        if (remove == tail) {
            tail->previous->next = head;
            head->previous = tail->previous;
            tail = tail->previous;
            return;
        }
        
        DNode<T>* temp = head;
        while (temp != remove) {
            temp = temp->next;
        }
        
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
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
    
    void reverse() {
        DNode<T>* curr = head;
        DNode<T>* prev = curr->previous;
        DNode<T>* next = NULL;
    
        
        int i = 0;
        int j = get_elements();
        
        while (i < j) {
            i++;
            next = curr->next;
            curr->next = prev;
            curr->previous = next;
            curr = next;
            prev = curr;
            
        }
        
        
        i = 0;
        DNode<T>* tmp;
        while (i < j) {
            tmp = curr->previous;
            tmp->next = curr;
            curr = tmp;
            i++;
        }
        
        tail = curr;
        head = curr->next;
        
        
      
        
        

    }
    void print_all_data() {
        DNode<T>* i = head;
        
        while(i != tail) {
            std::cout << i->data << std::endl;
            i = i->next;
        }
        std::cout << tail->data << std::endl;
    }
    
};
