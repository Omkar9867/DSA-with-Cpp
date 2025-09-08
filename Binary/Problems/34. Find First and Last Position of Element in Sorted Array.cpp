#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target){
    std::vector<int> result = {};
    int n = nums.size();
    if(n == 0) return {-1, -1}; 
    if(n == 1){
        if (nums[0] == target){
            return {0, 0};
        }else{
            return {-1, -1};
        }
    }
    int st = 0, ed = n -1;
    while(st <= ed){
        int mid = st + (ed - st)/2;
        if(nums[mid] == target){
            int left = mid, right = mid;
            while(left > 0 && nums[left - 1] == target) left --;
            while(right < n -1 && nums[right + 1] == target) right ++;
            result.push_back(left);
            result.push_back(right);
            return result;
        }else if(nums[mid] > target){
            ed = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return {-1, -1};
}

int main(){
    std::vector<int> arr = {1, 4};
    int target = 4;
    std::vector<int> result = searchRange(arr, target);
    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << " " ; 
    }
    return 0;
}

// 34. Find First and Last Position of Element in Sorted Array

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
 
// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109