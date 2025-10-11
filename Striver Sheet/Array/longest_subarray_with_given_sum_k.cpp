#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

// -------------------------------Brute Force O(n^2)------------------------
// int longestSubArray(int arr[], int k, int n){
//     int count1 = 0;
//     for(int i = 0; i < n; i++){
//         int count2 = 1;
//         int sum = 0;
//         for(int j = 1; j < n; j++){
//             count2++;
//             sum += arr[i] + arr[j];
//             // std::cout << "sum : " << sum << std::endl;
//             if(sum == k && count1 < count2){
//                 count1 = count2;
//             }
//         }
//     }
//     return count1;
// }

// --------------------------------Better Solution O(n^2)--------------- 
// int longestSubArray(std::vector<int> arr, long long k){
//     std::map<long long, int> preSumMap;       
//     long long sum = 0;
//     int maxLen = 0;
//     for(int i = 0; i < arr.size(); i++){
//         sum += arr[i];
//         if(sum == k){
//             maxLen = std::max(maxLen, i+1);
//         }
//         int rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen = std::max(maxLen, len);
//         }
//         preSumMap[sum] = i;
//     }
//     return maxLen;
// }

// ------------------------------------ Optimal Solution --------------------
int longestSubArray(std::vector<int> arr, long long k){
    int maxLength = 0;
    int n = arr.size();
    int i = 0;
    long long sum = 0;
    for(int j = 0; j < n; j++){
        sum += arr[j];
        // Shrink the window until the sum is less than or equal to k
        while(sum > k && i <= j){
            sum -= arr[i]; // Subtract the element at the left boundary
            i++;
        }
        if (sum == k) {
            maxLength = std::max(maxLength, j - i + 1);
        }
    }
    return maxLength;
}

int main(){
    int n = 5;
    // int arr[n] = {2,3,5,1,9};
    std::vector<int> arr = {2,3,5};
    int k = 5;
    // int result = longestSubArray(arr, k, n);
    int result = longestSubArray(arr, k);
    std::cout << "Result : " << result << std::endl; 

    return 0;
}



// Problem Statement: 
// Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Examples

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
