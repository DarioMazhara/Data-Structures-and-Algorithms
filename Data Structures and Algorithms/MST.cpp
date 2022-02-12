//
//  MST.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/12/22.
//



//Algorithm finds the minimum spanning tree
//A spanning tree means all vertices are connected
//All vertices in a spanning tree must be connected with the minimum weight edge
//to become a minimum spanning tree
#include <stdio.h>
#include <iostream>
#include <math.h>


//this is the number of vertfices in a graph defined as 'V'

#define V 5

using namespace std;

class MST {
public:
    
    
    //Returns the smallest key out of the adjacent vertices of the current vertex
    int minKey(int key[], bool mstSet[]) {
        
        int min = INT_MAX, min_index;
        
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }
   //prints constructed mst
    void printMST(int parent[], int graph[V][V]) {
        
        cout << "Edge   Weight" << endl;
        
        for (int i = 1; i < V; i++) {
            cout << parent[i] << "   " << i << "    " << graph[i][parent[i]] << endl;
        }
        
    }
    //contructs and prints an MST for a graph represented by adjacency matrix
    void primMST(int graph[V][V]) {
        
        //stores constructed mst
        int parent[V];
        
        //key values to pick min edge
        int keys[V];
        
        //keeps track of vertices not already in the mst
        bool mstSet[V];
        
        //init all key values except first vertex as infinite
        for (int i = 0; i < V; i++) {
            keys[i] = INT_MAX;
            mstSet[i] = false;
        }
        
        keys[0] = 0;
        
        parent[0] = -1;
        
        //mst to have V vertices
        
        for (int v = 0; v < V-1; v++) {
                
            //pick minimum key vertex from vertices not yet included in mst
            int u = minKey(keys, mstSet);
            
            //vertex u now in mst
            mstSet[u] = true;
            
            //update key values and parent index of adjacent vertices NOT in mst
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < keys[v]) {
                    parent[v] = u;
                    keys[v] = graph[u][v];
                }
                    
            }
            
            printMST(parent, graph);
            
        }
        
        
    }
};

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                          { 2, 0, 3, 8, 5 },
                          { 0, 3, 0, 0, 7 },
                          { 6, 8, 0, 0, 9 },
                          { 0, 5, 7, 9, 0 } };
    
    MST* mst = new MST();
    
    mst->primMST(graph);
    
    return 0;
}
