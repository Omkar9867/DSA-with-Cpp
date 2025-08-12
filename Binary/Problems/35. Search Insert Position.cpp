
#include <iostream>
#include <vector>

// ------------------ My Approach-----------------
int searchInsert(std::vector<int>& nums, int target) {
    int n = nums.size() - 1;
    int st = 0, ed = n;
    int ans = n;
    while(st <= ed){
        int mid = st + (ed - st)/2;
        if(nums[mid] >= target){
            ans = mid;
            ed = mid - 1;
        }else{
            ans = mid + 1;
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    std::vector<int> arr = {1,3,5,6};
    int k = 7;
    int result = searchInsert(arr, k);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}
// 35. Search Insert Position

// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4
 
// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104