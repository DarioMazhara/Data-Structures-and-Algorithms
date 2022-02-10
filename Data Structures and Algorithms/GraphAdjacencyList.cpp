//
//  GraphAdjacencyList.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/6/22.
//


//Weighted directed graph

#include <iostream>

template <typename T> struct AdjNode {
    T value;
    int cost;
    AdjNode* next;
};

template <typename T>
struct GraphEdge {
    T start_ver;
    T end_ver;
    int weight;
};

template <typename T> class Graph {
    
    //insert news into adjcancey list from a graph
    
    AdjNode<T>* getAdjNode(T value, T weight, AdjNode<T>* head) {
        AdjNode<T>* newnode = new AdjNode<T>;
        newnode->value = value;
        newnode->cost = weight;
        
        newnode->next = head;
        
        return newnode;
    }
    
    int nodes; // number of nodes in graph
    
public:
    AdjNode<T>** head; // double pointer, represents all of the vertices in the grapih
    
    
    Graph(GraphEdge<T> edges[], int n, int nodes) {
        //initialize an empty linked list of size nodes that will hold the vertices
        //in graph it create all the vertices
        head = new AdjNode<T>*[nodes](); //declare head as a pointer to adjacent nodes of size nodes
        this->nodes = n;
        for (int i = 0; i < nodes; i++) {
            head[i] = nullptr;
        }
        
        //contruct a directed graph by adding edges between the vertices
        for (int i = 0; i < n; i++) {
            T start_vertex = edges[i].start_ver;
            T end_vertex = edges[i].end_ver;
            int weight = edges[i].weight;
            
            AdjNode<T>* newnode = getAdjNode(end_vertex, weight, head[start_vertex]);
            
            head[start_vertex] = newnode;
        }
                    
    }
    
    //prints all adjacent vertices of a given vertex
    void print_adjacencylist(AdjNode<T>* ptr, int i) {
        while (ptr != nullptr) {
                std::cout << i << " | " << ptr->value << " | "
            << ptr->cost << " ----> ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};
