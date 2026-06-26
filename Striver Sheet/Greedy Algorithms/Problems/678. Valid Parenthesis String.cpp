#include <bits/stdc++.h>

class Solution {
public:

//--------------------------- Approach--TC->O(N)-SC->O(1)-----------------------
    bool checkValidString(std::string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                // Treat '*' as '(', ')' or ''
                minOpen--;
                maxOpen++;
            }

            // If maxOpen goes negative, too many closing brackets
            if (maxOpen < 0) return false;

            // minOpen should not be negative
            minOpen = std::max(minOpen, 0);
        }
        
        return minOpen == 0;
    }

    void printResult(bool result){
        std::cout << "Result: " << result << std::endl;
    }
};

int main(){
    Solution obj;
    std::string s = "(*))(";
    bool result = obj.checkValidString(s);
    
    obj.printResult(result);

    return 0;
}

// 678. Valid Parenthesis String

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true
 
// Constraints:
// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.