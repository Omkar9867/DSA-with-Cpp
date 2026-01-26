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
    // ---------------------------------------------- My Approach TC->O(N) -- SC->O(1)------------------------------
    // int lengthOfNode(Node* head) {
    //     int count = 0;
    //     Node* temp = head;
    //     while(temp != nullptr){
    //         temp = temp->next;
    //         count++;
    //     }
    //     return count;
    // }
    // Node* removeNthFromEnd(Node* head, int n) {
    //     Node* temp = head;
    //     int length = lengthOfNode(head);
    //     std::cout << "Length: " << length << std::endl;
    //     int k = length - n;
    //     int count = 0;
    //     while(count != k){
    //         temp = temp->next;
    //         count++;
    //     }  

    //     if(temp->next == nullptr){
    //         delete temp;
    //     }
    //     temp->value = temp->next->value;
    //     temp->next = temp->next->next;

    //     return head;
    // }

    //----------------------------Correct Approach-TC->O(N)------------------------
    Node* removeNthFromEnd(Node* head, int n) {
        Node dummy(0);
        dummy.next = head;

        Node* fast = &dummy;
        Node* slow = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        Node* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        return dummy.next;
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

    Node* head = new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    int n = 1;
    Node* result = sol.removeNthFromEnd(head, n);
    // int length = sol.lengthOfNode(head);
    // std::cout << "Length: "<< length << std::endl;
    std::cout << "After removing Nth Node in Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}

// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]
 
// Constraints:
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 
//! Follow up: Could you do this in one pass?