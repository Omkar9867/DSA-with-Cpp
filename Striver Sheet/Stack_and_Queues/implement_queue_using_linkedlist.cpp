#include <bits/stdc++.h>

// Node structure
struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
    private:
        Node* start;
        Node* end;
        int size;
    public:
        //Constructor
        LinkedListQueue(int size = 1000) {
            start = end = NULL;
            size = 0;
        }
        //Destructor
        // A destructor is a special function that is automatically called when an object is destroyed. 
        // At the closing brace }, ~LinkedListQueue() executes.
        ~LinkedListQueue(){
            delete start;
            delete end;
        }

        //Push
        void push(int x){
            Node* element = new Node(x);
            if(start == NULL) {
                // Initialise the pointers
                start = end = element;
            }else{
                end->next = element;
                end = element; // or end = end->next //!donot forget
            }
        }

        //Pop
        int pop(){
            if (start == NULL) {
                return -1;
            }
            int val = start->val;
            Node* temp = start; // Store the top temporarily
            start = start->next; // Update top to next node
            delete temp; // Delete old top node (necessary of node stays allocated in memory)
            size--; // Decrement size

            return val;
        }

        //Top
        int peek(){
            if (start == NULL) {
                return -1;
            }
            return start->val;
        }

        bool isEmpty() {
            return (size == 0);
        }

};

int main(){
    LinkedListQueue stack;
    std::vector<std::string> commands = {"LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"};
    std::vector<std::vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            std::cout << "null ";
        } else if (commands[i] == "pop") {
            std::cout << stack.pop() << " ";
        } else if (commands[i] == "peek") {
            std::cout << stack.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            std::cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListQueue") {
            std::cout << "null ";
        }
    }

    return 0;
}

// Implement Queue using Linked List

// Problem Statement: Implement a First-In-First-Out (FIFO) queue using a singly linked list. 
// The implemented queue should support the following operations: push, pop, peek, and isEmpty.

// Implement the LinkedListQueue class:
// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.

// Examples
// Example 1:
// Input:
// ["LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"]  
// [[], [3], [7], [], [], []]  
// Output:
//  [null, null, null, 3, 3, false]  

// Explanation:
// LinkedListQueue queue = new LinkedListQueue();  
// - queue.push(3);  
// - queue.push(7);  
// - queue.peek(); // returns 3  
// - queue.pop(); // returns 3  
// - queue.isEmpty(); // returns false  

// Example 2:
// Input:
//  ["LinkedListQueue", "push", "pop", "isEmpty"]  
// [[], [2], [], []]  
// Output:
//  [null, null, 2, true]  
// Explanation:
 
// LinkedListQueue queue = new LinkedListQueue();  
// - queue.push(2);  
// - queue.pop(); // returns 2  
// - queue.isEmpty(); // returns true