#include <bits/stdc++.h>

// ---------------------------------------Optimal Approach--TC->O(N log N)--SC->O(N)---------------------------------Loop->n & Binary->logn
int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> tails;
    for(int i = 0; i < nums.size(); i++){
        int left = 0, right = tails.size();
        while(left < right){
            int mid = left + (right - left)/2;
            
            if(tails[mid] < nums[i]){
                // the current num must be on right
                left = mid + 1;
            }else{
                // tails[mid] >= num , so search on left
                right = mid;
            }
        }
        if (left == tails.size()) {
            // No element >= current num So num extends the subsequence
            tails.push_back(nums[i]);
        }else {
            // Replace the existing value with a smaller/equal ending value
            tails[left] = nums[i];
        }
    }
    return tails.size();
}

int main(){
    std::vector<int> arr = {10,9,2,5,3,7,101,18};
    int result = lengthOfLIS(arr);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// 300. Longest Increasing Subsequence

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 
// Constraints:
// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
 
//* Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?