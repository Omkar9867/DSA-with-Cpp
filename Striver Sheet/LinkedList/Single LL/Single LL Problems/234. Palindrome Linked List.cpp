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
    bool isPalindrome(Node *head) {
        std::stack<int> st;

        Node* temp = head;

        // Traverse the linked list and push values onto the stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next; 
        }

        // Reset
        temp = head;

        // Compare values by popping from the stack and checking against linked list nodes
        while (temp != NULL) {
            if (temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next; 
        }

        // If all values match, it's a palindrome
        return true;
    }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    // bool isPalindrome(Node *head) {

    // }

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

    bool result = sol.isPalindrome(head);
    std::cout << "Result of isPalindrome is : "<< result << std::endl;
    return 0;
}