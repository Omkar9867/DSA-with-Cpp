#include <bits/stdc++.h>

// -----------------------------------------Brute Force Approach--TC->O(N + N/2)--SC->(N/2)------------------------------------
// std::vector<int> rearrangeArray(std::vector<int>& nums) {
//     std::vector<int> positiveArr = {};
//     std::vector<int> negativeArr = {};
//     std::vector<int> arrangedArr = nums;
//     for(int i = 0; i<nums.size(); i++){
//         if(nums[i] > 0){
//             positiveArr.push_back(nums[i]);
//         }else{
//             negativeArr.push_back(nums[i]);
//         }
//     }
//     for(int i = 0; i < nums.size() / 2; i++){ // Important "/2"
//         arrangedArr[2*i] = positiveArr[i];
//         arrangedArr[2*i + 1] = negativeArr[i];
//     }
//     return arrangedArr;
// }

// -----------------------------------------Optimal Approach--TC->O(N)--SC->(1)------------------------------------
// Key: To maintain positive and negative index after each insert
std::vector<int> rearrangeArray(std::vector<int>& nums) {
    int posIndx = 0;
    int negIndx = 1;
    std::vector<int> arrangedArr(nums.size(), 0); // Understand here temp required, because updating the nums, will create issue in position while looping
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] > 0){
            arrangedArr[posIndx] = nums[i];
            posIndx += 2;
        }else{
            arrangedArr[negIndx] = nums[i];
            negIndx += 2;
        }
    }
    return arrangedArr;
}

int main(){
    std::vector<int> arr = {3,1,-2,-5,2,-4};
    std::vector<int> result = rearrangeArray(arr);
    for(int i = 0; i<result.size(); i++){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// 2149. Rearrange Array Elements by Sign

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Example 1:
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

// Example 2:
// Input: nums = [-1,1]
// Output: [1,-1]
// Explanation:
// 1 is the only positive integer and -1 the only negative integer in nums.
// So nums is rearranged to [1,-1].
 
// Constraints:
// 2 <= nums.length <= 2 * 105
// nums.length is even
// 1 <= |nums[i]| <= 105
// nums consists of equal number of positive and negative integers.
 

// It is not required to do the modifications in-place.