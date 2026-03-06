#include <bits/stdc++.h>

//---------------------------------Brute Force Approach--TC->O(N)----------------------------
// XOR is useful for combining values in a reversible way, applying it twice cancels the effect.
// To find the XOR of all numbers in a range, we can combine them one by one using XOR.
// Start with an initial value that doesn't affect the result (i.e., 0).
// As each number is XORed in, the result captures the cumulative effect of all values.
// The final result after traversing the range holds the complete XOR of that range.

int findXor(int l, int r) {
    int ans = 0;
    for(int i = l; i <= r; i++){
        ans ^= i;
    }
    return ans;
}

// ------------------------------Optimal Approach---TC->O(1) ---------------------------
// The XOR of numbers from 1 to n follows a predictable pattern based on n % 4.
// This pattern helps compute XOR from 1 to any number n in constant time.
// To get XOR of numbers in the range [L, R], compute XOR(1 to R) and XOR(1 to L - 1).
// Apply XOR between these two results, common prefixes cancel out due to XOR properties.
// This approach avoids looping through the range and achieves optimal performance.

int XORtillN(int n){
    if (n%4 == 1) return 1;
    if (n%4 == 2) return 2;
    if (n%4 == 3) return 3;
    return n;
}

int findXor(int l, int r) {
    return XORtillN(l-1) ^ XORtillN(r);
}

int main(){
    int l = 1, r = 3;
    int result = findXor(l, r);
    std::cout << "Result: " << result <<  std::endl;
    return 0;
}

// Find XOR of numbers from L to R

// Problem Statement: Given two integers L and R. Find the XOR of the elements in the range [L , R].

// Examples

// Example 1:
// Input : L = 3 , R = 5
// Output : 2
// Explanation : answer = (3 ^ 4 ^ 5) = 2.

// Example 2:
// Input : L = 1, R = 3
// Output : 0
// Explanation : answer = (1 ^ 2 ^ 3) = 0.