//
// Created by admin on 2020/7/20.
//

#include "order.h"
#include "../heap/heap.h"
#include <iostream>
#include<bits/stdc++.h>
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
/*
int kth_smallest_heap(int arr[], int n, int k){
    MinHeap mh(arr, n);
    for(int i=0; i<k-1; i++)
        mh.extractMin();
    return mh.getMin();
}
*/
// make use of c++ STL's set
// insert all elements into a set
// traverse the set to get the k-th element
int kth_smallest_STL(int arr[], int n, int k){
    set<int> s;
    for(int i=0; i<n; i++)
        s.insert(arr[i]);
    auto it = s.begin();// std::set<std::int>::iterator it = s.begin()是标准写法，如果声明了std命名空间则可以省去std，但是不建议
    // traverse for the k-th element in the set
    for(int i=0; i<k-1; i++){
        it++;
    }
    return *it;
}
