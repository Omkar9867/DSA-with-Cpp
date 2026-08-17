#include <bits/stdc++.h>

class Solution {
public:
    //------------------------------Bitmasking Approach--TC->O(2^n*n)--SC->O(2^n)-----------------------------
    std::vector<int> subsetSums(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> sums;

        // Iterate through all possible bitmasks from 0 to 2^n - 1
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                // If ith bit is set, include arr[i] in sum
                if (mask & (1 << i)) {
                    sum += arr[i];
                }
            }
            sums.push_back(sum);
        }
        sort(sums.begin(), sums.end());
        return sums;
    }

    //------------------------------Recursive Approach--TC->O(2^n)--SC->O(2^n)-----------------------------
    void findSums(int index, int currentSum, std::vector<int>& arr, std::vector<int>& sums) {
        // Base case: if we have considered all elements
        if (index == arr.size()) {
            sums.push_back(currentSum);
            return;
        }

        // Include current element
        findSums(index + 1, currentSum + arr[index], arr, sums);

        // Exclude current element
        findSums(index + 1, currentSum, arr, sums);
    }

    std::vector<int> subsetSums(std::vector<int>& arr) {
        std::vector<int> sums;
        findSums(0, 0, arr, sums);
        std::sort(sums.begin(), sums.end());
        return sums;
    }

    void printResult(std::vector<int> result){
        for (int sum : result) {
            std::cout << sum << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {5, 2, 1};
    std::vector<int> result = sol.subsetSums(arr);

    // Print the subset sums
    sol.printResult(result);

    return 0;
}

// Subset Sum : Sum of all Subsets

// Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

// Examples

// Input: N = 3, arr[] = {5,2,1}
// Output: 0,1,2,3,5,6,7,8
// Explanation: We have to find all the subset’s sum and print them.
// In this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

// Input: N=3,arr[]= {3,1,2}
// Output: 0,1,2,3,3,4,5,6
// Explanation: We have to find all the subset’s sum and print them.
// In this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6