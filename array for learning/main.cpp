#include <iostream>
#include <array>
#include "memory_location.h"
#include "./src/rotation.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[] = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15};
    rotate_reversal(arr, sizeof(arr)/sizeof(arr[0]), 5);
    print_array(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
