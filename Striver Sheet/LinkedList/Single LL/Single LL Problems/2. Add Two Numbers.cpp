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
    //-------------------------------------------------My Approach TC->O(N) -- SC->O(N) -------------------
    // Node* addTwoNumbers(Node* l1, Node* l2){
    //     Node* newHead = nullptr;
    //     Node* tail = nullptr;
    //     int carry = 0;
    //     while(l1 != nullptr || l2 != nullptr){
    //         int x = (l1 != nullptr) ? l1->value : 0;
    //         int y = (l2 != nullptr) ? l2->value : 0;
    //         int sum = (x + y + carry); //Note not to directlty do %10, simce we need the last val ahead
    //         carry = sum / 10; // Here
    //         Node* node = new Node(sum % 10);
    //         node->next = nullptr;
    //         if(newHead == nullptr){
    //             newHead = node;
    //             tail = node;
    //         }else{
    //             tail->next = node;
    //             tail = node;
    //         }
    //         if (l1) l1 = l1->next;
    //         if (l2) l2 = l2->next;
    //     }
    //     // handle edge case //!-----Obsolete------------
    //     // if(l1 != nullptr){
    //     //     while(l1 != nullptr){
    //     //         int sum = l1->value + carry;
    //     //         Node* node = new Node(sum % 10);
    //     //         node->next = nullptr;
    //     //         tail->next = node;
    //     //         tail = node;
    //     //         l1 = l1->next;
    //     //         carry = sum / 10;
    //     //     }
    //     // }
    //     // if(l2 != nullptr){
    //     //     while(l2 != nullptr){
    //     //         int sum = l2->value + carry;
    //     //         Node* node = new Node(sum % 10);
    //     //         node->next = nullptr;
    //     //         tail->next = node;
    //     //         tail = node;
    //     //         l2 = l2->next;
    //     //         carry = sum / 10;
    //     //     }
    //     // }
    //     if (carry > 0) {
    //         tail->next = new Node(carry);
    //     }

    //     return newHead;
    // }

    //------------------------------------------------- Approach TC->O(N) -- SC->O(N) -------------------
    Node* addTwoNumbers(Node* l1, Node* l2){
        //Initialize a dummy node as a new node
        Node *dummy = new Node(-1); 
        Node *temp = dummy; 
        //Carry will be carried to the next new node created
        int carry = 0;
        //Iterate till the end of both the lists
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->value; 
                l1 = l1 -> next; 
            }
            //Repeat the same process for l2 as l1
            if(l2 != NULL) {
                sum += l2 -> value; 
                l2 = l2 -> next; 
            }
            //Carry gets added to sum in the node (carry=sum/10)
            sum += carry; 
            carry = sum / 10; 
            Node *node = new Node(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next;
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

    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next = new Node(9);

    Node* head2 = new Node(9);
    head2->next = new Node(9);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);
    // head->next->next->next->next = new Node(5);

    Node* result = sol.addTwoNumbers(head, head2);
    std::cout << "Updated List: " << std::endl;
    sol.printList(result);
    return 0;
}


// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 
// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.