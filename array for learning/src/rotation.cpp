//
// Created by admin on 2020/7/16.
//

#include "rotation.h"
#include <iostream>
using namespace std;

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void rotate1(int arr[], int n, int d){
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i=0; i<n-d ;i++){
        arr[i] = arr[i+d];
    }
    for(int i=n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }

}
int gcd(int a, int b){
    if(b==0) {
        return a;
    }
    else{
        gcd(b, a%b);
    }
}
void rotate2(int arr[], int n, int d){
    int temp;
    //  assert n > d true
    d = d % n;
    int g = gcd(n, d);
    int block = n / g;
    for(int i=0; i<g; i++){
        int temp = arr[i];
        int j = i;
        while(true){
            int k = (j + d)%n;
            if(k==i)
                break;
            else{
                arr[j] = arr[k];
                j = k;
            }
        }
        arr[j] = temp;
    }
}
void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate_reversal(int arr[], int n, int d){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}
