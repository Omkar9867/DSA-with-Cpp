#include <iostream>
#include <vector>

// ------------------------------------My Approach----------------------------------
int rotatedArrNum(std::vector<int>& nums){
    int n = nums.size();
    int st = 0, ed = n - 1;
    if(nums[st] < nums[ed]){
        return 0; // handled condition where already sorted and returned the index
    }
    while(st<=ed){
        int mid = st + (ed - st)/2;
        // if around mid is the actual answer
        if(nums[mid] > nums[mid + 1]){
            return mid + 1;
        }
        if(nums[mid - 1] > nums[mid]){
            return mid;
        }
        // by decreasing the find length the mid will give us answer eventually
        if(nums[mid] > nums[st]){
            st = mid + 1;
        }else{
            ed = mid - 1;
        }
    }
    return 0;
}

int main(){
    std::vector<int> arr = {4,5,6,7,0,1,2,3};
    int result = rotatedArrNum(arr);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Find out how many times the array has been rotated

// Problem Statement: 
// Given an integer array arr of size N, sorted in ascending order (with distinct values). 
// Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

// Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

// Examples
// Input : arr = [4,5,6,7,0,1,2,3]
// Result: 4
// Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

// Input : arr = [3,4,5,1,2]
// Output : 3
// Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.