#include <bits/stdc++.h>

//------------------------------------------Approach-TC->O(N)+O(N)---SC->O(N)-----------------------------------

std::string postfixToInfix(std::string s){
    std::stack<std::string> st;
    int i = s.size();
    while(i >= 0){ // here we move reverse
        if(isalnum(s[i])){
            st.push(std::string(1, s[i]));
        }else{
            std::string t1 = st.top() ; st.pop(); // here we t1 - t2 not t2 - t1
            std::string t2 = st.top() ; st.pop();
            std::string conv = '(' + t1 + s[i] + t2 + ')'; //-> during addition might take time: O(N1 + N2)
            st.push(conv);
        }
        i--;
    }
    return st.top();
}


int main(){
    std::string s = "+ab";
    std::string result = postfixToInfix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Prefix to Infix Conversion

// Problem Statement: You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.
// Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.

// Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

// Examples
// Example 1:
// Input:
//  expression = "+ab
// Output:
//  (a+b)

// Example 2:
// Input:
//  expression = "*+ab-cd
// Output:
//  ((a+b)*(c-d))