#include <bits/stdc++.h>

//-------------------------------------Brute Force Approach TC_O(N^2)--------------------
// Because of loop inside loop approach


//------------------------------------Optimal Approach --TC->O(N)--SC->O(N)---------------------------
int subarraySum(std::vector<int>& nums, int k) {
    int n = nums.size();

    std::unordered_map<int, int> prefixSumCount;

    int prefixSum = 0;
    int count = 0;

    // Base case: prefix sum 0 has occurred once
    prefixSumCount[0] = 1;
    // Traverse through the array
    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];

        // Calculate the prefix sum that needs to be removed
        int remove = prefixSum - k;

        // If this prefix sum has been seen before, add its count to the result
        if (prefixSumCount.find(remove) != prefixSumCount.end()) {
            count += prefixSumCount[remove];
        }

        prefixSumCount[prefixSum]++;
    }
    
    return count;
}
//!Revisit the sum again: https://www.youtube.com/watch?v=xvNwoz-ufXA&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=33

int main(){
    std::vector<int> arr = {1,1,1};
    int k = 2;
    int result = subarraySum(arr, k);
    std::cout << "Result: " << result << " ";
    return 0;
}

// 560. Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2
 
// Constraints:
// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107


//!Question: Why do we need to set the value of 0?
//Let’s understand this using an example. Assume the given array is [3, -3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix sum as 3, and k is also 3. 
//So, the prefix sum of the remove-part should be x-k = 3-3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 for the key 0 and we will add 0 to our answer. This will mean that we have not found any subarray with sum 3 till now. But this should not be the case as index 0 itself is a subarray with sum k i.e. 3.
//So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.