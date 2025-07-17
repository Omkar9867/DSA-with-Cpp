#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k){
    // for(int i = nums.size() - 1; i >= nums.size() - k; i--){
    //     nums.insert(nums.begin(), nums[i]);
    //     nums.erase(nums.begin() + i + 1);
    // }
    int i = 0;
    int n = nums.size() - 1;
    while(i<k){
       nums.insert(nums.begin(), nums[n]);
        nums.erase(nums.begin() + n + 1);
        i++ ;
    }
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