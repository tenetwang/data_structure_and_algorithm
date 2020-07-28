//
// Created by admin on 2020/7/17.
//

#include "binarySearch.h"
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key){
    int mid = (low + high) / 2;
    if(low > high) return -1;
    if(low==high) return low;
    if(arr[mid] >key)
        return binarySearch(arr, low, mid-1, key);
    if(arr[mid] < key)
        return binarySearch(arr, mid+1, high, key);
    if(arr[mid] == key)
        return mid;
}
