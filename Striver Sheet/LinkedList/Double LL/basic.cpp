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

Node* convertArr2DLL(std::vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){ //Will start from 1 
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; //! Important step: Cause the prev's next is currently pointing to null
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        std::cout << head->data << " ";
        head = head->next; 
    }
}

int main(){
    std::vector <int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);
    return 0;
}