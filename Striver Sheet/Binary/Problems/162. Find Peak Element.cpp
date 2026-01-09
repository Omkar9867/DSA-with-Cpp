#include <bits/stdc++.h>


// -------------------------------------Brute Forcce Approach--TC->O(N)--SC->O(1)-----------------------------------
// int findPeakElement(std::vector<int>& nums) {
//     int n = nums.size();
    
//     for (int i = 0; i < n; i++) {
//         // Check left neighbor if exists
//         bool left = (i == 0) || (nums[i] >= nums[i - 1]);
//         // Check right neighbor if exists
//         bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);
        
//         // If both sides are valid, return index
//         if (left && right) return i;
//     }

//     // In case no peak found (shouldn't happen)
//     return -1;
// }


// -------------------------------------Optimal Approach--TC->O(logN)--SC->O(1)-----------------------------------
// Thus we know that if current element is greater than its left neighbour, we are in the left half and if our current element is greater than its right neighbour then we are in the right half. If we know the half that we are in currently, we can eliminate it to find our peak element.
int findPeakElement(std::vector<int>& nums) {
    int n = nums.size();
    int st = 0, ed = n - 1;
    while(st < ed){
        int mid = st + (ed - st)/2;
        //! Note to see from left the peak elem by comparing to next one, else if upward slope and next is bigger then we need right side to fing the peak 
        if(nums[mid] > nums[mid+1]){ // move left side if greater then left side
            ed = mid;
        }else { // move right side if greater then right side
            st = mid + 1;
        }
    }
    return st;
}

int main(){
    std::vector<int> arr = {1,2,3,1};
    int result = findPeakElement(arr);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 162. Find Peak Element

// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Example 2:
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
// Constraints:
// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.