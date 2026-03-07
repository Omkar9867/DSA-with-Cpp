#include <bits/stdc++.h>

// ----------------------------------Better Approach TC->O(N) --SC->O(N)----------------------------

// std::vector<int> singleNumber(std::vector<int>& nums) {
//     std::vector<int> result;
//     std::unordered_map<int, int> mp;
//     for(int i = 0; i<nums.size(); i++){
//         // mp.insert(nums[i], +1);
//         mp[nums[i]] += 1;
//     }
//     for(const auto& it: mp){
//         if(it.second == 1) result.push_back(it.first);
//     }
//     return result;
// }

// ----------------------------------Optimal Approach TC->O(N) --SC->O(1)----------------------------
// Traverse the entire array, performing an XOR operation on all numbers. This will effectively cancel out all the numbers that appear twice, leaving us with the XOR of the two unique numbers.
// Determine the rightmost set bit (bit that is 1) in the result from the first step. This set bit can be used to differentiate the two unique numbers since they must differ at this bit position.
// Traverse the array again, but this time divide the numbers into two groups:
// One group where the numbers have the rightmost set bit.
// Another group where the numbers do not have this bit set.
// Perform XOR operations while adding numbers in each group. This will cancel out the duplicate numbers, leaving only the unique numbers in each group.

std::vector<int> singleNumber(std::vector<int>& nums) {
    int n = nums.size();
    long XOR = 0;
    
    for(int i=0; i < n; i++) {
        XOR ^= nums[i];
    }
    int rightmost = XOR & (XOR - 1) ^ XOR;
    int XOR1 = 0, XOR2 = 0;
    for(int i=0; i < n; i++) {
        /* Divide the numbers among bucket 1
        and 2 based on rightmost set bit */
        if(nums[i] & rightmost) {
            XOR1 = XOR1 ^ nums[i];
        }
        else {
            XOR2 = XOR2 ^ nums[i];
        }
    }
    return {XOR1, XOR2};
}


int main(){
    std::vector<int> nums = {1,2,1,3,2,5};
    std::vector<int> result = singleNumber(nums);
    std::cout << "[";
    for(auto num : result){
        std::cout << num << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}

// 260. Single Number III

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
// Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:
// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

// Example 2:
// Input: nums = [-1,0]
// Output: [-1,0]

// Example 3:
// Input: nums = [0,1]
// Output: [1,0]

// Constraints:
// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.