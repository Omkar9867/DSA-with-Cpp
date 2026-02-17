#include <bits/stdc++.h>

//----------------------------------Brute Force Approach--TC->O(2^2n * N)---SC->O(N)---------------------------------
bool isValid(std::string s){
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;

}

void generateAll(std::string curr, int n, std::vector<std::string>& result){
    if(curr.length() == 2*n){
        if(isValid(curr)) result.push_back(curr);
        return;
    }
    generateAll(curr + "(", n, result);
    generateAll(curr + ")", n, result);
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    generateAll("", n, res);
    return res;
}

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