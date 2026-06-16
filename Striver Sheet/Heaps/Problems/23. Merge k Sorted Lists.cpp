#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode* makeList(std::initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }

    return dummy.next;
}

class Compare {
public:
    // Comparator to order ListNode pointers based on node values
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
//--------------------------------Brute Force--TC->O(NlogN)----------------------------
    // ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    //     std::vector<int> allValues;

    //     for (auto list : lists) {
    //         while (list != NULL) {
    //             allValues.push_back(list->val);
    //             list = list->next;
    //         }
    //     }

    //     // Sort
    //     sort(allValues.begin(), allValues.end());

    //     // Create a dummy head for the final result list
    //     ListNode* dummy = new ListNode(0);
    //     ListNode* curr = dummy;

    //     // Create new linked list nodes from sorted values
    //     for (int val : allValues) {
    //         curr->next = new ListNode(val);// Note to make Node of the value
    //         curr = curr->next;
    //     }
        
    //     return dummy->next;
    // }

//--------------------------------Optimal Approach--TC->O(NlogK)----------------------------
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

        for(auto list : lists){
            if(list != NULL){
                pq.push(list); // Here are only the first pointers.
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // While the heap is not empty
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            // If there's a next node, push it into the heap
            if (smallest->next != NULL)
                pq.push(smallest->next);
        }

        return dummy->next;
    }


    void printList(ListNode* head){
        while(head != nullptr){
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

};

int main(){
    std::vector<ListNode*> lists = {
        makeList({1, 4, 5}),
        makeList({1, 3, 4}),
        makeList({2, 6})
    };
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);
    
    return 0;
}


// 23. Merge k Sorted Lists

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []
 
// Constraints:
// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.