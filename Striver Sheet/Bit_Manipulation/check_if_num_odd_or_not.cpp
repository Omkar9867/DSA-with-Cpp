#include <bits/stdc++.h>

// -----------------------------------Approach TC->O(1) -----------------------------

bool checkOdd(int n){
    return n % 2 != 0;
}


int main(){
    int num = 5;  // Binary: 101

    if (checkOdd(num)) {
        std::cout << "The " << num << " is odd." << std::endl;
    } else {
        std::cout << "The " << num << " is not odd." << std::endl;
    }
    return 0;
}

// Check if a number is odd or not

// Problem Statement: Given a non-negative integer n, determine whether it is odd.
// Return true if the number is odd, otherwise return false. A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

// Example 1:
// Input:
//  n = 7
// Output:
//  true
// Explanation:
//  7 is not divisible by 2. Hence, it is odd.

// Example 2:
// Input:
//  n = 10
// Output:
//  false
// Explanation:
//  10 is divisible by 2. Hence, it is not odd.