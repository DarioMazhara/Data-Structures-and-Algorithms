//
//  LinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.cpp"

using namespace std;

template <typename T>
class LinkedList {
public:
    
    Node<T>* head;
    
    LinkedList() {
        head = NULL;
    }
    
    void add(Node<T>* add, double index = -1) {

        if (head == NULL) {
            head = add;
            return;
        }
        if (head->next == NULL) {
            head->next = add;
            return;
        }
        
        if (index == -1) {
            Node<T>* temp = head;
            
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = add;
            return;
        }
        
        Node<T> *temp = head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        
        Node<T>* temp2 = temp->next;
        
        temp->next = add;
        
        temp->next->next = temp2;
    }
    
    void deletenode(Node<T> * delete_node) {
        Node<T>* temp = head;
        
        if (delete_node == head) {
            head = head->next;
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
    
    void print_all_data() {
        Node<T>* i = head;
        
        while(i != NULL) {
            cout << i->data << endl;
            i = i->next;
        }
    }
    
    void print_head() {
        std::cout << head->data << std::endl;
    }
    
};
