#include <iostream>
#include <vector>
// using namespace std;

// Since it is a sorted arr then binary search should be the first option

int search(std::vector<int>& nums, int target) {
    int st = 0, ed = nums.size() - 1;
    while(st <= ed){
        //ed - st is safe as long as ed >= st
        int mid = st + (ed-st) / 2; //! (st + ed) / 2 can cause integer overflow if st and ed are large.
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            ed = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return -1;
}

int main(){
    std::vector<int> arr = {-1,0,3,5,9,12};
    int k = 9;
    int result = search(arr, k);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.
// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 
// Constraints:
// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.