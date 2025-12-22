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
    // bool isPalindrome(Node *head) {
    //     std::stack<int> st;

    //     Node* temp = head;

    //     // Traverse the linked list and push values onto the stack
    //     while (temp != NULL) {
    //         st.push(temp->val);
    //         temp = temp->next; 
    //     }

    //     // Reset
    //     temp = head;

    //     // Compare values by popping from the stack and checking against linked list nodes
    //     while (temp != NULL) {
    //         if (temp->val != st.top()) {
    //             return false;
    //         }
    //         st.pop();
    //         temp = temp->next; 
    //     }

    //     // If all values match, it's a palindrome
    //     return true;
    // }

    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    // Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.
    // Key Solution: After finding the middle, then reversing the second have and looping from head to middle and (reversed)->middle to tail
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;  // It's a palindrome by definition
        }
        Node* fast = head;
        Node* slow = head;
        Node* temp = head;
        while(fast != NULL && fast->next != nullptr){ //1. Find the middle
            slow = slow->next;
            fast = fast->next->next;
        };
        Node* reversedNode = reverseNode(slow); //2. reverse the second half from the middle
        while(temp != slow && reversedNode != NULL){ //3. compare from temp i.e. head to middle --to-- middle to tail
            if(temp->val != reversedNode->val){
                return false;
            }
            temp = temp->next;
            reversedNode = reversedNode->next;
        }
        return true;
    }

    Node* reverseNode(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        };
        return prev;
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
    Node* nodeSecond = head->next;
    // std::cout << nodeSecond->val << std::endl;
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    bool result = sol.isPalindrome(head);
    std::cout << "Result of isPalindrome is : "<< result << std::endl;
    // Node* reversedNode = sol.reverseNode(head);
    // sol.printList(reversedNode);
    return 0;
}