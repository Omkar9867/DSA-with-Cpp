#include <bits/stdc++.h>

//----------------Brute Force will take -- TC->O(N! * N) -----SC -> (N!)------------- 
// N! to generate all for length N ==> O(N! * N)
//!👎❌ No Brute Force

//--------------------------------------------------Better Solution--TC->O()---SC->O()---------------------------

// void nextPermutation(std::vector<int>& nums) {
    
// }

//--------------------------------------------------Optimal Solution--TC->O(N)---SC->O(1)---------------------------
// 1. First iterate the arr from reverse order and look for the fall in a rising order and break and store the index
// 2. Then iterate the arr again in reverse order till the stored index , and swap when a value found bigger then the indexed val.
//* Purpose is we are following longer prefix match // Reference: https://www.youtube.com/watch?v=JDOXKqF60RQ
// 3. Now the next possible permutation is ready , just after the indexedVal all the other are in descending order as expected, because thery were in rising order
// 4. return the arr which is the answer.  
// 5. Edge case: if index is -1, reverse whole arr.

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int index = -1;
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        std::reverse(nums.begin(), nums.end()); // Edge Case
        return;
    }
    for(int i = n-1; i >= index; i--){
        if(nums[i] > nums[index] ){
            std::swap(nums[i], nums[index]);
            break;
        }
    }
    std::reverse(nums.begin() + index + 1, nums.begin() + n);
}

int main(){
    std::vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    for(int i = 0; i<arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

// 31. Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
// then the next permutation of that array is the permutation that follows it in the sorted container. 
// If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 
// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:
// Input: nums = [1,1,5]
// Output: [1,5,1]
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100