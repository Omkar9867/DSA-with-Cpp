#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(N^2)---------------------------
// int longestOnes(std::vector<int>& nums, int k) {
//     int maxLen = 0;

//     for (int i = 0; i < nums.size(); i++) {
//         int zeros = 0;

//         for (int j = i; j < nums.size(); j++) {

//             // If current element is zero, increment zero count
//             if (nums[j] == 0) {
//                 zeros++;
//             }

//             // If number of zeros exceeds k, break this subarray
//             if (zeros > k) {
//                 break;
//             }

//             // Update max length if this subarray is valid
//             maxLen = std::max(maxLen, j - i + 1);
//         }
//     }
//     return maxLen;
// }

//----------------------------------Optimal Approach--TC->O(N)--SC->O(N)---------------------------
//“I can have at most k zeros in my window. If I exceed that, I shrink from the left until I'm valid again.”
// int longestOnes(std::vector<int>& nums, int k) {
//     int maxLength = 0;
//     int zeroCount = 0;
//     int l = 0, r = 0;
//     while(r < nums.size()){ //Keep r moving 
//         if(nums[r] == 0){
//             zeroCount++;
//         }
//         while(zeroCount > k){
//             if(nums[l] == 0){
//                 zeroCount--;
//             }
//             l++;
//         }
//         maxLength = std::max(maxLength, r - l +1);
//         r++;
//         // std::cout << r << " MaxL: " << maxLength << std:: endl;
//     }
//     return maxLength;
// }

//----------------------------------Optimal Approach2--TC->O(N)--SC->O(N)---------------------------
// remove "while" and add "If" instead
int longestOnes(std::vector<int>& nums, int k) {
    int maxLength = 0;
    int zeroCount = 0;
    int l = 0, r = 0;
    while(r < nums.size()){ //Keep r moving 
        if(nums[r] == 0){
            zeroCount++;
        }
        if(zeroCount > k){
            if(nums[l] == 0){
                zeroCount--;
            }
            l++;
        }
        maxLength = std::max(maxLength, r - l +1);
        r++;
        // std::cout << r << " MaxL: " << maxLength << std:: endl;
    }
    return maxLength;
}

int main(){
    // std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    std::vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    int result = longestOnes(nums, k);

    std::cout << "Result: " << result << std::endl;

    return 0;
}


// 1004. Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length