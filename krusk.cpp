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

int find(subset subsets[], int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int l, int r){
    int l_root = find(subsets, l);
    int r_root = find(subsets, r);
    
    if(subsets[l_root].rank < subsets[r_root].rank)
        subsets[l_root].parent = r_root;
    else if(subsets[l_root].rank > subsets[r_root].rank)
        subsets[l_root].parent = r_root;
    else{
        subsets[r_root].parent = l_root;
        subsets[l_root].rank++;
    }
}

void krusk(Graph graph){
    int size = graph.getSize();
    Edge mst[size];
    Edge edges[graph.getEdges()];
    int e = 0;                  //Edge index variable
    int se = 0;                 //Sorted edge index variable

    int k = 0;
    for(int i = 0; i < size; i++){
        AdjListNode * head = graph.adjNode(i);
        
        while(head){
            edges[k].src = i;
            edges[k].dest = head->dest;
            edges[k].weight = head->weight;
        
        head = head->next;
        k++;
        }
    }
    
    QuickSort(edges, 0, graph.getEdges() - 1);
    
    subset *subsets = new subset[size];
    
    for(int i = 0; i < size; i ++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    while(e < size - 1){
        Edge next = edges[se++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);
        
        if(x!=y){
            mst[e++] = next;
            Union(subsets, x, y);
        }
    }
    
    int totalcost = 0;
    for(int i = 0; i < e; i++){
        cout << mst[i].src << " - " << mst[i].dest << " -> " << mst[i].weight << endl;
        totalcost += mst[i].weight;
    }
    cout << "Total cost: " << totalcost << endl;
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















