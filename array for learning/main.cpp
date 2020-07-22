#include <iostream>
#include <array>
#include "memory_location.h"
#include "src/rotation/rotation.h"
#include "./src/binarySearch.h"
#include "./src/util/utility.h"
#include "./src/arrange/arrange.h"
#include "./src/order_statistics/order.h"
#include "./src/heap/heap.h"
using namespace std;

void tree(int n){
    int* temp = new int [n];
    for(int i=0; i<n; i++){
        temp[i] = 1;
    }
    int sum = 0;
    for(int i=1; i<n; i++){
        sum = 0;
        for(int j=0; j<i; j++){
            sum += temp[j] * temp[i - 1 -j];
        }
        temp[i] = sum;
    }
    // cout
    for(int i=0; i<n; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
}

// base case: 3 4 5 6 1 2
// return 3
int find_pivot(int arr[], int low, int high){
    int mid = (low + high) / 2;
    if(high < low) return -1;
    if(high==low) return low;
    if(mid < high && arr[mid] > arr[mid+1]) {
        return mid;
    }
    if(mid > low && arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[mid] <= arr[low]) {
        return find_pivot(arr, low, mid-1);
    }
    return find_pivot(arr, mid+1, high);


}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << kth_smallest_heap(arr, n, 2);
    //printArray(arr, n);
}
