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
    //-----------------Time Complexity: O(n), We traverse the entire list once. -----------Space Complexity: O(1), Only dummy nodes and pointers are used (constant space).
    Node* sortZeroOneTwo(Node* head) {
        // Have heads in place
        Node* zeroNode = new Node(-1);
        Node* oneNode = new Node(-1);
        Node* twoNode = new Node(-1);

        //Add values for tails
        Node* zeroTail = zeroNode;
        Node* oneTail = oneNode;
        Node* twoTail = twoNode;
        
        Node* temp = head;
        while(temp != nullptr){
            if(temp->val == 0){
                zeroTail->next = temp;  //* Note to assign Node and nnot only the val 
                zeroTail = zeroTail->next;
            }else if(temp->val == 1){
                oneTail->next = temp;
                oneTail = oneTail->next;
            }else{
                twoTail->next = temp;
                twoTail = twoTail->next;
            }
            temp = temp->next;
        }
        // Connect the three lists:
        // zeroTail -> oneNode.next -> twoNode.next // beacuse initial value was -1
        // Handle edge cases if 0s or 1s list is empty
        zeroTail->next = oneNode->next ? oneNode->next : twoNode->next;
        oneTail->next = twoNode->next;
        twoTail->next = nullptr;
        temp = zeroNode->next;

        delete zeroNode;
        delete oneNode;
        delete twoNode;

        return temp;
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
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    Node* result = sol.sortZeroOneTwo(head);
    std::cout << "After removing Middle Node in Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}


// Sort a Linked List of 0's 1's and 2's by changing links

// Problem Statement: Given a linked list containing only 0's, 1's, and 2's, sort the linked list by rearranging the links (not by changing the data values).

// Examples
// Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
// Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL