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
    int lengthOfList(Node* node){
        int result = 0;
        while(node != nullptr){
            result++;
            node = node->next;
        } 
        return result;
    }

    //-------------------------------------------------Brute Force Approach O(N+N/2) ~ O(N)-------------------
    // Node* middleNode(Node* head) {
    //     Node*temp = head;
    //     int length = lengthOfList(temp);
    //     int mid = (length / 2);
    //     int i = 0;
    //     while(i < mid){
    //         // mid--;
    //         // if(mid == 0){    //? Can do in both iteration way!
    //         //     break;
    //         // }
    //         temp = temp->next;
    //         i++;
    //     }
    //     return temp;
    // }

    //-------------------------------------------------Optimal Approach O(N+N/2) ~ O(N)-------------------
    Node* middleNode(Node* head) {
        Node*fast = head; 
        Node*slow = head;
        while(fast != NULL && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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

    Node* head = new Node(0);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    Node* result = sol.middleNode(head);
    std::cout << std::endl;
    std::cout << "Middle of the Linked List: " << result->value << std::endl;
    return 0;
}

// 876. Middle of the Linked List

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 
// Constraints:
// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100