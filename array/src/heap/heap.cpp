//
// Created by admin on 2020/7/20.
//

#include "heap.h"
#include <iostream>
#include <climits>
#include "../util/utility.h"
using namespace std;

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Destructor: Free the allocated memory
MinHeap::~MinHeap() {
    delete [] harr;
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0, heap_size);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i, int heap_size)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest, heap_size);
    }
}

void MinHeap::printHeap() {
    for(int i=0; i<heap_size; i++){
        cout << harr[i] << " ";
    }
    cout << endl;
}

void MinHeap::sortHeap() {
    // swap every elements to the last place of harr and heapify
    // in every turn i, i-th element of harr becomes the i-th smallest element
    int temp_size = heap_size;
    for(int i=0; i<heap_size; i++){
        swap(&harr[temp_size-1], &harr[0]);
        temp_size--;
        MinHeapify(0, temp_size);
    }
    // now the harr is descended. reverse it
    /*
    for(int i=0; i<heap_size/2; i++){
        swap(&harr[i], &harr[heap_size -1 -i]);
    }
     */

    int i = 0, j = heap_size-1;
    while(i<=j){
        swap(&harr[i++], &harr[j--]);
    }

}