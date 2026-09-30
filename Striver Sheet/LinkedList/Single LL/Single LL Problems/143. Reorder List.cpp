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
    void reorderList(Node *head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        std::vector<Node*> nodes;
        Node* current = head;

        while(current != nullptr){
            nodes.push_back(current);
            current = current->next;
        }

        int left = 0, right = (int)nodes.size() - 1;
        while(left < right){
            nodes[left]->next = nodes[right];
            left++;
            if(left == right){
                break;
            }
            nodes[right]->next = nodes[left];
            right--;
        }
        // End the reordered linked list. //!understand this
        nodes[left]->next = nullptr;
    }

private:
    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* reverseLL(Node* head) {
        Node* previous = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;

            current->next = previous;

            previous = current;
            current = nextNode;
        }
        return previous;
    }

    void mergeLists(Node* first, Node* second) {
        while (second != nullptr) {
            Node* firstNext = first->next;
            Node* secondNext = second->next;

            first->next = second;

            second->next = firstNext;

            // Move both pointers to their next available nodes.
            first = firstNext;
            second = secondNext;
        }
    }
public:
    // ---------------------------------------------- Optimal Approach TC->O(N) -- SC->O(1)------------------------------
    void reorderList(Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* middle = findMid(head);

        Node* second = middle->next;
        middle->next = nullptr;

        second = reverseLL(second);

        // Merge the first half and reversed second half alternately.
        mergeLists(head, second); //!understand why head and not middle
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

    Node* head = new Node(3);
    head->next = new Node(2);
    Node* nodeSecond = head->next;
    // std::cout << nodeSecond->val << std::endl;
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = nodeSecond;

    sol.reorderList(head);
    std::cout << "Result of cycle LL is : "<< head << std::endl;
    return 0;
}

// 143. Reorder List

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 
// Constraints:
// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000
 