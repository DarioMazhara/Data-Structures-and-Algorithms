//
//  IntersectionLinkedList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/6/22.
//

#include "LinkedList.cpp"
#include "Node.cpp"
template <typename T> class IntersectionLinkedList {
    
public:
    
    static LinkedList<T>* intersection(LinkedList<T>* list,LinkedList<T>* list2) {
        
        int size1 = list->node_count();
        int size2 = list2->node_count();
        
        LinkedList<T>* newlist = new LinkedList<T>();
        
        Node<T>* temp = list->head;
        Node<T>* temp2 = list2->head;
        for (int i = 0; i < size1; i++) {
            temp2 = list2->head;
            for (int j = 0; j < size2; j++) {
                if (temp == temp2) {
                    newlist->add(new Node<T>(temp->data));
                }
                temp2 = temp2->next;
            }
        }
        
        return newlist;
    }
};


