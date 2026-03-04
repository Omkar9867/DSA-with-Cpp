#include <bits/stdc++.h>

//---------------------------------Approach--TC->O(N*2^N)----------------------------

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    // Calculate the total number of subsets (2^n) using bitwise shift
    int subsets = 1 << n; //2^n is written as this
    for(int num = 0; num<subsets; num++){
        std::vector<int> subset;
        // Iterate through each bit of the number
        for (int i = 0; i < n; i++) {
            // If the ith bit is set, include nums[i] in the subset
            if (num & (1 << i)) {
                subset.push_back(nums[i]); //!Understand this well, we arew playing with positions not numbers. [pos1, pos2, ... posn]
            }
        }

        // Add the constructed subset into the result
        result.push_back(subset);
    }
    return result;
}
//So even if more position, the first loop will run till 2^n times
//and the pattern of bit makes the position to include that [i]th num to include
//Binary: 101
//  bit0 = 1 → include 1
//  bit1 = 0 → skip 2
//  bit2 = 1 → include 3

int main(){
    std::vector<int> nums = {4, 5, 6};
    std::vector<std::vector<int>> result = subsets(nums);
    for (auto row : result) {
        for (auto val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// 78. Subsets

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
 
// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.