#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Logic here is to imagine every day as sale day, and while moving forward we will see for the past indexes which was the lowest value and the max profit
int maxProfit(vector<int> arr){ // ---> O(n)
    // int bestBuy = INT_MAX;
    int maxVal = 0, bestBuy = arr[0];
    // for(int i=0; i<arr.size(); i++){
    //     bestBuy = min(arr[i], bestBuy);
    //     maxVal = max(maxVal ,arr[i] - bestBuy);
    //     if(maxVal < 0){
    //         maxVal = 0;
    //     }
    // }
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > bestBuy){
        maxVal = max(maxVal, arr[i] - bestBuy);
        }
        bestBuy = min(bestBuy, arr[i]);
    }
    return maxVal;
}

int main(){
    vector<int> price = {7,1,5,3,6,4};
    int maximumProfit = maxProfit(price);
    cout << "Max Profit of my share is : " << maximumProfit << endl;

    return 0;
}

//Question:
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.