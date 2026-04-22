#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// TimeLimit--- Exceeds
// int numberOfSubarrays(std::vector<int>& nums, int k) {
//     int count = 0;

//     for (int i = 0; i < nums.size(); i++) {
//         int oddCount = 0;

//         for (int j = i; j < nums.size(); j++) {
//             // Check if current number is odd
//             if (nums[j] % 2 != 0)
//                 oddCount++;

//             // If odd count exceeds k, break (not nice)
//             if (oddCount > k) break;

//             // If odd count is exactly k, count this subarray
//             if (oddCount == k)
//                 count++;
//         }
//     }
//     return count;
// }

//----------------------------------Better Approach--TC->O(N)--SC->O(n)--------------------------
// int numberOfSubarrays(std::vector<int>& nums, int k) {
//     std::unordered_map<int, int> freq;
//     freq[0] = 1;

//     // Running count of odd numbers in the current prefix
//     int oddCount = 0;
//     // Total number of nice subarrays
//     int result = 0;

//     for (int num : nums) {

//         // Check if current number is odd and update count
//         if (num % 2 == 1) oddCount++;

//         // If there exists a prefix with (current odd count - k), add its frequency to result
//         if (freq.count(oddCount - k)) {
//             result += freq[oddCount - k];
//         }

//         // Update the frequency of current odd count
//         freq[oddCount]++;
//     }
//     return result;
// }

//----------------------------------Optimal Approach--TC->2(N)--SC->O(1)---------------------------
int countAtMost(std::vector<int>& nums, int k) {
    int left = 0, res = 0;

    for (int right = 0; right < nums.size(); right++) {
        // If current number is odd, reduce k
        if (nums[right] % 2 != 0)
            k--;

        // Shrink the window until k is valid
        while (k < 0) {
            if (nums[left] % 2 != 0) k++;
            left++;
        }

        res += (right - left + 1);
    }

    return res;
}
int numberOfSubarrays(std::vector<int>& nums, int k) {
    return countAtMost(nums, k) - countAtMost(nums, k - 1);
}

int main(){
    std::vector<int> nums = {1, 1, 2, 1, 1};
    // std::vector<int> nums = {1,0,1,0,1};
    int k = 3;
    int result = numberOfSubarrays(nums, k);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

// 1248. Count Number of Nice Subarrays

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.

// Example 3:
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 
// Constraints:
// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length