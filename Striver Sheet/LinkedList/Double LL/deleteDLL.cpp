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

// ----------------------/*Delete Tail*/-------------------
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

// ----------------------/*Delete kth Elem*/--------------------
Node* deleteKElem(Node* head, int k){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    int count = 0;
    while(temp->next != NULL){
        count++;
        if(count == k){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(temp->back == nullptr){
        Node* prev = temp;
        temp = temp->next;
        prev->next = nullptr;
        delete prev;
    }else if(temp->next == nullptr){
        Node* tail = temp;
        temp->back = nullptr;
        tail->back = nullptr;
        delete tail;
    }else{
        Node* front = temp->next;
        Node* prev = temp->back;
        prev->next = front;
        front->back = prev;
        temp->back = nullptr;
        temp->next = nullptr;
        delete temp;
    }
    return head;
}

// ----------------------/*Remove Given Node*/------------------i
void deleteNode(Node* head){
    Node* temp = head;
    Node* front = temp->next;
    Node* prev = temp->back;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }else{
        prev->next = front;
        front->back = prev;
        temp->back = temp->next = nullptr;
        delete temp;
    }
}

int main(){
    std::vector <int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);
    std::cout << std::endl;
    //------------------//
    // Node* deltedHead = deleteHead(head);
    // print(deltedHead);
    //--------------------//
    // Node* deletedTail = deleteTail(head);
    // print(deletedTail);
    //-------------------//
    // int k = 3;
    // Node* deletedK = deleteKElem(head, k);
    // print(deletedK);
    //-------------------//
    deleteNode(head->next->next);
    print(head);
    return 0;
}