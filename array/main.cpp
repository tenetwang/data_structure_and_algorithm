#include <iostream>
#include <array>
#include "memory_location.h"
#include "src/rotation/rotation.h"
#include "./src/binarySearch.h"
#include "./src/util/utility.h"
#include "./src/arrange/arrange.h"
//#include "./src/order_statistics/order.h"
#include "./src/heap/heap.h"
#include "./src/query/query.h"
#include "./src/optimization/opt.h"
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


    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n) << endl;

    int temp[] = {10, 20, 10, 5};
    MinHeap mh(sizeof(temp) / sizeof(temp[0]));
    for(int i=0; i<4; i++){
        mh.insertKey(temp[i]);
    }
    mh.printHeap();
    mh.sortHeap();
    mh.printHeap();


    return 0;
}
