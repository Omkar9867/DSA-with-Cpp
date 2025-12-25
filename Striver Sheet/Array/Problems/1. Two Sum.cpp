#include <bits/stdc++.h>

//-------------------------------Brute Force Approach -- TC->O(N)------------------------
// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//     std::vector<int> result = {};
//     for(int i = 0; i<nums.size(); i++){
//         for(int j = i+1; j <nums.size(); j++){
//             if(nums[i] + nums[j] == target){
//                 result.push_back(i);
//                 result.push_back(j);
//                 return result;
//             }
//         }
//     }
//     return {};
// }

//-------------------------------Better Approach -- TC->O(N) SC->O(N)------------------------
// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//     std::vector<int> result = {};
//     std::unordered_map<int, int> map;
//     for(int i = 0; i<nums.size(); i++){
//         int complement = target - nums[i];
//         if(map.find(complement) != map.end()){
//             result.push_back(map[complement]);
//             result.push_back(i);
//             return result;
//         }else{
//             map[nums[i]] = i;
//         }
//     }
//     return {};
// }

//-------------------------------Additional Approach -- TC->O(N logN) SC->O(N)------------------------
// Time Complexity: O(N log N) due to sorting the array initially, where N is the number of elements. The two-pointer traversal runs in O(N).
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<int> result = {};
    // Create a vector of pairs to remember original indices after sorting
    std::vector<std::pair<int, int>> numsWithIndex;
    for (int i = 0; i < n; i++) {
        numsWithIndex.push_back({nums[i], i});
    }
    // Sort based on the element values
    std::sort(numsWithIndex.begin(), numsWithIndex.end());
    int left = 0, right = n - 1;
    while(left < right){
        int sum = numsWithIndex[left].first + numsWithIndex[right].first;
        if(sum == target){
            result.push_back(numsWithIndex[left].second);
            result.push_back(numsWithIndex[right].second);
            return result;
        }else if(sum > target){
            right--;
        }else{
            left++;
        }
    }
    return {};
}

int main() {
    std::vector<int> arr = {3,2,4};
    int target = 6;

    std::vector<int> result = twoSum(arr, target);
    for(int i = 0; i<result.size(); i++){
        std::cout << result[i] << " ";
    }

    return 0;
}

// 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109

// Only one valid answer exists.
//! Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 