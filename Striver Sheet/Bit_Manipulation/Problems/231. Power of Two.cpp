#include <bits/stdc++.h>

// -----------------------------------Approach TC->O(1) -----------------------------

// Power of two numbers have exactly one bit set in their binary form.
// Subtracting one flips all bits after the set bit, creating no overlap with the original number. //! Note how a binary will only have one 1 rest 0? when previous was all 1. 
//! That 1 becomes 0
//! All right bits become 1
//! So there is no position where both numbers have 1
// A bitwise AND between the number and one less than itself will be zero only for powers of two.
// 1000
// 0111
// -----
// 0000
// This property allows for a fast check without looping or dividing.


bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n-1)) == 0; // Check if n is greater than 0 and has only one bit set
}


int main(){
    int num = 16;  // Binary: 101

    if (isPowerOfTwo(num)) {
        std::cout << "The " << num << " is Power of two." << std::endl;
    } else {
        std::cout << "The " << num << " is not Power of two." << std::endl;
    }
    return 0;
}

// 231. Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 24 = 16

// Example 3:
// Input: n = 3
// Output: false
 
// Constraints:
// -231 <= n <= 231 - 1
 
//! Follow up: Could you solve it without loops/recursion?