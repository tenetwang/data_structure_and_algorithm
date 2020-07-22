//
// Created by admin on 2020/7/20.
//

#include "arrange.h"
#include "../util/utility.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../util/utility.h"
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end){
    while(start<end){
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rearrange(int arr[], int n){
    int i = -1;
    for(int j=0; j<n; j++){
        if(arr[j] > 0){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
}

// shuffle: randomize a given array
void shuffle(int arr[], int n){
    /*
     * Fisher-Yates shuffle algorithm
     * time complexity: O(n)
     * given a random function rand(), generates random number at O(1)
     * from the last(first also works) element, swap it with a random element chosen from the arr(including itself)
     * exclude this element and repeat
     * */
    srand(time(NULL));
    for(int i = n-1; i>0; i--){
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}
