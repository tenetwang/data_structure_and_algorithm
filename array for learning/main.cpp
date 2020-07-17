#include <iostream>
#include <array>
#include "memory_location.h"
#include "./src/rotation.h"
#include "./src/binarySearch.h"
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
    int arr[] = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15};
    //rotate_reversal(arr, sizeof(arr)/sizeof(arr[0]), 5);
    print_array(arr, sizeof(arr)/sizeof(arr[0]));
    int p;
    //tree(10);
    //int p=0, t = p;
    //p = t++;
    //cout << t << p <<endl;
    p = find_pivot(brr, 0, 5);
    cout << "pivot " << p << endl;
    p = binarySearch(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 1);
    cout << "binarysearch " << p << endl;

    return 0;
}
