#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0 , ed = nums.size() -1;

    while(st <= ed){
        int mid = st + (ed-st) / 2;
        if(target == nums[mid]){
            return mid;
        }
        
        if(nums[st] <= nums[mid]){ //This assure that left part is sorted. and then we can write the binary search here.
            if(nums[st] <= target && target <= nums[mid]){ // this logic sees whether the target is inside the sorted array or not
                ed = mid -1; // end will be updated so the next iteration will take the mid from left side
            } else{
                st = mid + 1; // end will be updated so the next iteration will take the mid from right side
            } 
        }else{ //Right sorted
            if(nums[mid] <= target && target <= nums[ed]){ //since the right one is sorted we will check from right side
                st = mid + 1;
            }else{ //since not on the left side we'll go ti right side then
                ed= mid -1 ;
            }
        }
    } 
    return -1;
}

int main(){
    vector<int>number = {4,5,6,7,0,1,2};
    int target = 0;

    cout << "Sorted Array index = " << search(number, target) << endl;

    return 0;
}

//Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 
// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

//Basically the first approach in mind would be the Linear Search where looping in the array we found the target O(n)
//Now while the question tells the word sorted. That time always think for the Binary Search Approach O(logn)