#include <bits/stdc++.h>

int partition(std::vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<high){
            i++;
        }
        while(arr[j] > pivot && j>low){
            j--;
        }
        if(i < j) std::swap(arr[i], arr[j]); //!Important condition
    }
    std::swap(arr[low], arr[j]);
    return j;
}

void qs(std::vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    }
}

void sortColors(std::vector<int>& nums) {
    qs(nums, 0, nums.size()-1);
}

int main(){
    std::vector<int> arr = {2,0,2,1,1,0};
    std::cout << "Before Sort: "<< std::endl;
    for(int i = 0; i<arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "After Sort: "<< std::endl;

    sortColors(arr);
    for(int i = 0; i<arr.size(); i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}
//!Learn Quick Sort

// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]
 
// Constraints:
// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?