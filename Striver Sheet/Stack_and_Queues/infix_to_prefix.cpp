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

std::string prefixToInfix(std::string s){
    std::reverse(s.begin(), s.end());
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
            while(!st.empty() && (priority(s[i]) < priority(st.top()))){ //* Enhance condition where it should be only small not even equal
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
    std::reverse(ans.begin(), ans.end());
    return ans;

}


int main(){
    std::string s = "x+y*z/w+u";
    std::string result = prefixToInfix(s);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Infix to Prefix

// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a prefix expression.

// Examples
// Example 1:
// Input:
//  x + y * z / w + u  
// Output:
//  ++x/*yzwu  
// Explanation:
  
// The infix expression "x + y * z / w + u" is converted to prefix form as "++x/*yzwu" by applying the rules of infix to prefix conversion.

// Example 2:
// Input:
//  a + b  
// Output:
//  +ab  
// Explanation:
  
// The infix expression "a + b" is converted to prefix form as "+ab".