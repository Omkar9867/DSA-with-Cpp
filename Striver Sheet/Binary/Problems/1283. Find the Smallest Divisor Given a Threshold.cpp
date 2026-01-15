#include <bits/stdc++.h>

// -------------------------------------Brute Force Approach--TC->O(N * max(a[]))--SC->O(1)-----------------------------------O(n^2)
// bool isDivisor(std::vector<int>& nums, int threshold, int k){
//     int n = nums.size();
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         int val = (nums[i] + k - 1)/k; //ciel val
//         count += val;
//     }
//     if(count <= threshold){
//         return true;
//     }else{
//         return false;
//     }
// }

// int smallestDivisor(std::vector<int>& nums, int threshold) {
//     int high = *std::max_element(nums.begin(), nums.end());
//     for(int i = 1; i <= high; i++){
//         if(isDivisor(nums, threshold, i)){
//             return i;
//         }
//     }
//     return -1;
// }
//! Above time limit exceeds


// -------------------------------------Optimal Approach--TC->O(Nlog(max(a[]))--SC->O(1)-----------------------------------i.e. O(nlogn)
long long isDivisor(std::vector<int>& nums, int k){
    int n = nums.size();
    long long count = 0;
    for(int i = 0; i < n; i++){
        long long val = (nums[i] + k - 1)/k; //ciel val
        count += val;
    }
    return count;
}

int smallestDivisor(std::vector<int>& nums, int threshold) {
    int st = 1;
    int high = *std::max_element(nums.begin(), nums.end());
    int ans = high;
    while(st <= high){
        int mid = st + (high - st)/2;
        long long val = isDivisor(nums, mid);
        if(val <= threshold){
            ans = mid;
            high = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}


int main(){
    std::vector<int> arr = {44,22,33,11,1};
    int h = 5;
    int result = smallestDivisor(arr, h);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 1283. Find the Smallest Divisor Given a Threshold

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
// Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

// Example 1:
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

// Example 2:
// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44
 
// Constraints:
// 1 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 106
// nums.length <= threshold <= 106