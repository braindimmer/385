#include "Graph.h"
#include <string>
#include <iostream>

using namespace std;

Graph::Graph(){}

Graph::Graph(int V){
    this->V = V;
    array = new AdjList[V];
    for(int i = 0; i < V; i++)
        array[i].head = NULL;
}


AdjListNode* Graph::newAdjListNode(int dest, int weight){
    AdjListNode * newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void Graph::addEdge(int src, int dest, int weight){
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = array[src].head;
    array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = array[dest].head;
    array[dest].head = newNode;
    edges++;
}

int Graph::getEdges(){
    return edges;
}

int Graph::getSize(){
    return this->V;
}

void Graph::Print(){
    for(int i = 0; i < getSize(); i++){
        AdjListNode * ptr = array[i].head;
        //cout << "Adjacency list of vertex " << getLabel(i) << "\n head";
        while(ptr){
            //cout << "-> " << getLabel(ptr->dest);
            ptr = ptr->next;
        }
    cout << endl;
    }
}

void Graph::PrintGraph(){

    bool * explored = new bool[V];
    for(int i = 0; i < V; i++)
        explored[i] = false;

    for(int i = 0; i < V; i++){
        AdjListNode * ptr = array[i].head;
        while(ptr){
            explored[i] = true;
            if(explored[ptr->dest] == false){
                cout << i << " -> " << ptr->dest;
                cout << endl;
                ptr = ptr->next;
            }
            else{
                ptr = ptr->next;
            }
    }
    }
}

AdjListNode * Graph::adjNode(int u){
    return array[u].head;
}

