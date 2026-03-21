#include <bits/stdc++.h>

//------------------------------------------Approach-TC->O(N)+O(N)---SC->O(N)-----------------------------------

std::string postfixToInfix(std::string s){
    std::stack<std::string> st;
    int i = s.size();
    while(i >= 0){ // here we move reverse
        if(isalnum(s[i])){
            st.push(std::string(1, s[i]));
        }else{
            std::string t1 = st.top() ; st.pop();
            std::string t2 = st.top() ; st.pop();
            std::string conv = t1 + t2 + s[i]; //-> during addition might take time: O(N1 + N2)
            st.push(conv);
        }
        i--;
    }
    return st.top();
}


int main(){
    std::string s = "*+ab-cd";
    std::string result = postfixToInfix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Prefix to Postfix Conversion

// Problem Statement: You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.

// Prefix (Polish) notation places the operator before operands.
// Postfix (Reverse Polish) notation places the operator after operands.

// Examples
// Example 1:
// Input:
//  expression = "+ab
// Output:
//  ab+

// Example 2:
// Input:
//  expression = "*+ab-cd
// Output:
//  ab+cd-*