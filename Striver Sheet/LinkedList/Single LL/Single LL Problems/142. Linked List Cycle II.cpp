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
    //-------------------------------------------------Brute Force Approach TC->O(N) -- SC->O(N) -------------------
    // Node* detectCycle(Node *head) {
    //     std::unordered_map<Node*, int> hashedVal;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         if (hashedVal.find(temp) != hashedVal.end()) {
    //             return temp;
    //         }
    //         hashedVal[temp] = 1;
    //         temp = temp->next;
    //     }
    //     return NULL;
    // }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    //*  Tortoise and Hare Algorithm (Floyd’s Cycle Detection).  //
    Node* detectCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //Collided
                slow = head;
                while(slow != fast){ // This will guranteed collide
                    slow = slow->next; // Travel both the L1 distance
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    //?Future reference: https://www.youtube.com/watch?v=2Kd0KKmmHFc

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

    Node* result = sol.detectCycle(head);
    std::cout << "Result of cycle LL is : "<< result << std::endl;
    return 0;
}

// 142. Linked List Cycle II

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
// Note that pos is not passed as a parameter.
// Do not modify the linked list.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
 
// Constraints:
// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
 
// Follow up: Can you solve it using O(1) (i.e. constant) memory?