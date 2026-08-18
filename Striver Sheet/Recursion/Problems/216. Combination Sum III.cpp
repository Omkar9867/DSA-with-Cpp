#include <bits/stdc++.h>

class Solution {
private: 
    void func(int sum, int last, std::vector<int> &nums, int k, std::vector<std::vector<int>> &ans) {
        // If the sum is zero and the number of elements is k
        if(sum == 0 && nums.size() == k) {
            // Add the current combination and return
            ans.push_back(nums);
            return; 
        }
        // If the sum is less than or equal to zero or the number of elements exceeds k
        if(sum <= 0 || nums.size() > k) return; 

        // Iterate till 9
        for(int i = last; i <= 9; i++) {
            if(i <= sum) {
                nums.push_back(i); 
                // Recursive call with updated sum and next number
                func(sum - i, i + 1, nums, k, ans); 
                //! Remove the last number to backtrack
                nums.pop_back(); 
            } else {
                // If the number is greater than the sum, break the loop
                break;
            }
        }
    } 
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> nums;
        func(n, 1, nums, k, ans);
        return ans; 
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
    int k = 3;
    int n = 7;
    std::vector<std::vector<int>> result = sol.combinationSum3(k, n);

    sol.printResult(result);

    return 0;
}

// 216. Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:
// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 
// Constraints:
// 2 <= k <= 9
// 1 <= n <= 60