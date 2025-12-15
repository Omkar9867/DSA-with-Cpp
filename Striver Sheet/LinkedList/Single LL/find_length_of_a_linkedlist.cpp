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
    int lengthOfList(Node* node){
        int result = 0;
        while(node != nullptr){
            std::cout << node->value << " ";
            result++;
            node = node->next;
        } 
        return result;
    }

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

    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);

    // sol.printList(head);
    int result = sol.lengthOfList(head);
    std::cout << std::endl;
    std::cout << "Length of the Linked List: " << result << std::endl;
    return 0;
}

// Find the Length of a Linked List

// Problem Statement: Given the head of a linked list, print the length of the linked list.

// Examples
// Input: 0->1->2 
// Output: 3
// Explanation: The list has a total of 3 nodes, thus the length of the list is 3.

// Examples
// Input: 12->5->8->7
// Output: 4
// Explanation: The list has a total of 4 nodes, thus the length of the list is 4.
