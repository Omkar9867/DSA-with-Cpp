#include <bits/stdc++.h>

struct Node{
    int val;
    Node* next;

    Node(int val1, Node* next1){
        val = val1;
        next = next1;
    }

    Node(int val1){
        val = val1;
        next = nullptr;
    }
};

class Solution{
public:
    //-------------------------------------------------My Force Approach TC->O(N) -- SC->O(N) -------------------
    // int loopLength(Node *head) {
    //     std::unordered_map<Node*, int> hashedVal;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         if (hashedVal.find(temp) != hashedVal.end()) {
    //             Node* temp1 = temp->next;
    //             int count = 1;
    //             while(temp1 != temp){
    //                 count++;
    //                 temp1 = temp1->next;
    //             }
    //             return count;
    //         }
    //         hashedVal[temp] = 1;
    //         temp = temp->next;
    //     }
    //     return 0;
    // }

    //-------------------------------------------------Brute Force Approach TC->O(N) -- SC->O(N) -------------------
    // Timer approach
    int loopLength(Node *head) {
        std::unordered_map<Node*, int> hashedVal;
        Node* temp = head;
        int timer = 0;
        while(temp != NULL){
            if (hashedVal.find(temp) != hashedVal.end()) {
                return timer - hashedVal[temp];
            }
            hashedVal[temp] = timer++;
            temp = temp->next;
        }
        return 0;
    }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    //*  Tortoise and Hare Algorithm (Floyd’s Cycle Detection).  //
    // Node* loopLength(Node *head) {

    // }

    void printList(Node* head){
        // Node* temp = head;
        while(head != nullptr){
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Solution sol;

    Node* head = new Node(3);
    head->next = new Node(2);
    Node* nodeSecond = head->next;
    // std::cout << nodeSecond->val << std::endl;
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = nodeSecond;

    int result = sol.loopLength(head);
    std::cout << "Result of cycle LL is : "<< result << std::endl;
    return 0;
}


// Length of Loop in Linked List:

// Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.

// Examples
// Input: 
// 1 2 3 4 5 3; 
// Output: 3
// Explanation: A cycle exists in the linked list starting at node 3 -> 4 -> 5 and then back to 3. There are 3 nodes present in this cycle.