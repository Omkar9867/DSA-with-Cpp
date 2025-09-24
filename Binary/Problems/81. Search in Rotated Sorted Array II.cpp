#include <iostream>
#include <vector>

bool search(std::vector<int>& nums, int target){
    int n = nums.size();
    int st = 0, ed = n - 1;
    while(st <= ed){
        int mid = st + (ed - st) / 2;
        // std::cout << "Mid now is: " << mid << std::endl;
        if(nums[mid] == target){
            return true;
        }
        // Eliminated the numbers if condition meets arr[st] == arr[mid] == arr[ed];
        else if(nums[st] == nums[mid] && nums[ed] == nums[mid]){
            st = st+1;
            ed = ed-1;
            continue;
        }else if(nums[st] <= nums[mid]){ // means left is sorted
            int exp = nums[st] <= nums[mid];
            // std::cout << "It is left side: " << exp << std::endl;
            if(nums[st] <= target && target <= nums[mid]){
                ed = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(nums[mid] <= target && target <= nums[ed]){
                st = mid + 1;
            }else{
                ed = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    std::vector<int>number = {1,0,1,1,1};
    int target = 0;
    std::cout << "Sorted Array index = " << search(number, target) << std::endl;

    return 0;
}

// 81. Search in Rotated Sorted Array II

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
// You must decrease the overall operation steps as much as possible.

// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
 
// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104