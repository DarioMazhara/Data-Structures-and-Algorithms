#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

// BFS of a graph using adjacency list representation

class Graph
{
    int V; // number of vertices

    // pointer to array containing adj lists
    list<int> *adj;

public:
    Graph(int V);

    // add edge to grapH
    void addEdge(int v, int w);

    // prints BFS traversal from a given source
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{

    // init all vertices as not visited yet
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // queue for BFS
    list<int> queue;

    // mark curr node as visited (start node), enqueue it
    visited[s] = true;
    queue.push_back(s);

    // iterator i used to get all adj vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // dequeue vertex from queue and print
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // get all adj vertices of the dequeued vertex s
        // if an adj vertex has not been visited, mark it as visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS starting from vertex 2" << endl;

    g.BFS(2);

    return 0;
}