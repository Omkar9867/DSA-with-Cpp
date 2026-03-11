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

class LinkedListStack {
    private:
        Node* head; //Top of the node
        int size;
    public:
        //Constructor
        LinkedListStack(int size = 1000) {
            head = NULL;
            size = 0;
        }
        //Destructor
        // A destructor is a special function that is automatically called when an object is destroyed. 
        // At the closing brace }, ~LinkedListStack() executes.
        ~LinkedListStack(){
            delete[] head;
        }

        //Push
        void push(int x){
            Node* element = new Node(x);
            //Connect the existing head to new node
            element->next = head;
            // Re-assign the head to the new made node
            head = element;
            size++;
        }

        //Pop
        int pop(){
            if (head == NULL) {
                return -1;
            }
            int val = head->val;
            Node* temp = head; // Store the top temporarily
            head = head->next; // Update top to next node
            delete temp; // Delete old top node (necessary of node stays allocated in memory)
            size--; // Decrement size

            return val;
        }

        //Top
        int top(){
            if (head == NULL) {
                return -1;
            }
            return head->val;
        }

        bool isEmpty() {
            return (size == 0);
        }

};

int main(){
    LinkedListStack stack;
    std::vector<std::string> commands = {"LinkedListStack", "push", "push", "pop", "top", "isEmpty"};
    std::vector<std::vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

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
        } else if (commands[i] == "LinkedListStack") {
            std::cout << "null ";
        }
    }

    return 0;
}


// Implement stack using linked list

// Problem Statement: Implement a Last-In-First-Out (LIFO) stack using a singly linked list.
// The implemented stack should support the following operations: push, pop, top, and isEmpty.

// Implement the LinkedListStack class:
// void push(int x): Pushes element x onto the stack.
// int pop(): Removes and returns the top element of the stack.
// int top(): Returns the top element of the stack without removing it.
// boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// Examples

// Example 1:
// Input:
  // ["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]  
// [[], [3], [7], [], [], []]  
// Output:
//   [null, null, null, 7, 3, false]  
// Explanation:
//   LinkedListStack stack = new LinkedListStack();  
// - stack.push(3);  
// - stack.push(7);  
// - stack.pop(); // returns 7  
// - stack.top(); // returns 3  
// - stack.isEmpty(); // returns false  

// Example 2:
// Input:
// ["LinkedListStack", "isEmpty"]  
// [[]]  
// Output:
//   [null, true]  
// Explanation:
//   LinkedListStack stack = new LinkedListStack();  
// - stack.isEmpty(); // returns true