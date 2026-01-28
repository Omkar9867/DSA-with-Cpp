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
    //--------------------------------------------Brute Force Approach-TC->O(2N + NlogN) -- SC->O(N)---------------------------------
    // Node* sortList(Node* head) {
    //     Node* temp = head;
    //     std::vector<int> arr = {};
    //     while(temp != nullptr){
    //         arr.push_back(temp->val);
    //         temp = temp->next;
    //     }
    //     std::sort(arr.begin(), arr.end());
    //     temp = head;
    //     for(int i = 0; i < arr.size(); i++){
    //         temp->val = arr[i];
    //         temp = temp->next;
    //     }
    //     return head;
    // }

    //--------------------------------------------Optimal Approach-TC->O(NlogN) -- SC->O(1)---------------------------------
    // We can try to implement a modified version of Merge Sort Algorithm. This algorithm would divide the linked list into halves recursively until single nodes remain. 
    // These sorted halves of the linked list are merged back together in a sorted order.
    Node* mergeSortedLL(Node* l1, Node* l2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        //traverse both ls
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val >= l2->val){
                temp->next = l2;
                l2 = l2->next; 
            }else{
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        // Attach remaining nodes
        if (l1 != nullptr) {
            temp->next = l1;
        } else {
            temp->next = l2;
        }
        // return dummnode next linked
        return dummyNode->next;
    }

    Node* findMiddle(Node* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        Node* slow = head;
        Node* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* sortList(Node* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        Node* middle = findMiddle(head);
        Node* right = middle->next; // middle next element will be right start (head)
        middle->next = nullptr; //for left to have till middle its next to be nullptr
        Node* left = head;
        left = sortList(left);
        right = sortList(right);
        // Merge sorted halves
        return mergeSortedLL(left, right);
    }

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

    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);

    Node* result = sol.sortList(head);
    std::cout << "After removing Middle Node in Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}


// 148. Sort List

// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:
// Input: head = []
// Output: []
 
// Constraints:
// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105