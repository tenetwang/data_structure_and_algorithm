//
// Created by admin on 2020/7/20.
//

#include "utility.h"
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
