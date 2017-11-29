#include <iostream>

using namespace std;

void min_heapify(int * heap, int i, int n){
    int j, temp;
    temp = heap[i];
    j = 2 * i;
    while(j <= n){
        if(j < n and heap[j+1] < heap[j])
            j++;
        if(temp < heap[j])
            break;
        else if(temp >= heap[j]){
            heap[j/2] = heap[j];
            j = 2 * j;
        }
    }
    heap[j/2] = temp;
    return;
}


void build_minheap(int * heap, int n){
    int i;
    for(i = n/2; i >= 1; i--)
        min_heapify(heap, i, n);
}

int main(){
    int n, i , x;
    cout << "enter no of elements of array\n";
    cin >> n;
    int heap[20];
    for(i = 1; i <= n; i++){
        cout << "enter element" << i << endl;
        cin >> heap[i];
    }
    build_minheap(heap, n);
    cout << "min heap\n";
    for(i = 1; i <= n; i++)
        cout << heap[i] << endl;
}







