#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//

//------------------------------------Brute force TC-->O(n^2)-----------------------
// int singleNumber(vector<int> nums){
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         int count = 0;
//         for(int j = 0; j < n; j++){
//             if(nums[i] == nums[j]){
//                 count++;
//             }
//         }
//         if(count == 1){
//             return nums[i];
//         }
//     }
// }

//------------------------------------Better Approach TC-->O(n) but SC-->O(n)-----------------------
// int singleNumber(vector<int> nums){
//     int n = nums.size();
//     unordered_map<int, int> hashArr;
//     for(int i = 0; i < n; i++){
//         hashArr[nums[i]] += 1;
//     }
//     for(const auto& it : hashArr){
//         if(it.second == 1){
//             return it.first;
//         }
//     }
// }

// -----------------------------------Optimal Approach Bitwise xor Approach---TC-->O(n) but SC-->O(1) -----------------
int singleNumber(vector<int> nums){
    int n = nums.size();
    int xorr = 0;
    for(int i = 0; i < n; i++){
        xorr ^= nums[i]; 
    }
    return xorr;
}

int main(){
    vector<int> arr = {4,1,2,1,2};
    int result = singleNumber(arr);
    cout << "Result: " << result << endl;
    return 0;
}


// 136. Single Number

// Hint
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1

// Constraints:
// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.