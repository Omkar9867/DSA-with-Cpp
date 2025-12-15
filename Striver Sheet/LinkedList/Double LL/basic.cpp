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

// ----------------------/*Delete Head*/------------------
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

// ----------------------/*Delete Tail*/------------------
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    while(head != NULL){
        if(head->next == NULL){
            Node* prev = head;
            head->back->next = nullptr;
            prev->back = nullptr;
            delete prev; 
            break;
        }
        head = head->next;
    }
    return head;
}

int main(){
    std::vector <int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);
    std::cout << std::endl;
    Node* deltedHead = deleteHead(head);
    print(deltedHead);
    Node* deltedTail = deleteTail(head);
    print(deltedTail);
    return 0;
}