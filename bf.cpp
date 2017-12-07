#include "Graph.h"
#include <iostream>
#include <climits>

using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};

int Partition(Edge edges[], int low, int high){
    Edge pivot = edges[low];
    do{
        while(low < high && edges[high].weight >= pivot.weight){
            high--;
        }
        if(low < high){
            edges[low] = edges[high];
            while(low < high && edges[low].weight <= pivot.weight){
                low++;
            }
            if(low < high)
                edges[high] = edges[low];
        }
        
    }while(low<high);
    edges[low] = pivot;
    return low;
    
}

void QuickSort(Edge edges[], int low, int high){
    int mid;
    if(low < high){
        mid = Partition(edges, low, high);
        QuickSort(edges, low, mid - 1);
        QuickSort(edges, mid + 1, high);
    } 
}

struct subset{
    int parent;
    int rank;
};

void bf(Graph graph, int src){
    int size = graph.getSize();
    int edges = graph.getEdges();
    int cost[size];
    
    for(int i = 0; i < V; i++)
        cost[i] = INT_MAX;
    cost[src] = 0;
    
    for(int i = 1; i <= V-1; i++){
        for(int j = 0; j < edges; j++){
            int u = 
        }
    }
    
    
}

int main(){
    int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    int W = 9;
	Graph g2(W);

	g2.addEdge(0, 1, -4);
    g2.addEdge(0, 7, -8);
    g2.addEdge(1, 2, 9);
    g2.addEdge(1, 7, 11);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 8, -2);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, -14);
    g2.addEdge(4, 5, 10);
    g2.addEdge(5, 6, 2);
    g2.addEdge(6, 7, 1);
    g2.addEdge(6, 8, -6);
    g2.addEdge(7, 8, -7);
    
    cout << "\n<-- Connected graph for Kruskals -->" << endl;
    g.Print();
    cout << "\n<-- MST of graph -->" << endl;
    krusk(g);
    
    cout << "\n Connected graph2 for Kruskals -->" << endl;
    g2.Print();
    cout << "\n<--- MST of graph with negative weights -->"<< endl;
    krusk(g2);
    
}















