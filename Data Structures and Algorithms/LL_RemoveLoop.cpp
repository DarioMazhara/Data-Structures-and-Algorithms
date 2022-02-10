//
//  LL_RemoveLoop.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/9/22.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <set>
#include "LinkedList.cpp"

using namespace std;

//Detects and removes a loop in a linked list if it is present

class RL_LinkedList {
    
public:
    
    template <typename T> Node<T>* detect_loop(LinkedList<T>* list) {
        Node<T>* slow = list->head;
        Node<T>* fast = list->head;
        
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return fast;
            }
        }
        return NULL;
    }
    
    template <typename T> bool detect_remove (LinkedList<T>* list) {
        
        Node<T>* common = detect_loop(list);
        Node<T>* start;
        Node<T>* temp = list->head;
        if (common == NULL) {
            return false;
        }
        while (temp != NULL) {
            if (common->next == temp) {
                common->next = NULL;
                return true;
            }
            start = common->next;
            
            while (start != common) {
                if (start->next == temp) {
                    start->next = NULL;
                    return true;
                }
                start = start->next;
            }
            temp = temp->next;
        }
        
        
        return false;
    }
    
};

int main() {
    
    LinkedList<string>* ll = new LinkedList<string>();
    
    
    Node<string>* node1 = new Node<string>("Node 1");
    Node<string>* node2 = new Node<string>("Node 2");
    Node<string>* node3 = new Node<string>("Node 3");
    Node<string>* node4 = new Node<string>("Node 4");
    Node<string>* node5 = new Node<string>("Node 5");
    Node<string>* node6 = new Node<string>("Node 6");
    
    
    ll->add(node1);
    ll->add(node2);
    ll->add(node3);
    ll->add(node4);
    ll->add(node5);
    ll->add(node6);
    node6->next = node3;
    cout << node6->next->data << endl;
    RL_LinkedList rl;
    
    Node<string>* copy = rl.detect_loop(ll);
    
    cout << copy->data << endl;
    
    cout << rl.detect_remove(ll) << endl;
    
    cout << node6->next->data << endl;
}
