#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------Brute Force Approach O(n^2)----------------
// int missingNumber(vector<int>& nums){

//     // Outer loop that runs from 1 to N:
//     for (int i = 0; i <= nums.size(); i++) {

//         // flag variable to check
//         //if an element exists
//         int flag = 0;

//         //Search the element using linear search:
//         for (int j = 0; j < nums.size(); j++) {
//             if (nums[j] == i) {

//                 // i is present in the array:
//                 flag = 1;
//                 break;
//             }
//         }

//         // check if the element is missing
//         //i.e flag == 0:

//         if (flag == 0) return i;
//     }

//     // The following line will never execute.
//     // It is just to avoid warnings.
//     return -1;
// };

//-------------------------------Better Approach TC-->O(n) but SC-->O(n)----------------
// int missingNumber(vector<int>& nums){
//     int hashArr[nums.size()] = {0};
//     // storing the frequencies of each nums val
//     for(int i = 0; i < nums.size(); i++){
//         hashArr[nums[i]]++;
//     };
//     for(int i = 0; i < nums.size(); i++){
//         if(hashArr[i] == 0) return i;
//     };
    
// }

// -------------------------------Optimal Approach 1 TC-O(n)-------------------------
// int missingNumber(vector<int>& nums){
//     int n = nums.size();
//     int sumOfn = n * (n+1) / 2;
//     int sumOfVal = 0;
//     for (int i = 0; i < n; i++){
//         sumOfVal += nums[i];
//     }
//     return sumOfn - sumOfVal;
// }


// ------------------------------- XOR Approach TC-O(n) -- SC(1)----(//*Details explain last)-------------------------
int missingNumber(vector<int>& nums){
    int n = nums.size();
    int xor1 = 0 , xor2 = 0;
    for (int i = 0; i < n; i++){
        xor1 ^= nums[i];
        xor2 ^= i + 1;
    }
    return xor1 ^ xor2;
}


int main(){
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    int result = missingNumber(arr);
    cout << "Result: " << result << endl;
    return 0;
}


// 268. Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation:
// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation:
// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

// Constraints:

// n == nums.length
// 1 <= n <= 104
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

// Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?


// XOR Approach:
// Intuition:
// Two important properties of XOR are the following:

// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// Now, let’s XOR all the numbers between 1 to N.
// xor1 = 1^2^.......^N

// Let’s XOR all the numbers in the given array.
// xor2 = 1^2^......^N (contains all the numbers except the missing one).

// Now, if we again perform XOR between xor1 and xor2, we will get:
// xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N)

// Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. 
// The result will be = 0 ^ (missing number) = missing number (according to property 2).