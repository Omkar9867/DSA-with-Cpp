#include <bits/stdc++.h>

class Solution {
public:
//---------------------------Brute Force--TC->O(NlogN)---------------------------------
    // std::vector<int> sortNearlySortedArray(std::vector<int>& arr, int k) {
    //     std::sort(arr.begin(), arr.end());
    //     return arr;
    // }

//---------------------------Optimal Approach--TC->O(NlogK)---------------------------------
//!understand well
// First push into min heap upto k+1 elem, because the smallest must lie somewhere in that section {arr[0 ... k]}
// Then make an empty result, to pop the smallest i.e. top form the minheap
// During this process , empty the remaining vector arr also by pushing inside the (min-heap) so sorting is correct 
// Make sure in the edge case to empty the remaining heap 
    std::vector<int> sortNearlySortedArray(std::vector<int>& arr, int k) {
        // Create a min heap using priority_queue with greater comparator
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
       
        std::vector<int> result;

        // Push first k+1 elements into the heap
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }
        // Process the remaining elements of the array
        for (int i = k + 1; i < arr.size(); i++) {
            // Push the smallest element from the heap to the result
            result.push_back(minHeap.top());
            minHeap.pop();

            // Push the current element into the heap
            minHeap.push(arr[i]);
        }

        // Pop remaining elements from the heap
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;  
    }

    std::vector<int> printList(std::vector<int> nums){
        for(int i = 0; i<nums.size(); i++){
            std::cout << nums[i] << " " << std::endl;
        }
    }

};

int main(){
    std::vector<int> nums = {};
    int k = 1;

    Solution sol;
    std::vector<int> result = sol.sortNearlySortedArray(nums, k);


    return 0;
}


// Sort K sorted array

// Problem Statement: Given an array arr[] and a number k . The array is sorted in a way that every element is at max k distance away from it sorted position. 
// It means if we completely sort the array, then the index of the element can go from i - k to i + k where i is index in the given array. 
// Our task is to completely sort the array.

// Examples
// Input :  arr = [6, 5, 3, 2, 8, 10, 9], k = 3  
// Output :  [2, 3, 5, 6, 8, 9, 10]  
// Explanation :  The element 2 was at index 3, it moved to index 0. The element 3 was at index 2, it moved to index 1. 
// The element 5 moved from index 1 to index 2. The element 6 moved from index 0 to index 3. The rest (8, 9, 10) were near their correct spots and shifted slightly.

// Input :  arr = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2  
// Output :  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
// Explanation :  The element 2 moved from index 3 to index 1. The element 3 moved from index 4 to index 2. 
// The element 4 moved from index 1 to index 3. The element 5 moved from index 2 to index 4. All others remained in or near their correct positions.