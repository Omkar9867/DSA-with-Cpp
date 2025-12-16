#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor with data and next and back
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node * convertArr2DLL(std::vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        std::cout << head->data << " ";
        head = head->next; 
    }
}

// ----------------------------------Brute Force Approach 2parse solution with SC->O(N)-------------------------
// Node* reverseDLL(Node* head){
//     Node* temp = head;
//     std::stack<int> st;
//     while(temp != NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp != NULL){
//         Node* prev = temp->back;
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;
// }

// ----------------------------------Optimal Approach TC->O(N)/ SC->O(N) -------------------------------
Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        prev = temp->back;

        temp->back = temp->next;
        temp->next = prev;

        temp = temp->back; //!Note here you are swap the next, so now we have to go back
    }
    return prev->back; //!Note prev will be pointing before the temp, techniqally prev's back will be the head
}

int main(){
    std::vector <int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);
    std::cout << std::endl;

    Node* reversedDll = reverseDLL(head);
    print(reversedDll);

    return 0;
}