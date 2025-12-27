#include <bits/stdc++.h>

//------------------------------Optimal Approach--TC->O(N)--SC->(1)------------------------
// int maxSubArray(std::vector<int>& nums){
//     int maxSum = INT_MIN;
//     int sum = nums[0];
//     for(int i = 0; i < nums.size(); i++){
//         sum = std::max(nums[i], sum + nums[i]);
//         maxSum = std::max(maxSum, sum);
//     }
//     return maxSum;
// }

//------------------------------Kadane's Algorithm--TC->O(N)--SC->(1)------------------------
// int maxSubArray(std::vector<int>& nums){
//     int maxSum = INT_MIN;
//     int sum = 0;
//     for(int i = 0; i < nums.size(); i++){
//         sum += nums[i];
//         if(sum > maxSum){
//             maxSum = sum;
//         }
//         if(sum < 0){  //-------Main kadan's addon --(Is it better to start a new subarray here, or continue the previous one?)
//             sum = 0;
//         }
//     }
//     return maxSum;
// }

// ---------------------------------------------------------------------------------------------------------------------------------
// =============================================================Extended============================================================
// ---------------------------------------------------------------------------------------------------------------------------------

//*Return subArray print
std::vector<int> maxSubArray(std::vector<int>& nums){
    int maxSum = INT_MIN;
    int sum = 0;
    int tempStart = 0;
    int bestStart = 0, bestEnd = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] > sum + nums[i]){
            sum = nums[i];
            tempStart = i;
        }else{
            sum += nums[i];
        }
        if(maxSum < sum){
            maxSum = sum;
            bestStart = tempStart;
            bestEnd = i;
        }
    }
    return std::vector<int>(nums.begin() + bestStart, nums.begin() + bestEnd + 1);  //Key rule to remember (🔥 interview favorite) 
                                                                                    //STL ranges are always [start, end) — end is NOT included
}



int main(){
    std::vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    // int result = maxSubArray(arr);
    // std::cout << "Result: " << result << std::endl;
    std::vector<int> result = maxSubArray(arr);
    for(int i = 0; i<result.size(); i++){
        std::cout << result[i] << " ";
    }

    return 0;
}

// 53. Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

//! Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.