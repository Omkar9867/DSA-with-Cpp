#include <bits/stdc++.h>

class Solution {
public:
//------------------------------------Brute Force--TC->O(N^3)--SC->O(K)-------------------------------
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
       int n = nums.size();
 
        // Edge Case
        if (n < 3) {
            return {};
        }
 
        std::set<std::vector<int>> uniqueTriplets;

        for (int first = 0; first < n - 2; first++) {
            for (int second = first + 1; second < n - 1; second++) {
                for (int third = second + 1; third < n; third++) {
                    long long sum = (long long) nums[first] + nums[second] + nums[third];
 
                    // A zero sum gives a valid triplet.
                    if (sum == 0) {
                        std::vector<int> triplet = { nums[first], nums[second], nums[third] };
                        // Sort
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
 
        return std::vector<std::vector<int>>(uniqueTriplets.begin(),uniqueTriplets.end()); 
    }

//-------------------------------Optimal Solution---------------------------
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> answer;
 
        // Edge Case
        if (n < 3) {
            return answer;
        }
        // Sort so pointers are easy to be used
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){
            //Skip the same fixed value to avoid duplication
            if(i > 0 &&  nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = n - 1;
 
            while (left < right) {
                long long sum =(long long) nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {// A smaller sum needs a larger left value.
                    left++;
                }else if (sum > 0) { // A larger sum needs a smaller right value
                    right--;
                }else {
                    answer.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    // Skip repeated values so same triplet is not added again
                    
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
 
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
 
        return answer;
    }


};


int main(){

    return 0;
}



// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 
// Constraints:
// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105