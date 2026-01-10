#include <bits/stdc++.h>


// -------------------------------------Brute Force Approach--TC->O(N)--SC->O(1)-----------------------------------
// int findSqrt(int n) {
//     int ans = 0;
//     for (int i = 1; i <= n; i++) {
//         if ((long long)i * i <= n) {
//             ans = i;
//         } else {
//             // Break when i*i > n
//             break;
//         }
//     }
//     return ans;
// }


// -------------------------------------Optimal Approach--TC->O(logN)--SC->O(1)-----------------------------------
int findSqrt(int n) {
    if (n < 2) return n;

    int std = 1, ed = n / 2, ans = 0;

    // Perform binary search
    while (std <= ed) {
        long long mid = std + (ed - std) / 2;

        if (mid * mid <= n) {
            // Store mid as potential answer
            ans = mid;
            std = mid + 1; //!important to modify by +1 and -1
        } else {
            ed = mid - 1;
        }
    }

    // Return final answer
    return ans;
}

int main(){
    int n = 28;
    int result = findSqrt(n);
    std::cout<< "Result: " << result << std::endl;
    return 0;
}

// Finding Sqrt of a number using Binary Search

// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

// Examples

// Input: N = 36
// Output: 6
// Explanation: Square root of 36 is 6. 

// Input: N = 28
// Output: 5
// Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5. 