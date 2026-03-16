#include <bits/stdc++.h>

//--------------------------------Brute Force Approach-TC->O(1)--SC->O(N)------------------------------
// class MinStack{
// private:
//     std::stack<std::pair<int, int>> st;
// public:
//     MinStack(){
        
//     }
//     void push(int x) {
//         int minVal = x;
//         if(!st.empty()){
//             int lastMin = st.top().second;
//             minVal = std::min(x, lastMin);
//         }
//         st.push({x, minVal});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

//-------------------------------------Optimal Approach-TC->O(1)--SC->O(1) --------------------------------
class MinStack{
private:
    std::stack<int> st;
    int minVal = 0;
public:
    MinStack(){
        
    }
    void push(int val) {
        if(st.empty()){
            minVal = val;
            st.push(val);
            return;
        }
        // If the value is greater than the minimum
        if(val >= minVal) {
            st.push(val);
        }else{
            // Add the modified value to stack
            st.push(2 * val - minVal); //This modified is like encrypt which is used while decrupt
            // Update the minimum
            minVal = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        int x = st.top();
        st.pop();
        // If the modified value was added to stack
        if(x < minVal) {
            // Update the minimum
            minVal = 2 * minVal - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        int x = st.top();
        if(minVal < x) return x;
        return minVal;
    }
    
    int getMin() {
        return minVal;
    }
};

int main(){
    MinStack stack;
    std::vector<std::string> commands = {"MinStack","push","push","push","getMin","pop","top","getMin"};
    std::vector<std::vector<int>> inputs = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            std::cout << "null ";
        } else if (commands[i] == "pop") {
            stack.pop();
            std::cout << "null ";
        } else if (commands[i] == "top") {
            std::cout << stack.top() << " ";
        } else if (commands[i] == "getMin") {
            std::cout << stack.getMin() << " ";
        } else if (commands[i] == "MinStack") {
            std::cout << "null ";
        }
    }

    return 0;
}

// 155. Min Stack
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.