#include<bits/stdc++.h>

class Solution {
    //!Understand well
  private:
    void findCombination(int ind, int target, std::vector<int>& arr, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {
        // Base case: If the target becomes 0
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through the elements starting from 'ind'
        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1]) continue;
            // If the current element is greater break
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            //Backtrack
            ds.pop_back();
        }
    }

  public:
//------------------------------------Approach--TC->O(2^n*k)--SC->(k*x)------------------------------
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
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

// 40. Combination Sum II

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Constraints:
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
 