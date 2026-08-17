#include<bits/stdc++.h>

class Solution {
private:
//-------------------------------Approach--TC->O(2^n)-----------------------------
    int func(int ind, int sum, std::vector<int> &nums) {
        if (sum == 0) return 1;
        // Base case: if sum is negative or index exceeds array size
        if (sum < 0 || ind == nums.size()) return 0;
        // Recurse by including current number or excluding it from the sum 
        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }

public:
    int countSubsequenceWithTargetSum(std::vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    std::cout << "Result: "<< sol.countSubsequenceWithTargetSum(nums, target) << std::endl;
    return 0;
}

// Count all subsequences with sum K

// Problem Statement: Given an array nums and an integer k.
// Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

// Examples

// Example 1:
// Input :
//  nums = [4, 9, 2, 5, 1] , k = 10
// Output :
//  2
// Explanation :
//  The possible subsets with sum k are [9, 1] , [4, 5, 1].

// Example 2:
// Input :
//  nums = [4, 2, 10, 5, 1, 3] , k = 5
// Output :
//  3
// Explanation :
//  The possible subsets with sum k are [4, 1] , [2, 3] , [5].