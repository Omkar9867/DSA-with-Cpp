#include <bits/stdc++.h>

class Solution {
private:
    // Recursion
    void func(int ind, std::string digits, std::string s, std::vector<std::string> &ans, std::string combos[]) {
        // Base case: if index reaches the end of digits
        if(ind == digits.size()) {
            ans.push_back(s);
            return;
        }
        // Convert the current character to an integer
        int digit = digits[ind] - '0';
        // Loop through the corresponding characters
        for(int i = 0; i < combos[digit].size(); i++) {
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
        }
    }

public:
    // ----------------------------------Approach-TC->O(4^N * N)----------------------------------because each digit can map to up to 4 letters, and there are n digits.
    std::vector<std::string> letterCombinations(std::string digits) {
        std::string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> result;
        std::string s = ""; // Temp string

        func(0, digits, s, result, combos);
        return result;
    }
};

int main() {
    Solution solution;
    std::string digits = "23"; // Input digits
    std::vector<std::string> result = solution.letterCombinations(digits); // Get combinations

    // Print the results
    for (const std::string& combination : result) {
        std::cout << combination << " ";
    }
    return 0;
}

// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
// Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example :
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = "2"
// Output: ["a","b","c"]
 
// Constraints:
// 1 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].