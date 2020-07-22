//
// Created by admin on 2020/7/20.
//

#include "order.h"
#include "../heap/heap.h"
#include <iostream>
using namespace std;

void kth_smallest(int arr[], int n, int k){
    for(int j=0; j<k; j++){
        for(int i=j; i<n; i++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int kth_smallest_heap(int arr[], int n, int k){
    MinHeap mh(arr, n);
    for(int i=0; i<k-1; i++)
        mh.extractMin();
    return mh.getMin();
}
