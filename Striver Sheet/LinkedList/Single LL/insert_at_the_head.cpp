#include <bits/stdc++.h>

class Node {
public:
    int data; // Data value
    Node* next; // pointer to next node
    
    // Constructor with data and next
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Solution{
public:
    Node* insertAtHead(Node* head, int t){ // t is the new val that should be in head
        Node* newPointer = new Node(t, head);
        return newPointer;
        // Here simply, created a new node, where the head is the new value now and rest are the data
    }

    void printList(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Solution sol;
    // Create a head
    Node* head = new Node(2);
    head->next = new Node(3);

    std::cout << "Original List: ";
    sol.printList(head);

    // INsert the new value in head
    int t = 1;
    head = sol.insertAtHead(head, t); 

    std::cout << "After Insertion at Head: ";
    sol.printList(head);

    return 0;
}