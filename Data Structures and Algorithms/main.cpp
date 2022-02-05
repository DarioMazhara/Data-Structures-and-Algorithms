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
#include "CircularDoubleLinkedList.cpp"
using namespace std;





int main(int argc, const char * argv[]) {
    // insert code here...
    
    CircularDoubleLinkedList<string>* cdll = new CircularDoubleLinkedList<string>();
    
    DNode<string>* dn1 = new DNode<string>("dario");
    DNode<string>* dn2 = new DNode<string>("rose");
    DNode<string>* dn3 = new DNode<string>("ethan");
    DNode<string>* dn4 = new DNode<string>("krishan");
    
    cdll->add(dn1);
    cdll->add(dn2);
    cdll->add(dn3);
    cdll->add(dn4);
    
    cdll->print_all_data();
    
    cout << " " << endl;
    
    DNode<string>* dn5 = new DNode<string>("insert");
    
    cdll->insert(dn5, 3);
    
    cdll->print_all_data();
    
    cdll->deletenode(dn2);
    
    cout << " " << endl;
    
    cdll->print_all_data();
    
    cout << " " << endl;
    
    cdll->reverse();
    
    cdll->print_all_data();
    
    
    
    
    return 0;
}
