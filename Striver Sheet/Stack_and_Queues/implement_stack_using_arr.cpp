#include <bits/stdc++.h>

class ArrayStack {
    private:
        int* stackArray; //Holds all arr elements
        int capacity; //Maximum capacity
        int topIndex; //Index of the top element
    public:
        //Constructor
        ArrayStack(int size = 1000) {
            capacity = size;
            stackArray = new int[capacity];
            topIndex = -1;
        }
        //Destructor
        // A destructor is a special function that is automatically called when an object is destroyed. 
        // At the closing brace }, ~ArrayStack() executes.
        ~ArrayStack(){
            delete[] stackArray;
        }

        //Push
        void push(int x){
            if(topIndex > capacity - 1){
                std::cout << "Stack overflow" << std::endl;
                return;
            }
            stackArray[++topIndex] = x;
            std::cout << "Top idx" << topIndex << std::endl;
        }

        //Pop
        int pop(){
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return -1; 
            }
            return stackArray[topIndex--];
        }

        //Top
        int top(){
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return -1; 
            }
            return stackArray[topIndex];
        }

        bool isEmpty() {
            return topIndex == -1;
        }

};

int main(){
    ArrayStack stack;
    std::vector<std::string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    std::vector<std::vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            std::cout << "null ";
        } else if (commands[i] == "pop") {
            std::cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            std::cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            std::cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            std::cout << "null ";
        }
    }

    return 0;
}

// Implement Stack using Array

// Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array.
// The implemented stack should support the following operations: push, pop, peek, and isEmpty.

// Implement the ArrayStack class:

// void push(int x): Pushes element x onto the stack. int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it. boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// Examples
// Example 1:
// Input:
  
// ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]  
// [[], [5], [10], [], [], []]  
// Output:
//   [null, null, null, 10, 10, false]  
// Explanation:
//   ArrayStack stack = new ArrayStack();  
// - stack.push(5);  
// - stack.push(10);  
// - stack.top(); // returns 10  
// - stack.pop(); // returns 10  
// - stack.isEmpty(); // returns false  

// Example 2:
// Input:
  
// ["ArrayStack", "isEmpty", "push", "pop", "isEmpty"]  
// [[], [], [1], [], []]  
// Output:
//  [null, true, null, 1, true]  
// Explanation:
//   ArrayStack stack = new ArrayStack();  
// - stack.push(1);  
// - stack.pop(); // returns 1  
// - stack.isEmpty(); // returns true