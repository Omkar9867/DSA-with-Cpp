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
    bool hasCycle(Node *head) {
        std::unordered_map<Node*, int> hashedVal;
        Node* temp = head;
        while(temp != NULL){
            if (hashedVal.find(temp) != hashedVal.end()) {
                return true;
            }
            hashedVal[temp] = 1;
            temp = temp->next;
        }
        return false;
    }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    bool hasCycle(Node *head) {
        
    }

    // ---------------------------------------------- Recursive Approach TC->O(N) -- SC->O(1)------------------------------

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

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Node* result = sol.reverseList(head);
    // std::cout << "Reverse of the Linked List: " << std::endl;
    // sol.printList(result);
    return 0;
}