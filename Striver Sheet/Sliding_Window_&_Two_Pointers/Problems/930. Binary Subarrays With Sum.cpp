#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// TimeLimit--- Exceeds
// int numSubarraysWithSum(std::vector<int>& nums, int goal) {
//     int maxCount = 0;
//     for(int i = 0; i<nums.size(); i++){
//         int sum = 0;
//         for(int j = i; j<nums.size(); j++){
//             sum += nums[j];
//             if(sum == goal){
//                 maxCount++;
//             }
//         } 
//     }
//     return maxCount;
// }

//----------------------------------Better Approach--TC->O(N)--SC->O(n)--------------------------
// int numSubarraysWithSum(std::vector<int>& nums, int goal) {
//     // Hashmap to store prefix sum frequencies
//     std::unordered_map<int, int> prefixSumCount;

//     int count = 0, sum = 0;

//     // Add base case: prefix sum 0 has frequency 1
//     prefixSumCount[0] = 1;

//     // Iterate through the array
//     for (int num : nums) {
//         // Add current element to prefix sum
//         sum += num;

//         // If (sum - goal) exists in map, add its frequency to count
//         if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
//             count += prefixSumCount[sum - goal];
//         }

//         prefixSumCount[sum]++;
//     }

//     // Return total count of valid subarrays
//     return count;
// }

//----------------------------------Optimal Approach--TC->2(N)--SC->O(1)---------------------------
//!Understand welll Todo
int atMost(std::vector<int>& nums, int k) {
    // If k is negative, no such subarrays exist
    if (k < 0) return 0;

    int left = 0;
    int sum = 0;
    int count = 0;

    // Traverse the array using right pointer
    for (int right = 0; right < nums.size(); right++) {
        // Add current element to sum
        sum += nums[right];

        // Shrink the window from the left if sum exceeds k
        while (sum > k) {
            sum -= nums[left];
            left++;
        }

        // Add the number of valid subarrays ending at right
        count += (right - left + 1);
    }

    return count;
}
int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    // Return difference between subarrays with sum at most goal and at most (goal - 1)
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main(){
    std::vector<int> nums = {0,0,0,0,0};
    // std::vector<int> nums = {1,0,1,0,1};
    int k = 0;
    int result = numSubarraysWithSum(nums, k);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// 930. Binary Subarrays With Sum

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.

// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

// Example 2:
// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
 
// Constraints:
// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length