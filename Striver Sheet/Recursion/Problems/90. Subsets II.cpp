#include <bits/stdc++.h>

class Solution {
private:
//Recursive Helper
    void findSubsets(int ind, std::vector<int>& nums, std::vector<int>& ds, std::set<std::vector<int>>& result) {
        // Base case: if we've considered all elements, add to result
        if (ind == nums.size()) {
            result.insert(ds);
            return;
        }

        //1: Include the element at the current index
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, result);

        //! Backtrack to explore the other choice
        ds.pop_back();

        // 2: Do not include the element at the current index
        findSubsets(ind + 1, nums, ds, result);
    }
public:
    //------------------------------Brute Force Approach--TC->O(2^n*n)--SC->O(2^n)-----------------------------
    std::vector<std::vector<int>> subsetSums(std::vector<int>& nums) {
        std::set<std::vector<int>> result;
        std::vector<int> ds;
        // Sort the array to handle duplicates consistently
        std::sort(nums.begin(), nums.end());
        
        findSubsets(0, nums, ds, result);

        // Convert the set of unique subsets to a vector for the final answer
        std::vector<std::vector<int>> ans(result.begin(), result.end());
        return ans;
    }

    //------------------------------Recursive Approach--TC->O(2^n)--SC->O(2^n)-----------------------------
    std::vector<std::vector<int>> subsetSums(std::vector<int>& nums) {
        
    }

    void printResult(std::vector<std::vector<int>> result){
        std::cout << "[ ";
        for (const auto& subset : result) {
            std::cout << "[ ";
            for (int num : subset) {
                std::cout << num << " ";
            }
            std::cout << "] ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {5, 2, 1};
    std::vector<std::vector<int>> result = sol.subsetSums(arr);

    // Print the subset sums
    sol.printResult(result);

    return 0;
}

// 90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
