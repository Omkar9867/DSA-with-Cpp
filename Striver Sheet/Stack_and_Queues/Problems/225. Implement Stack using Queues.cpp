#include <bits/stdc++.h>

class MyStack {
private:
    std::queue<int>* q;
public:
    MyStack() {
        q = new std::queue<int>();
    }
    
    void push(int x) {
        if(empty()){
            exit(1);
        }
        int s = q->size(); 
        // Add element
        q->push(x); 
        for(int i=0; i<s; i++){
            q->push(q->front()); 
            q->pop(); 
        }
    }
    
    int pop() {
        int n = q->front(); 
        // Remove front element
        q->pop(); 
        // Return removed element
        return n; 
        //Can write?
        // return q->pop();
    }
    
    int top() {
        // Return front element
        return q->front();
    }
    
    bool empty() {
        return q->empty();
    }
};

int main(){
    MyStack queue;
    std::vector<std::string> commands = {"MyStack","push","push","top","pop","empty"};
    std::vector<std::vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            std::cout << "null ";
        } else if (commands[i] == "pop") {
            std::cout << queue.pop() << " ";
        } else if (commands[i] == "top") {
            std::cout << queue.top() << " ";
        } else if (commands[i] == "empty") {
            std::cout << (queue.empty() ? "true" : "false") << " ";
        } else if (commands[i] == "MyStack") {
            std::cout << "null ";
        }
    }
    return 0;
}

// 225. Implement Stack using Queues

// Implement a last-in-first-out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

// Example 1:
// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]

// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
 

// Constraints:

// 1 <= x <= 9
// At most 100 calls will be made to push, pop, top, and empty.
// All the calls to pop and top are valid.
 

// Follow-up: Can you implement the stack using only one queue?