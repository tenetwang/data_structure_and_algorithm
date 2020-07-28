//
// Created by admin on 2020/7/20.
//

#ifndef ARRAY_FOR_LEARNING_HEAP_H
#define ARRAY_FOR_LEARNING_HEAP_H

class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // Destructor
    ~MinHeap();

    // to heapify a subtree with the root at given index
    void MinHeapify(int, int);

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    // Print the heap array
    void printHeap();

    // Sort the heap: ascending
    void sortHeap();
};


#endif //ARRAY_FOR_LEARNING_HEAP_H
