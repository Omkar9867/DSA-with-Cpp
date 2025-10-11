#include <iostream>
#include <vector>
using namespace std;


//* This approach gives error: heap-buffer-overflow
// void moveZeroes(vector<int>& nums) {
//     int st = 0, ed = 0;
//     if(nums.size() == 1){
//         return;
//     }
//     while(ed < nums.size()){
//         if(nums[ed] != 0){
//             swap(nums[st], nums[ed]);
//             st++;
//         }else{
//             ed++;
//         }
//     }
// } 

// --------------My Approach--------------
void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[j] , nums[i]);
            j++;
        }
    }
} 

int main(){
    vector<int> arr = {0,1,0,3,12};
    moveZeroes(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ,";
    }
    return 0;
}


// 283. Move Zeroes
// Hint
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]
 
// Constraints:
// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
 