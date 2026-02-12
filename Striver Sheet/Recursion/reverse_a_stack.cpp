#include <bits/stdc++.h>

//----------------------------------------Approach--TC->O(N^2)--SC->O(N)----------------------------------
void insertAtBottom(std::stack<int>& s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    // Pop the top element
    int topVal = s.top();
    s.pop();

    // Recurse for the rest of the stack
    insertAtBottom(s, val);

    // Push the popped element back
    s.push(topVal);
}

void reverseStack(std::stack<int>& st){
    // Base case
    if (st.empty()) return;
    // Top elem
    int topElem = st.top();
    st.pop();
    // Recursively call until empty
    reverseStack(st);
    //Then while coming back insert the pop elem at bottom;
    insertAtBottom(st, topElem);
}



int main(){
    std::stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    reverseStack(s);
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

// Reverse a stack using recursion

// Problem Statement: You are given a stack of integers. Your task is to reverse the stack using recursion. 
// You may only use standard stack operations (push, pop, top/peek, isEmpty). 
// You are not allowed to use any loop constructs or additional data structures like arrays or queues.

// Your solution must modify the input stack in-place to reverse the order of its elements.

// Examples
// Example 1:
// Input:
//  stack = [4, 1, 3, 2]  
// Output:
//  [2, 3, 1, 4]

// Example 2:
// Input:
//  stack = [10, 20, -5, 7, 15]  
// Output:
//  [15, 7, -5, 20, 10]