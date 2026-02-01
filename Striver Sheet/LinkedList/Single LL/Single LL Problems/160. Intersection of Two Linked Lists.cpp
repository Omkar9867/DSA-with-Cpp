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
    //-------------------------------------------------Brute Force Approach TC->O(N^2) -- SC->O(1) -------------------
    // Node* getIntersectionNode(Node* headA, Node* headB){
    //     while(headB != nullptr){
    //         Node* temp = headA;
    //         while (temp != nullptr){
    //             if(temp == headB){ //! Note donot check value, check node instead 
    //                 return headB;
    //             }else{
    //                 temp = temp->next;
    //             }
    //         }         
    //         headB = headB->next;
    //     }
    //     return NULL;
    // }

    //-------------------------------------------------Better Approach TC->O(N) -- SC->O(N) --//*Hashing*-----------------
    // Node* getIntersectionNode(Node* headA, Node* headB){
    //     std::unordered_set<Node*> st;
    //     while(headA != nullptr){
    //         st.insert(headA);
    //         headA = headA->next;
    //     }
    //     while(headB != nullptr){
    //         if(st.find(headB) != st.end()) return headB;
    //         headB = headB->next;
    //     }
    //     return NULL;
    // }

    //-------------------------------------------------Optimal Approach TC->O(N) -- SC->O(1) -------------------
    // int getDifference(Node* head1, Node* head2) {
    //     int len1 = 0, len2 = 0;
    //     while (head1 != NULL || head2 != NULL) {
    //         if (head1 != NULL) {
    //             ++len1;
    //             head1 = head1->next;
    //         }
    //         if (head2 != NULL) {
    //             ++len2;
    //             head2 = head2->next;
    //         }
    //     }
    //     return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
    // }
    // Node* getIntersectionNode(Node* headA, Node* headB){
    //     int diff = getDifference(headA, headB);
    
    //     if (diff < 0) 
    //         while (diff++ != 0) headB = headB->next;
    //     else 
    //         while (diff-- != 0) headA = headA->next;

    //     while(headA != nullptr){
    //         if (headA == headB) return headA;  // Intersection point found
    //         headB = headB->next;
    //         headA = headA->next;
    //     }
    //     return NULL;
    // }


    //-------------------------------------------------Optimal Approach TC->O(N) -- SC->O(1) -------------------
    //* Take two dummy nodes for each list. Point each to the head of the lists.
    //* Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

    Node* getIntersectionNode(Node* headA, Node* headB){
        Node* d1 = headA;
        Node* d2 = headB;

        while(d1 != d2){
            if (d1 == nullptr){
                d1 = headB;
            }else if(d2 == nullptr){
                d2 = headA;
            }else{
                d1 = d1->next;
                d2 = d2->next;
            }
        }
        return d2;
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

    Node* common = new Node(8);
    common->next = new Node(4);
    common->next->next = new Node(5);

    // List A
    Node* head = new Node(4);
    head->next = new Node(1);
    head->next->next = common;

    // List B
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = common;

    Node* result = sol.getIntersectionNode(head, head2);
    std::cout << "Intersection of the Linked List: " << std::endl;
    sol.printList(result);
    return 0;
}


// 160. Intersection of Two Linked Lists

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:
// The test cases are generated such that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.
// Custom Judge:
// The inputs to the judge are given as follows (your program is not given these inputs):
// intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
// listA - The first linked list.
// listB - The second linked list.
// skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
// skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
// The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 
// Example 1:
// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'
// Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
// - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

// Example 2:
// Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Intersected at '2'
// Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

// Example 3:
// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: No intersection
// Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.
 
// Constraints:
// The number of nodes of listA is in the m.
// The number of nodes of listB is in the n.
// 1 <= m, n <= 3 * 104
// 1 <= Node.val <= 105
// 0 <= skipA <= m
// 0 <= skipB <= n
// intersectVal is 0 if listA and listB do not intersect.
// intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 

// Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?