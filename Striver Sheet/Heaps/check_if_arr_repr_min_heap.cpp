#include <bits/stdc++.h>

class Solution {
public:
    bool isMinHeap(std::vector<int>& nums) {
        int n = nums.size();

        // Iterate through all non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++) {

            // Calculate the left child index
            int left = 2 * i + 1;

            // If left child exists and is smaller than parent, not a min-heap
            if (left < n && nums[i] > nums[left]) {
                return false;
            }

            // Calculate the right child index
            int right = 2 * i + 2;

            // If right child exists and is smaller than parent, not a min-heap
            if (right < n && nums[i] > nums[right]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    std::vector<int> nums = {10, 20, 30, 21, 23};

    // Output result
    std::cout << (obj.isMinHeap(nums) ? "true" : "false") << std::endl;
    return 0;
}


// Check if an array represents a min heap

// Problem Statement: Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.
// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Examples
// Input: nums = [10, 20, 30, 21, 23]
// Output: true
// Explanation: Each node has a lower or equal value than its children.


// Input: nums = [10, 20, 30, 25, 15]
// Output: false
// Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.