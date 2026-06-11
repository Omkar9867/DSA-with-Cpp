#include <bits/stdc++.h>

class Solution {
// public:
    //-------------------------------Brute Force---TC->O(NlogK)
    // int findKthLargest(std::vector<int>& nums, int k) {
    //     std::priority_queue <int, std::vector<int>, std::greater<int>> pq;
        
    //     for(int i = 0; i < k; i++) pq.push(nums[i]);
        
    //     // Process the rest of the elements 
    //     for(int i = k; i < nums.size(); i++) {
    //         if(nums[i] > pq.top()) {
                
    //             pq.pop(); // remove the smallest from the min-heap
                
    //             // Add the current element to the min-heap
    //             pq.push(nums[i]); 
    //         }
    //     }
        
    //     return pq.top();
    // }

    //-------------------------------Optimal Force---TC->O(N)--------------Quick-Select-----
    //* Assuming the array gets divided into two equal parts, with every partitioning step, the search range is reduced by half. Thus, the time complexity is O(N + N/2 + N/4 + ... + 1) = O(N).

    //* In the worst-case scenario (when the element at the left or right index is chosen as the pivot):
    //* In such cases, the array is divided into two unequal halves, and the search range is reduced by one element with every partitioning step. Thus, the time complexity is O(N + N-1 + N-2 + ... + 1) = O(N2). However, the probability of this worst-case scenario is negligible.
private:
    // Function to get a random index 
    int randomIndex(int &left, int &right) {
        // length of the array 
        int len = right - left + 1;
        
        // Return a random index from the array 
        return (rand() % len) + left;
    }
    
    // Function to perform the partition and return the updated index of pivot
    int partitionAndReturnIndex(std::vector<int> &nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex]; // Get the pivot element
        
        // Swap the pivot with the left element
        std::swap(nums[left], nums[pivotIndex]);
        
        int ind = left + 1; // Index to mark the start of right portion
        
        // Traverse on the array 
        for(int i = left + 1; i <= right; i++) {
            
            // If the current element is greater than the pivot
            if(nums[i] > pivot) {
                // Place the current element in the left portion
                std::swap(nums[ind], nums[i]);
                
                // Move the right portion index
                ind++;
            }
        }
        
        std::swap(nums[left], nums[ind-1]); // Place the pivot at the correct index
        
        return ind-1; // Return the index of pivot now
    }

public:
    int findKthLargest(std::vector<int>& nums, int k) {
        //Edge case
        if(k > nums.size()) return -1;
        
        // Pointers to mark the part of working array 
        int left = 0, right = nums.size() - 1;
        
        while(true) {
            // Get the pivot index
            int pivotIndex = randomIndex(left, right);
            
            // Update the pivotIndex
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);
            
            // If Kth largest element is found, return
            if(pivotIndex == k-1) return nums[pivotIndex];
            
            // Else adjust the end pointers in array 
            else if(pivotIndex > k-1) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
        
        return -1;
    }


    void printResult(int result){
        std::cout << "Result: " << result << std::endl;
    }
};

int main(){
    Solution obj;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = obj.findKthLargest(nums, k);
    
    obj.printResult(result);

    return 0;
}

// 215. Kth Largest Element in an Array

// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

//* Can you solve it without sorting?

// Example 1:
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 
// Constraints:
// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104