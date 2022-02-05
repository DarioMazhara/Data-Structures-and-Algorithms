//
//  main.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/4/22.
//

#include <iostream>
#include <stdio.h>
#include "LinkedList.cpp"
#include <string>
#include <utility>
#include "DLinkedList.cpp"
#include "DoublyNode.cpp"
#include "CircularLinkedList.cpp"
using namespace std;





int main(int argc, const char * argv[]) {
    // insert code here...
    
    DLinkedList<string>* dll = new DLinkedList<string>();
    CircularLinkedList<string>* cll = new CircularLinkedList<string>();
    
    DNode<string>* dn1 = new DNode<string>("dario");
    DNode<string>* dn2 = new DNode<string>("rose");
    DNode<string>* dn3 = new DNode<string>("ethan");
    DNode<string>* dn4 = new DNode<string>("krishan");
    DNode<string>* dn5 = new DNode<string>("alex");
    
    Node<string>* cn1 = new Node<string>("dario1");
    Node<string>* cn2 = new Node<string>("rose");
    Node<string>* cn3 = new Node<string>("ethan");
    Node<string>* cn4 = new Node<string>("krishan");
    Node<string>* cn5 = new Node<string>("alex");
    Node<string>* cn6 = new Node<string>("javesh");
    
    dll->add(dn1);
    dll->add(dn2);
    dll->add(dn3);
    dll->add(dn4);
    
    cll->add(cn1);
    cll->add(cn2);
    cll->add(cn3);
    cll->add(cn4);
    cll->add(cn5);
    
    cll->print_all_data();
    
    cout << "  " << endl;
    
    cll->insert(cn6, 2);
    
    cll->print_all_data();
    
    cll->deletenode(cn5);
    
    cout << " " << endl;
    
    cll->print_all_data();
    
    
    cout << "     " << endl << cll->get_elements() << endl;
    
    cll->reverse();
    
    cout << " " << endl;
    
    
    cll->print_all_data();
    
    return 0;
}
