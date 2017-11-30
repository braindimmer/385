#include "Graph.h"
#include <iostream>

struct MinHeapNode{
	int v;
	int cost;
};

struct MinHeap{
	int size;
	int capacity;
	int * pos;
	MinHeapNode * array;
};

struct MinHeapNode * newMinHeapNode(int v, int cost){
	struct MinHeapNode * minHeapNode = new MinHeapNode();
	minHeapNode->v = v;
	minHeapNode->cost = cost;
	return minHeapNode;
};

struct MinHeap * createMinHeap(int capacity){
	struct MinHeap* minHeap = new MinHeap();
	minHeap->pos = new int[capacity];
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = new MinHeapNode[capacity];
	return minHeap;
};

void swapMinHeapNode(MinHeapNode * a, MinHeapNode * b){
	MinHeapNode * temp = a;
	a = b;
	b = temp;
};

void minHeapify(MinHeap * minHeap, int i){
	int smallest, left, right;
	smallest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if(left < minHeap->size and
		 	minHeap->array[left].cost < minHeap->array[smallest].cost)
		smallest = left;
	if(right < minHeap->size and 
			minHeap->array[right].cost < minHeap->array[smallest].cost)
		smallest = right;

	if(smallest != i){
		MinHeapNode * smallestNode = &minHeap->array[smallest];
		MinHeapNode * iNode = &minHeap->array[i];

		minHeap->pos[smallestNode->v] = i;
		minHeap->pos[iNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[i]);
		minHeapify(minHeap, smallest);
	}
}

bool isEmpty(MinHeap * minHeap){
	return minHeap->size == 0;
}

struct MinHeapNode * getMin(MinHeap * minHeap){
	if(isEmpty(minHeap))
		return NULL;

	struct MinHeapNode * root = &minHeap->array[0];

	struct MinHeapNode * lastNode = &minHeap->array[minHeap->size - 1];
	minHeap->array[0] = *lastNode;

	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	minHeap->size--;
	minHeapify(minHeap, 0);

	return root;
};

void decreaseKey(MinHeap * minHeap, int v, int cost){
	int i = minHeap->pos[v];

	minHeap->array[i].cost = cost;

	while(i and minHeap->array[i].cost < minHeap->array[(i - 1)/2].cost){
		minHeap->pos[minHeap->array[i].v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2].v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}

bool isInMinHeap(MinHeap * minHeap, int v){
	if(minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void printArr(int arr[], int n){
	for(int i = 1; i < n; i++)
		std::cout << arr[i] << " - " << i << std::endl;
}

void prims(Graph graph){
	int size = graph.getSize();	//Number of vertices
	int mst[size];					//MST
	int cost[size];				//Minimum weight edges

	MinHeap* minHeap = createMinHeap(size);

	for(int v = 1; v < size; v++){
		mst[v] = -1;
		cost[v] = 99999999;
		minHeap->array[v] = *newMinHeapNode(v, cost[v]);
		minHeap->pos[v] = v;
	}

	cost[0] = 0;
	minHeap->array[0] = *newMinHeapNode(0, cost[0]);
	minHeap->pos[0] = 0;

	minHeap->size = size;

	while(!isEmpty(minHeap)){
		MinHeapNode* minHeapNode = getMin(minHeap);
		int u = minHeapNode->v;

		AdjListNode* crawl = graph.adjNode(u);
		while(crawl!=NULL){
			int v = crawl->dest;

			if(isInMinHeap(minHeap, v) and crawl->weight < cost[v]){
				cost[v] = crawl->weight;
				mst[v] = u;
				decreaseKey(minHeap, v, cost[v]);
			}
			crawl = crawl->next;
		} 
	}

	printArr(mst, size);
}

int main(){
	int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
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
 
    prims(g);
 
    return 0;

}

