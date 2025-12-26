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

// void sortColors(std::vector<int>& nums) {
//     qs(nums, 0, nums.size()-1);
// }

// -----------------------------------------Brute Force Approach TC->O(N) ---SC->O(1) --------------------------------------
// void sortColors(std::vector<int>& nums) {
//     // Initialize count variables for 0s, 1s, and 2s
//     int count0 = 0, count1 = 0, count2 = 0;

//     // Count the frequency of 0s, 1s, and 2s in the array
//     for(int i = 0; i < nums.size(); i++) {
//         if(nums[i] == 0) count0++;
//         else if(nums[i] == 1) count1++;
//         else count2++;
//     }

//     // Overwrite the array with the counted values
//     int index = 0;

//     // Fill with 0s
//     while(count0--) {
//         nums[index++] = 0;
//     }

//     // Fill with 1s
//     while(count1--) {
//         nums[index++] = 1;
//     }

//     // Fill with 2s
//     while(count2--) {
//         nums[index++] = 2;
//     }
// }

//!--------------------------------=============Dutch National Flag algorithm================-------------------------------
//-------------------------------------------------Optimal Approach--------------------------------
void sortColors(std::vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            std::swap(nums[mid], nums[low]);
            mid++;
            low++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }  
}
// This is an iterative approach where mid will play with the numbers 0, 1 and 2 and assign according to the low , high and mid himself and iterate appropriately

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