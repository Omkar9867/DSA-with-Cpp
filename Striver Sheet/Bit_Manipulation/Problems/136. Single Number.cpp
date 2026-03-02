#include <bits/stdc++.h>

// ----------------------------------Better Approach TC->O(N) --SC->O(N)----------------------------

// int singleNumber(std::vector<int>& nums) {
//     std::unordered_map<int, int> mp;
//     for(int i = 0; i<nums.size(); i++){
//         // mp.insert(nums[i], +1);
//         mp[nums[i]] += 1;
//     }
//     for(const auto& it: mp){
//         if(it.second == 1) return it.first;
//     }
//     return 0;
// }

// ----------------------------------Optimal Approach TC->O(N) --SC->O(1)----------------------------
// Two important properties of XOR are the following:
// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a. ←Property 2
int singleNumber(std::vector<int>& nums) {
    int xorr = 0;
    for(int i = 0; i<nums.size(); i++){
        xorr ^= nums[i]; // here the dupplicate number will be nullify i.e. 0 in the iteration because we know all number comes twice, and the single number 'a' if ^= 0 will give a;
    }
    return xorr;
}


int main(){
    std::vector<int> nums = {4,1,2,1,2};
    std::cout << "Result: " << singleNumber(nums) << std::endl;
    return 0;
}


// 136. Single Number

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1

// Constraints:
// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.