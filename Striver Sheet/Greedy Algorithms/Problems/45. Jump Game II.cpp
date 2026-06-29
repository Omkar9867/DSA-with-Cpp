#include <bits/stdc++.h>

class Solution {
private:
     int minJumps(std::vector<int>& nums, int position) {
        // If we are already at or beyond the last index, no more jumps needed
        if (position >= nums.size() - 1) return 0;

        // If we can't move from current position
        if (nums[position] == 0) return INT_MAX;

        int minStep = INT_MAX;

        // Try every possible jump from 1 to nums[position]
        for (int jump = 1; jump <= nums[position]; ++jump) {
            int subResult = minJumps(nums, position + jump);

            // If the result is not INT_MAX, update minimum step
            if (subResult != INT_MAX)
                minStep = std::min(minStep, 1 + subResult);
        }

        return minStep;
    }
public:
//-----------------------Brute Force Approach----TC->O(2^n)-SC->O(N)-----------------------
    // int jump(std::vector<int>& nums) {
    //     return minJumps(nums, 0);
    // }


//-----------------------Better Approach----TC->O(N^2)-SC->O(N)-----------------------
    int jump(std::vector<int>& nums) {
        int n = nums.size();

        // Initialize DP array with large value
        std::vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        // Iterate through all indices
        for (int i = 0; i < n; ++i) {
            // For each position, calculate max jump
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                // Update dp value for the position we can reach
                dp[i + j] = std::min(dp[i + j], dp[i] + 1);
            }
        }

        // Return the minimum jumps to reach last index
        return dp[n - 1];
    }


//*-----------------------------Optimal Approach-----------------------------
//---------------------------TC->O(N)--SC->O(1)-----------------------
    int jump(std::vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;

        // exclude the last element
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest index that can be reached so far
            farthest = std::max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                jumps++; // jumps will increase only after the new jump i.e. when i meets the current end which was eventually previously the largest jump.
                // update the current end with the farthest idx now
                currentEnd = farthest;
            }
        }

        return jumps;
    }

    void printResult(int num){
        std::cout << num << ": Result" << std::endl;
    }

};

int main(){
    Solution obj;
    std::vector<int> nums = {2,3,1,1,4};
    int n = 2;   
    int result = obj.jump(nums);
    
    obj.printResult(result);

    return 0;
}

// 45. Jump Game II

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at index i, you can jump to any index (i + j) where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2
 
// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].