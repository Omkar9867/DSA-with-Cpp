#include <bits/stdc++.h>

struct Node{
    int value;
    Node* next;

    Node(int value1){
        value = value1;
        next = nullptr;
    }
};

class Solution{
public:
    bool isElementPresent(Node* head, int n){
        while(head != nullptr){
            if(head->value == n){
                return true;
            }
            head = head->next;
        }
        return false;
    }

    void printList(Node* head){
        while(head != nullptr){
            std::cout << head->value << " ";
            head = head->next;
        }
        std::cout << std:: endl;
    }
};


int main(){
    Solution sol;

    Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);

    int n = 8;

    bool result = sol.isElementPresent(head, n);
    std::cout << "Result : " << result << std::endl;

    return 0;
}

// Problem Statement: 
// Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. 
// Return true if it is present, or else return false.

// Examples:

// Input: 0->1->2, val = 2
// Output: True
// Explanation: Since element 2 is present in the list, return true.

// Input: 12->5->8->7, val = 6 
// Output: False
// Explanation: The list does not contain element 6. Therefore, return false.