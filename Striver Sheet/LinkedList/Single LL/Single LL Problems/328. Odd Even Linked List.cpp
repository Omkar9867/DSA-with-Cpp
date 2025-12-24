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
    //-------------------------------------------------Brute Force Approach TC->O(N) -- SC->O(Nlog) -------------------
    // Node* oddEvenList(Node *head) {
    //     if (!head) return head;
    //     std::queue<int> evenQ;
    //     std::queue<int> oddQ;
    //     Node* temp = head;
    //     while(temp != NULL && temp->next != nullptr){
    //         oddQ.push(temp->val);
    //         evenQ.push(temp->next->val);
    //         temp = temp->next->next;
    //     }
    //     // If odd length, push last odd node
    //     if (temp != nullptr) {
    //         oddQ.push(temp->val);
    //     }
    //     temp = head;
    //     while(oddQ.size() != 0){
    //         temp->val = oddQ.front(); oddQ.pop();
    //         temp = temp->next;
    //     }
    //     while(evenQ.size() != 0){
    //         temp->val = evenQ.front(); evenQ.pop();
    //         temp = temp->next;
    //     }
    //     return head;
    // }

    //! Note this was for the value not the position which differs from question ------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    // Node* oddEvenList(Node *head) {
    //     Node* evenHead = new Node(-1), *evenTail = evenHead; 
    //     Node* oddHead = new Node(-1), *oddTail = oddHead;
    //     Node* curr = head, *temp;
    //     while(curr != NULL){
    //         temp = curr;
    //         curr = curr->next;
    //         temp->next = nullptr; // Ensure The node doesn’t accidentally keep old links, new list ends cleanly
    //         // Append to odd list if value is odd
    //         if(temp->val & 1){
    //             oddTail->next = temp;             //---Connect the node
    //             oddTail = temp;                   //---Move the tail
    //         }else{ // Append to the even list
    //             evenTail->next = temp;
    //             evenTail = temp;
    //         }
    //     }
    //     oddTail->next = evenHead->next;
    //     return oddHead->next;
    // }

    //------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    Node* oddEvenList(Node *head) {
        if (!head || !head->next) return head;
        Node*temp = head;
        Node*even = head->next;
        Node*odd = head;
        Node* evenHead = even;
        while(even != NULL && even->next != nullptr){
            odd->next = even->next; // imagine they are on behind the other
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
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
};

int main(){
    Solution sol;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* result = sol.oddEvenList(head);
    sol.printList(result);
    return 0;
}

// 328. Odd Even Linked List

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
 
// Constraints:
// The number of nodes in the linked list is in the range [0, 104].
// -106 <= Node.val <= 106