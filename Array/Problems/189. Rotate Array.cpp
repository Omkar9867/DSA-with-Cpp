#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------Brute Force Approach----------------
// Time limit exceed, where insert takes O(n) as well as erase, so it is running k times
//If both n and k are large, this results in a quadratic time complexity (O(n * k)), which can easily lead to a Time Limit Exceeded (TLE) error.

void rotate(vector<int>& nums, int k){
    int i = 0;
    int n = nums.size() - 1;
    while(i<k){
       nums.insert(nums.begin(), nums[n]);
        nums.erase(nums.begin() + n + 1);
        i++ ;
    }
};

// -------------------------Optimal Approach TC--->O(n)--SC-->O(1)-------------------
void rotate(vector<int>& nums, int k){
    k = k % nums.size(); // Handle cases where k >= nums.size()
    
    // Reverse the entire vector
    reverse(nums.begin(), nums.end());
    
    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
    
    // Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(arr, k);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ,";
    }
    return 0;
}


// 189. Rotate Array
// Hint
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 
// Constraints:
// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105