#include <bits/stdc++.h>

//------------------------------------------Approach-TC->O(N)+O(N)---SC->O(N)-----------------------------------

std::string postfixToPrefix(std::string s){
    std::stack<std::string> st;
    int i = 0;
    while(i < s.size()){ // here we move reverse
        if(isalnum(s[i])){
            st.push(std::string(1, s[i]));
        }else{
            std::string t1 = st.top() ; st.pop();
            std::string t2 = st.top() ; st.pop();
            // 1st: operator, t2, t1
            std::string conv = s[i] + t2 + t1 ; //-> during addition might take time: O(N1 + N2)
            st.push(conv);
        }
        i++;
    }
    return st.top();
}


int main(){
    std::string s = "abc*+d-";
    std::string result = postfixToPrefix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Postfix to Prefix Conversion

// Problem Statement: You are given a valid postfix expression as a string, where:
// Operands are single lowercase English letters ('a' to 'z')
// Operators are binary: '+', '-', '*', '/'
// The expression contains no spaces and is guaranteed to be valid.

// Write a function to convert the postfix expression into a prefix expression, also as a string without spaces.

// Examples
// Example 1:
// Input:
//  expression = "ab+"
// Output:
//  "+ab"
// Explanation:
//  Postfix → Prefix

// Example 2:
// Input:
//  expression = "abc*+d-"
// Output:
//  "-+a*bcd"