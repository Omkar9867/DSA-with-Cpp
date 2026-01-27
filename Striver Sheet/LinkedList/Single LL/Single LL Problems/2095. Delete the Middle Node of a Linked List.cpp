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
    //--------------------------------------------Brute Force Approach-TC->O(N + N/2) -- SC->O(1)---------------------------------
    // Using the brute force approach, the middle node of a linked list can be determined by traversing the entire linked list initially to find the total number of nodes, denoted as n. 
    // Then we reset the temporary node temp to the head of the linked list and proceed to traverse to the node positioned at index [n/2], 
    // which represents either the middle node in an odd-lengthed list or the node just before the middle node in an even-lengthed linked list.

    // ---------------------------------------------- My Approach TC->O(N) -- SC->O(1)------------------------------
    Node* deleteMiddle(Node* head) {
        Node* temp = head;
        
        if(head == nullptr || head->next == nullptr){
        //----- delete(head)-----;
        // You should NOT delete head manually
        // The platform already frees the entire list afterward
        // By deleting head yourself, you create a double-free / use-after-free
            return nullptr;
        }
        
        Node* fast = temp->next->next;
        Node* slow = temp;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* middle = slow->next;
        slow->next = middle->next;
        delete(middle);
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
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);

    Node* result = sol.deleteMiddle(head);
    std::cout << "After removing Middle Node in Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}

// 2095. Delete the Middle Node of a Linked List

// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 
// Example 1:
// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node. 

// Example 2:
// Input: head = [1,2,3,4]
// Output: [1,2,4]
// Explanation:
// The above figure represents the given linked list.
// For n = 4, node 2 with value 3 is the middle node, which is marked in red.

// Example 3:
// Input: head = [2,1]
// Output: [2]
// Explanation:
// The above figure represents the given linked list.
// For n = 2, node 1 with value 1 is the middle node, which is marked in red.
// Node 0 with value 2 is the only node remaining after removing node 1.
 
// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 1 <= Node.val <= 105