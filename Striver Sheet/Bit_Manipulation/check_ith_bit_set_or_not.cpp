#include <bits/stdc++.h>

// -----------------------------------Brute Force Approach TC->O(logn) -----------------------------
// Time Complexity: O(log n), due to integer-to-binary conversion and indexing.
// Space Complexity: O(log n), for the binary string.

// bool checkIthBit(int n, int i){
//     std::string binaryForm = "";

//     while(n > 0){
//         binaryForm += (n % 2 == 0 ? '0' : '1');
//         n /= 2;
//     }
//     if( i >= binaryForm.length()) return false;

//     return binaryForm[i] == '1';
// }

// -----------------------------------Optimal Approach--TC->O(1)--SC->O(1)-----------------------

// Use bit masking to isolate the i-th bit in the binary representation of the number.
// By shifting 1 to the left i times, you create a mask where only the i-th bit is set.
// Perform a bitwise AND between the number and the mask to check if that specific bit is active.
// If the result is non-zero, the i-th bit is set to 1; otherwise, it is 0.

//Todo: Understand thoroughly
bool checkIthBit(int n, int i){
    // Check if the i-th bit is set using bitwise AND operation
    return (n & (1 << i)) != 0; // If the ith bit is 1, the result will be non-zero 
}

int main(){
    int num = 5;  // Binary: 101
    int bitIndex = 2;  // Check the 2nd bit (0-based index)

    if (checkIthBit(num, bitIndex)) {
        std::cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << std::endl;
    } else {
        std::cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << std::endl;
    }
    return 0;
}

// Check if the i-th bit is set or not

// Problem Statement: Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1).
// Otherwise, return false.

// Examples

// Example 1:
// Input: 
// n = 5, i = 0
// Output: 
// true
// Explanation: 
// Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

// Example 2:
// Input: 
// n = 10, i = 1
// Output: 
// true
// Explanation: 
// Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).