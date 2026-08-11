#include<bits/stdc++.h>

class Solution {
    //!Understand well
  private:
    void findCombination(int ind, int target, std::vector<int>& arr, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {
        if (ind == arr.size()) {
            // If the target is zero, we have found a valid combination
            if (target == 0) {
                ans.push_back(ds);  // Add the current combination to the result
            }
            return;
        }

        // Recursive case: pick the element if it's less than or equal to the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);  // Add the current element to the combination
            findCombination(ind, target - arr[ind], arr, ans, ds);  // Continue with the same index to allow repeated elements
            ds.pop_back();  // Backtrack by removing the last added element
        }

        // Skip current and move to next
        findCombination(ind + 1, target, arr, ans, ds);
    }

  public:
//------------------------------------Approach--TC->O(2^t*k)--------------------------------
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds; // Store a current combination
        findCombination(0, target, candidates, ans, ds); 
        return ans;
    }
};

int main() {
    Solution obj;
    std::vector<int> v {2, 3, 6, 7};  // Candidate numbers
    int target = 7;

    std::vector<std::vector<int>> ans = obj.combinationSum(v, target);

    // Output the combinations
    std::cout << "Combinations are: " << std::endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl; 
    }

    return 0;
}


// 39. Combination Sum

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:
// Input: candidates = [2], target = 1
// Output: []
 
// Constraints:
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40