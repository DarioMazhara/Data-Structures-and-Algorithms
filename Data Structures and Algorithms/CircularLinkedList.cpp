//
//  CircularLinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/5/22.
//

#include <iostream>
#include <stdio.h>
#include "Node.cpp"

template <typename T> class CircularLinkedList {
    
public:
    Node<T>* head;
    Node<T>* tail;
       
       CircularLinkedList() {
           head = NULL;
           tail = NULL;
       }
       
       void add(Node<T>* add) {

           if (head == NULL) {
               head = add;
               return;
           }
           if (tail == NULL) {
               tail = add;
               tail->next = head;
               head->next = tail;
               return;
           }
           
           tail->next = add;
           add->next = head;
           tail = add;
     //      tail->next = head;
    }
    int get_elements() {
        Node<T>* temp = head;
        
        int i = 1;
        while (temp != tail) {
            temp = temp->next;
            i++;
        }
        return i;
    }
    
    void insert(Node<T>* insert, double index = -1) {
        if (index == 0) {
            insert->next = head;
            tail->next = insert;
            head = insert;
            return;
        }
        if (index == get_elements()) {
            tail->next = insert;
            insert->next = head;
            return; 
        }
        
        Node<T>* temp = head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        insert->next = temp->next;
        temp->next = insert;
        
    }
       
       void deletenode(Node<T> * delete_node) {
           Node<T>* temp = head;
           
           if (delete_node == head) {
               tail->next = tail->next->next;
               head = head->next;
               return;
           }
           if (delete_node == tail) {
               while (temp->next != tail) {
                   temp = temp->next;
               }
               temp->next = head;
               tail = temp;
               return;
           }
           
           while (temp->next != delete_node) {
               temp = temp->next;
           }
           temp->next = temp->next->next;
           
       }
    
    
       
       Node<T>* search(Node<T>* find) {
           if (find == head) {
               return head;
           }
           
           Node<T>* temp = head;
           
           while (temp->next != find) {
               temp = temp->next;
           }
           
           return temp->next;
       }
    
    void reverse() {
        Node<T>* curr = head;
        Node<T>* prev = tail;
        Node<T>* next = NULL;
        
        int i = 0;
        int j = get_elements();
        while (i < j) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            
            curr = next;
            
            i++;
        }
        head = prev;
        tail = curr;
    }
       
       void print_all_data() {
           Node<T>* i = head;
           
           while(i != tail) {
               std::cout << i->data << std::endl;
               i = i->next;
           }
           std::cout << tail->data << std::endl;
       }
       
       void print_head() {
           std::cout << head->data << std::endl;
       }
};
