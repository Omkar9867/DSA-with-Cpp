#include <bits/stdc++.h>

//-----------------------------------------Approach--TC->O(N)---SC->O(N)-------------------------------
bool isValid(std::string s) {
    std::stack<char> st;
    for (auto it : s) {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);  // Push opening brackets to stack
        else {
            if (st.empty()) return false;  // No matching opening bracket, because never opened so not valid
            char ch = st.top();
            st.pop();

            // Check for matching pair
            if ((it == ')' && ch == '(') ||
                (it == ']' && ch == '[') ||
                (it == '}' && ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main(){
    std::string s = "()";
    std::cout << "Result: " << isValid(s) << std::endl;
    return 0;
}

// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Example 5:
// Input: s = "([)]"
// Output: false

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.