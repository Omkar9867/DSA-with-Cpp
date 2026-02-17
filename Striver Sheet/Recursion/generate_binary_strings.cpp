#include <bits/stdc++.h>

//----------------------------------------Approach--TC->O(2^n)--Since each position has 2 choices--SC->O(N)----------------------------------
// At each step, try to place '0' or '1' at the current position.
// You can always place '0'.
// You can place '1' only if the previous character was not '1'.
// Recurse until the length becomes n, and collect all valid strings.

void generate(int n, std::string curr, std::vector<std::string>& result){
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }
    // Always try adding '0'
    generate(n, curr + "0", result);
    
    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
    //So "0" is inserting , 1 will insert at condition
}



int main(){
    int n = 2;
    // Vector to store results
    std::vector<std::string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (std::string& s : result) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}

//             ""
//          /       \
//        "0"        "1"
//       /   \       /
//    "00"  "01"   "10"

// Generate all binary strings

// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s.
// Return the result in lexicographically increasing order.

// A binary string is a string consisting only of characters '0' and '1'.

// Examples
// Example 1:
// Input:
//  n = 3  
// Output:
//  ["000", "001", "010", "100", "101"]  
// Explanation:
//  All binary strings of length 3 that do not contain consecutive 1s.

// Example 2:
// Input:
//  n = 2  
// Output:
//  ["00", "01", "10"]  
// Explanation:
//  All binary strings of length 2 that do not contain consecutive 1s.