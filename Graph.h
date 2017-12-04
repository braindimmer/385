#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>

struct AdjListNode{
        int dest;
        int weight;
        AdjListNode* next;
};

struct AdjList{
        AdjListNode * head;
};

class Graph
{
private:
        int edges;
        int V;                          //vertex
        AdjList * array;                //array of adjacency list head pointers

public:
    Graph();

	//Constructs a graph of size V and initializes its adjacency list
    //head pointers to NULL
    Graph(int V);

    //Creates a new node(vertex)
    AdjListNode* newAdjListNode(int dest, int weight);
    AdjListNode* adjNode(int u);

    void Print();
    void PrintGraph();

    
    
    //Adds an edge
    void addEdge(int src, int dest, int weight);

    int getEdges();
    int getSize();

};
#endif
