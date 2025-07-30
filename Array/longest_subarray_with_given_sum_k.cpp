#include <iostream>
#include <algorithm>

// -------------------------------Brute Force ------------------------
int longestSubArray(int arr[], int k, int n){
    int count1 = 0;
    for(int i = 0; i < n; i++){
        int count2 = 1;
        int sum = 0;
        for(int j = 1; j < n; j++){
            count2++;
            sum += arr[i] + arr[j];
            // std::cout << "sum : " << sum << std::endl;
            if(sum == k && count1 < count2){
                count1 = count2;
            }
        }
    }
    return count1;
}

int main(){
    int n = 5;
    int arr[n] = {2,3,5,1,9};
    int k = 10;
    int result = longestSubArray(arr, k, n);
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
