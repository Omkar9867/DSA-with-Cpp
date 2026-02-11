#include <bits/stdc++.h>

//----------------------------------------Approach--TC->O(N^2)--SC->O(N)----------------------------------

void insert(std::stack<int>& s, int top){
    // Base case: if the stack is empty or temp is larger than the top element
    if (s.empty() || s.top() <= top) {
        s.push(top);
        return;
    }
    // Otherwise pop top elem and recusively insert
    // this refers like your are looping every top until the right placement of above case and while coming up push back the pop ones
    int temp = s.top();
    s.pop();
    insert(s, top);

    //Push the popped elem back
    s.push(temp);
}

void sortStack(std::stack<int>& st){
    if(!st.empty()){
        int topElm = st.top();
        st.pop();
        sortStack(st);
        insert(st, topElm);
    }
}


// If the stack is empty, stop.
// Remove the top element of the stack.
// Sort the remaining stack recursively.
// Insert the removed element back into the stack while maintaining descending order.
// Use a helper function to place the element in its correct position.


int main(){
    std::stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    sortStack(s);
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

// Sort a Stack

// Problem Statement: You are given a stack of integers. Your task is to sort the stack in descending order using recursion, 
// such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). 
// You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

// Examples

// Example 1:
// Input:
//  stack = [4, 1, 3, 2]
// Output:
//  [4, 3, 2, 1]

// Explanation:
//  After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.

// Example 2:
// Input:
//  stack = [1]
// Output:
//  [1]

// Explanation:
//  A single-element stack is already sorted.