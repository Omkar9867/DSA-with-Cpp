#include <bits/stdc++.h>

// -------------------------------------Brute Force Approach--TC->O(N * max(a[]))--SC->O(1)-----------------------------------O(n^2)
// int daysNeeded(std::vector<int>& weights, int capacity) {
//     int days = 1;
//     int countLoaded = 0;
//     for (int weight : weights) {
//         if(countLoaded + weight > capacity){ // will reset load and increase day after eachcapacity overload, which will give the day require for that capacity 
//             days++;
//             countLoaded = weight;
//         }else{
//             countLoaded += weight; // else addon to the existing weight
//         }
//     }
//     return days;
// }
// int shipWithinDays(std::vector<int>& weights, int days) {
//     int maxVal = *std::max_element(weights.begin(), weights.end()); //(since capacity can't be less than the heaviest package)
//     int accumulatedVal = std::accumulate(weights.begin(), weights.end(),0);//(which guarantees all packages shipped in one day)
//     for(int i = maxVal; i <= accumulatedVal; i++){
//         int needed = daysNeeded(weights, i); //I'll keep sending the capacity
//         if(needed <= days){
//             return i;
//         }
//     }
//     return maxVal;
// }
// This will give time limit exceed

// -------------------------------------Optimal Approach--TC->O(Nlog(max(a[])))--SC->O(1)-----------------------------------O(nlogn)
long long daysNeeded(std::vector<int>& weights, int capacity) {
    long long days = 1;
    long long countLoaded = 0;
    for (int weight : weights) {
        if(countLoaded + weight > capacity){ // will reset load and increase day after eachcapacity overload, which will give the day require for that capacity 
            days++;
            countLoaded = weight;
        }else{
            countLoaded += weight; // else addon to the existing weight
        }
    }
    return days;
}
int shipWithinDays(std::vector<int>& weights, int days) {
    int maxVal = *std::max_element(weights.begin(), weights.end()); //(since capacity can't be less than the heaviest package)
    int accumulatedVal = std::accumulate(weights.begin(), weights.end(),0);//(which guarantees all packages shipped in one day)
    int ans = accumulatedVal;
    while(maxVal <= accumulatedVal){
        int mid = maxVal + (accumulatedVal - maxVal) / 2;
        int needed = daysNeeded(weights, mid);
        if(needed <= days){
            ans = mid;
            accumulatedVal = mid - 1;
        }else{
            maxVal = mid + 1;
        }
    }
    return ans;
}
//!An error in case appeared which was regarding how the ceil was calculated. when long long the below example resulted 3, 
//! And by calculating the ciel making the pile double it resulted one. So if the value was not long long it gave error


int main(){
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    int result = shipWithinDays(arr, d);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 1011. Capacity To Ship Packages Within D Days

// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Example 1:
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

//* Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// Example 2:
// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4

// Example 3:
// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1

// Constraints:
// 1 <= days <= weights.length <= 5 * 104
// 1 <= weights[i] <= 500
