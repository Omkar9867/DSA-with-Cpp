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
    //-------------------------------------------------Brute Force Approach TC->O(N) -- SC->O(N) -------------------
    //Hint: Since stacks follow Last-In-First-Out (LIFO) order, popping elements from the stack gives us the values in reverse order. 
    // After the stack is filled, we reassign the values to the nodes while traversing the original list again. 
    // This effectively reverses the list in terms of values without modifying node links.
    // Node* reverseList(Node* head) {
    //     Node* temp = head;
    //     std::stack<int> st; 
    //     while(temp != NULL){
    //         st.push(temp->value);
    //         temp = temp->next;
    //     }
    //     // Reset the temp to head as it got null above;
    //     temp = head;
    //     while(temp != NULL){
    //         temp->value = st.top();
    //         st.pop();
    //         temp = temp->next;
    //     }
    //     return head; //! Understand That [temp->value = st.top()] rewrites values inside nodes, not the nodes themselves.
    // }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    // Node* reverseList(Node* head) {
    //     Node* prev = NULL;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         Node* front = temp->next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = front;
    //         // std::cout<< "Prev val : " << prev->value << std::endl; 
    //         // std::cout<< "Next temp : " << temp->next->value << std::endl; 
    //         // std::cout<< "Curr temp : " << temp->value << std::endl; 
    //     }
    //     return prev;
    // }

    // ---------------------------------------------- Recursive Approach TC->O(N) -- SC->O(1)------------------------------
    Node* reverseList(Node* head) {
        if(head == NULL || head->next == nullptr){
            return head;
        }
        Node* newHead = reverseList(head->next); 
        Node* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* result = sol.reverseList(head);
    std::cout << "Reverse of the Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}

// 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []
 
// Constraints:
// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
 