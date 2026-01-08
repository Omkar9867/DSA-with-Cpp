#include <bits/stdc++.h>


// -------------------------------------Optimal Approach--TC->O(logN)--SC->O(1)-----------------------------------
int singleNonDuplicate(std::vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0]; // to return 1st index itself
    }
    int st = 0, ed = n - 1;
    while(st <= ed){
        int mid = st + (ed - st)/2;
        
        //Edge cases when overflow occurs, it will occur when every mid was perfect and last 2 elem left either 1st or last index for sure
        if (mid == 0 && nums[0] != nums[1])
            return nums[mid]; // if the mid is first index
        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[mid]; // if the mid is last index


        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid - 1]){
            return nums[mid];
        }
        if(mid % 2 == 0){ //even case //!Note to see the index position 
            //if second position then left half becasue correctly going
            if(nums[mid] == nums[mid - 1]){
                ed = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{//odd case
            //if first position then left half because correctly going
            if(nums[mid] == nums[mid + 1]){
                ed = mid - 1;
            }else{
                st = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    std::vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int result = singleNonDuplicate(arr);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// 540. Single Element in a Sorted Array

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 
// Constraints:
// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

//Remembering Appraoch:
// after finding mid,
// see if it repeats in right or left side and return the answer 
// then I have to see if the mid is %2, 
// if it is even , then that num[mid] if 2nd position [even , even], then the range should be seen in left side. Because it is going correctly so double pairs
// if it is odd , then that num[mid] if 1st position [odd , odd], then the range should be seen in left side. Because it is going correctly so double pairs
// To simplify, odd is in first position and even in second is the correct walk