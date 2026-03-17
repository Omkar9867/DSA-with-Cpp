#include <bits/stdc++.h>

//------------------------------------------Approach-TC->O(N)+O(N)---SC->O(N)+O(N)-----------------------------------

int priority(char optr){
    switch (optr){
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

std::string infixToPostfix(std::string s){
    std::stack<char> st;
    std::string ans;
    int i = 0;
    while(i < s.size()){
        if(s[i] == ' ') continue;   // ⭐ FIX
        if((s[i] >= 'A' && s[i] <= 'Z') ||  //* isalnum(s[i])
           (s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }else if(s[i] == '('){
            st.push('(');
        }else if(s[i] == ')'){ //* here until we find the opening bracket add all the operator to ans
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); //* pop the opening bracket also;
        }else{
            while(!st.empty() && (priority(s[i]) <= priority(st.top()))){ //* If priority is lower keep on removing char from stack and add to ans
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){ //*lastly remove all the leftover char
        ans += st.top();
        st.pop();
    }
    return ans;
}


int main(){
    std::string s = "aa + b * (c^d - e) ^ (f + g * h) - i"; // Because if ' ' there is issue
    // std::string s = "a+b*(c^d-e)^(f+g*h)-i";
    std::string result = infixToPostfix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Infix to Postfix

// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.
// Examples
// Example 1:
// Input:
//  a + b * (c^d - e) ^ (f + g * h) - i  
// Output:
//  abcd^e-fgh*+^*+i-  
// Explanation:
  
// The infix expression "a + b * (c^d - e) ^ (f + g * h) - i" is converted to postfix form as "abcd^e-fgh*+^*+i-" by applying the rules of infix to postfix conversion.

// Example 2:
// Input:
//  (p + q) * (m - n)  
// Output:
//  pq+mn-*  
// Explanation:
  
// The infix expression "(p + q) * (m - n)" is converted to postfix form as "pq+mn-*".