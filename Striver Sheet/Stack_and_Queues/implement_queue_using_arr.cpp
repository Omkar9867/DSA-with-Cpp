#include <bits/stdc++.h>

class ArrayQueue {
    private:
        int* array; //Holds all arr elements
        int capacity, currSize; //Maximum capacity
        int start, end; // Indices for start and end of the queue
    public:
        //Constructor
        ArrayQueue(int size = 10) {
            start = -1;
            end = -1;
            capacity = size;
            currSize = 0;
            array = new int[capacity];
        }
        //Destructor
        // A destructor is a special function that is automatically called when an object is destroyed. 
        // At the closing brace }, ~ArrayQueue() executes.
        ~ArrayQueue(){
            delete[] array;
        }

        //Push
        void push(int x){
            if(currSize == capacity){
                std::cout << "Queue overflow" << std::endl;
                exit(1);
            }
            if(end == -1){
                start = 0;
                end = 0;
            }else{
                end = (end + 1) % capacity; //! Circular increment of end
            }
            array[end] = x;
            currSize++;
        }

        //Pop
        int pop(){
            if (isEmpty()) {
                std::cout << "Queue is empty" << std::endl;
                exit(1); 
            }
            int pooped = array[start];
            // See before removing if the current size was 1
            if(currSize == 1){
                start = -1;
                end = -1;
            }else{
                start = (start + 1) % capacity; //! Circular increment of start
            }
            currSize--;
            return pooped;
        }

        // Method to get the front element of the queue
        int peek() {
            // Check if the queue is empty
            if (isEmpty()) {
                std::cout << "Queue is Empty" << std::endl;
                exit(1);
            }
            return array[start];
        }

        bool isEmpty() {
            return (currSize == 0);
        }

};

int main(){
    ArrayQueue queue;
    std::vector<std::string> commands = {"ArrayQueue", "push", "push", "peek", "pop", "isEmpty"};
    std::vector<std::vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            std::cout << "null ";
        } else if (commands[i] == "pop") {
            std::cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            std::cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            std::cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            std::cout << "null ";
        }
    }

    return 0;
}

// Implement Queue Using Array

// Problem Statement: Implement a First-In-First-Out (FIFO) queue using an array. 
// The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

// Implement the ArrayQueue class:

// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.

// Examples
// Example 1:
// Input:
 
// ["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]  
// [[], [5], [10], [], [], []]  
// Output:
//  [null, null, null, 5, 5, false]  
// Explanation:
  
// ArrayQueue queue = new ArrayQueue();  
// - queue.push(5);  
// - queue.push(10);  
// - queue.peek(); // returns 5  
// - queue.pop(); // returns 5  
// - queue.isEmpty(); // returns false  

// Example 2:
// Input:
  
// ["ArrayQueue", "isEmpty"]  
// [[]]  
// Output:
//  [null, true]  

// Explanation:
  
// ArrayQueue queue = new ArrayQueue();  
// - queue.isEmpty(); // returns true