#include <bits/stdc++.h>

struct Node{
    int value;
    Node* next;

    Node(int val1, Node* next1){
        value = val1;
        next = next1;
    }

    Node(int val1){
        value = val1;
        next = nullptr;
    }
};

class Solution{
public:
    //-------------------------------------------------Brute Force Approach TC->O(N) -- SC->O(N) -------------------
    Node* addOneToLL(Node* head) {
        Node* temp = head;
        long long count = 0;
        while(temp != nullptr){
            count = count * 10 + temp->value;
            temp = temp->next;
        }
        long long val = count + 1;
        std::string strVal = std::to_string(val);
       
        Node* newHead = nullptr;
        Node* tail = nullptr;
        for(int i = 0; i < strVal.length(); i++){
            Node* node = new Node(strVal[i] - '0'); // convert char to int
            node->next = nullptr;
            if (newHead == nullptr) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return newHead;
    }

    // ---------------------------------------------- Recursive Approach TC->O(N) -- SC->O(1)------------------------------
    // Node* addOneToLL(Node* head) {
        
    // }

    void printList(Node* head){
        // Node* temp = head;
        while(head != nullptr){
            std::cout << head->value << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Solution sol;

    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    Node* result = sol.addOneToLL(head);
    std::cout << "Updated List: " << std::endl;
    sol.printList(result);
    return 0;
}

// Add 1 to a number represented by LL

// Problem Statement: Given the head of a singly linked list representing a positive integer number. 
// Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. 
// The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.
// The number will contain no leading zeroes except when the value represented is zero itself.

// Examples
// Input: 4->5->6

// Output: 4->5->7
// Explanation: 456 + 1 = 457
// Input: 9->9->9

// Output: 1->0->0->0
// Explanation: 999 + 1 = 1000