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
//!Understand well
    // ---------------------------------------------- Optimal Approach TC->O(N+M) -- SC->O(1)------------------------------
    Node* mergeTwoLists(Node *list1, Node* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        Node* head = list1;
        Node* prev = nullptr; //Tail
        while(list1 != nullptr && list2 != nullptr){
            if(list2->val <= list1->val){
                Node* list2Next = list2->next;
                // Insert list2 node before list1
                if (prev != nullptr) {
                    prev->next = list2;
                } else {
                    // list2 node becomes the new head
                    head = list2;
                }
                list2->next = list1;
                prev = list2;
                list2 = list2Next;
            }else{
                prev = list1;
                list1 = list1->next;
            }
        }
        // Attach remaining list2 nodes
        if (list2 != nullptr) {
            prev->next = list2;
        }
        return head;
    }

    void printList(Node* head){
        // Node* temp = head;
        while(head != nullptr){
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    Node* buildList(std::vector<int>& values) {
    Node dummy(0);
    Node* tail = &dummy;
 
    for (int value : values) {
        tail->next = new Node(value);
        tail = tail->next;
    }
 
    return dummy.next;
}
};

int main(){
    Solution sol;
    std::vector<int> values = {1, 2, 4};
    std::vector<int> values2 = {1, 3, 4};
    Node* list1 = sol.buildList(values);
    Node* list2 = sol.buildList(values2);

    Node* result = sol.mergeTwoLists(list1, list2);
    std::cout << "Result of merged sorted list: " << std::endl;
    sol.printList(result);
    return 0;
}

// 21. Merge Two Sorted Lists

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]
 
// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.