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