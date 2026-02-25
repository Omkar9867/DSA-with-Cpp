#include <bits/stdc++.h>

// -----------------------------------Brute Force Approach TC->O(logn) becasue travel all bits once -----------------------------
// int countSetBits(int n){
//     int count = 0;
//     while(n > 0){
//         // if (n & 1 == 1) count++;
//         //Also written as :
//         count += (n & 1);  // Check if the least significant bit is set (1)
//         n >>= 1;
//     }
//     return count;
// }

// -----------------------------------Optimal Approach--TC->O(k)--SC->O(1)-----------------------
//where k is the number of set bits (often faster than checking all bits).

// Function to count the number of set bits (1s) in the binary representation of n using Brian Kernighan's Algorithm
int countSetBits(int n) {
    int count = 0;  // Variable to store the count of set bits

    // Step 1: While n is non-zero, turn off the rightmost set bit
    while (n) {
        n &= (n - 1);  //algorithm Turn off the rightmost set bit
        count++;  // Increment the count
    }

    // Step 2: Return the count of set bits
    return count;
}

int main(){
    int num = 13;  // Binary: 1101

    std::cout << "Total set bits in num is : " << countSetBits(num) << std::endl;
    return 0;
}

// Count the number of set bits

// Problem Statement: Given an integer n, return the number of set bits (1s) in its binary representation.
//! Can you solve it in O(log n) time complexity?

// Examples

// Example 1:
// Input: 
// n = 5
// Output:
//  2
// Explanation: 
// The binary representation of 5 is 101, which has 2 set bits.

// Example 2:
// Input: 
// n = 15
// Output: 
// 4
// Explanation: 
// The binary representation of 15 is 1111, which has 4 set bits.