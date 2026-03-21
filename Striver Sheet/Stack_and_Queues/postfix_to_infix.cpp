#include <bits/stdc++.h>

//------------------------------------------Approach-TC->O(N)+O(N)---SC->O(N)+O(N)-----------------------------------


std::string postfixToInfix(std::string s){
    std::stack<std::string> st;
    int i = 0;
    while(i < s.size()){
        if(isalnum(s[i])){
            st.push(std::string(1, s[i]));
        }else{
            std::string t1 = st.top() ; st.pop();
            std::string t2 = st.top() ; st.pop();
            std::string conv = '(' + t2 + s[i] + t1 + ')';
            st.push(conv);
        }
        i++;
    }
    return st.top();
}


int main(){
    std::string s = "ab+c*";
    std::string result = postfixToInfix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Postfix to Infix

// Problem Statement: Given a postfix expression (a string), convert it into an equivalent infix expression. The postfix expression is evaluated from left to right. The infix expression should have the proper parentheses to ensure correct operator precedence.

// Write a function to perform this conversion.

// Examples
// Example 1:
// Input:
//  "ab+c*"
// Output:
//  "(a+b)*c"

// Example 2:
// Input:
//  "ab*cd/+"
// Output:
//  "(a*b)+(c/d)"