//
// Created by admin on 2020/7/24.
//

#include "opt.h"
#include "../util/utility.h"

#include <iostream>
#include <climits>
using namespace std;

// Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

struct result maxSubArraySum(int arr[], int n){
    int max_pos[2] = {0, 0};
    int max_curr = arr[0];
    int max_all = arr[0];
    for(int i = 0; i < n; i++){
        max_curr += arr[i];
        if(arr[i] >= max_curr) {
            max_pos[0] = i;
            max_pos[1] = i;
            max_curr = arr[i];
        }
        if(max_all < max_curr){
            max_all = max_curr;
            max_pos[1] = i;
        }
    }
    struct result res;
    res.sum = max_all;
    res.pos[0] = max_pos[0];
    res.pos[1] = max_pos[1];
    return res;
}

/*
 * Maximum profit by buying and selling a share at most twice
 * In a daily share trading, a buyer buys shares in the morning and sells it on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.
 * Input:   price[] = {10, 22, 5, 75, 65, 80}
 * Output:  87
 */
int maxProfit(int price[], int n){
    int* profit = new int[n];
    for(int i = 0; i < n; i++){
        profit[i] = 0;
    }
    // traverse from right to left
    int max_price = price[n-1];
    for(int i = n-2; i >= 0; i--){
        max_price = max(max_price, price[i]);
        profit[i] = max(profit[i+1], max_price-price[i]);
    }
    // cout << profit[0] <<endl;
    // traverse from left to right
    int min_price = price[0];
    for(int i = 1; i < n; i++){
        min_price = min(min_price, price[i]);
        profit[i] = max(profit[i] + price[i-1] - min_price, profit[i-1]);
    }
    int result = profit[n-1];
    delete[] profit;
    return result;
}
