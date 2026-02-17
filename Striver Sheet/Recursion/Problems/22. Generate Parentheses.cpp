#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(2^2n * N)---SC->O(N)---------------------------------
// bool isValid(std::string s){
//     int balance = 0;
//     for (char c : s) {
//         if (c == '(') balance++;
//         else balance--;
//         if (balance < 0) return false;
//     }
//     return balance == 0;

// }

// void generateAll(std::string curr, int n, std::vector<std::string>& result){
//     if(curr.length() == 2*n){
//         if(isValid(curr)) result.push_back(curr);
//         return;
//     }
//     generateAll(curr + "(", n, result);
//     generateAll(curr + ")", n, result);
// }

// std::vector<std::string> generateParenthesis(int n) {
//     std::vector<std::string> res;
//     generateAll("", n, res);
//     return res;
// }

//----------------------------------Optimal Approach-----------------------------------
// Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
// Each sequence takes O(n) to build.
// So, total complexity: O(C(n) × n)

// Space Complexity: O(n) recursion depth.
// O(C(n) × n) to store results.

void backtrack(std::string curr, int open, int close, int n, std::vector<std::string>& result){
    if(curr.length() == 2*n){
        result.push_back(curr);
        return;
    }
    if(open < n) backtrack(curr+"(", open + 1, close, n, result);
    if(close < open) backtrack(curr+")", open, close + 1, n, result); //!Important close < open not "n"
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    backtrack("", 0, 0, n, res);
    return res;
}

// Start with an empty string curr = "".
// Initialize counters: open = 0, close = 0.
// If open < n, add '(' and recurse.
// If close < open, add ')' and recurse.
// If curr.length == 2 * n, add it to the result.

int main(){
    int n = 3;
    std::vector<std::string> result = generateParenthesis(n);
    for (std::string s : result) std::cout << s << std::endl;
    return 0;
}

// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]
 
// Constraints:
// 1 <= n <= 8