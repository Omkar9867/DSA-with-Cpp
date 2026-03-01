#include <bits/stdc++.h>

// -----------------------------------Brute Force Approach TC->O(logn) -----------------------------
int setRightmostBit(int n){
    std::string binaryForm = "";
    while(n > 0){
        binaryForm += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    // for(int i = binaryForm.size() - 1; i >= 0; i--){ // This did not worked because it was not //!reversed
    //     if(binaryForm[i] == '0') {
    //         binaryForm[i] = '1';
    //         break;
    //     };
    // }
    for(int i = 0; i < binaryForm.size(); i++){
        if(binaryForm[i] == '0') {
            binaryForm[i] = '1';
            break;
        }
    }
    int num = 0;
    for(int i = 0; i < binaryForm.size(); i++){
        num += (binaryForm[i] - '0') * (1 << i);
    }
    return num;
}

// -----------------------------------Optimal Approach TC->O(1)-------------------------
// Use bitwise OR with n + 1:
// result = n | (n + 1)
// n + 1 flips the rightmost 0 in n to 1, and all bits to the right become 0.
// Performing OR sets that bit to 1 while leaving other bits unchanged
int setRightmostBit(int n){
    return n | (n+1);
}


int main(){
    // int num = 13;  // Binary: 1101
    int num = 10; //(binary: 1010)  

    std::cout << "Result : " << setRightmostBit(num) << std::endl;
    return 0;
}


//* Set the rightmost bit

// Problem Statement: Given a positive integer n, set the rightmost unset (0) bit of its binary representation to 1 and return the resulting integer.
// If all bits are already set, return the number as it is.

// Examples
// Example 1:
// Input:
//  n = 10 (binary: 1010)  
// Output:
//  11 (binary: 1011)  
// Explanation:
//   The rightmost unset bit is the least significant bit (LSB). Setting it to 1 gives 1011 = 11.

// Example 2:
// Input:
//  n = 7 (binary: 111)  
// Output:
//  7 (binary: 111)  
// Explanation:
//   All bits are already set to 1, so the number remains the same.