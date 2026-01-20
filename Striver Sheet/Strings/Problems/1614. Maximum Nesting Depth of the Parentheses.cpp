#include <bits/stdc++.h>

int maxDepth(std::string s) {
    int count = 0; 
    int balance = 0; //Helps to keep track of balance parenthesis
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            balance++; // I will keep adding which will nullify the decrement in else condition
            count = std::max(count, balance);
        }else if(s[i] == ')'){
            balance--; // I will keep subracting which will nullify the increment in if condition
        }
    }
    return count;
}

int main(){
    std::string inputArr = "(1+(2*3)+((8)/4))+1";
    int result = maxDepth(inputArr);

    std::cout << "Result: " << result << std::endl;
    return 0;
}

// 1614. Maximum Nesting Depth of the Parentheses

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:
// Input: s = "()(())((()()))"
// Output: 3

// Constraints:
// 1 <= s.length <= 100
// s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
// It is guaranteed that parentheses expression s is a VPS.