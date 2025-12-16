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

// ----------------------/*Insert Before Head*/------------------
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    
    return newHead;
}

// ----------------------/*Insert Before Tail*/------------------
Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        insertBeforeHead(head, val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    temp->back = newNode;
    prev->next = newNode;
    // newNode->next = temp; //! Note this should be done while making new Node
    // newNode->back = prev;
    return head;
}

// // ----------------------/*Insert Before Kth Elem*/------------------
// Node* insertBeforeKElem(Node* head, int val, int k){
//     Node* temp = head;
//     int count = 0;
//     while(temp->next != NULL){
//         count++;
//         if(count == k) break;
//         temp = temp->next;
//     }
//     //*Edge Cases
//     if(temp->back == nullptr){//meaning head
//         std::cout << "Yesss" << std::endl;
//         return insertBeforeHead(head, val);
//     }
//     if(temp->next == nullptr){//meaning tail
//         return insertBeforeTail(head, val);
//     }
//     Node* prev = temp->back;
//     Node* newNode = new Node(val, temp, prev);
//     prev->next = newNode;
//     temp->back = newNode;

//     return head;
// }

// ----------------------/*Insert Before Node*/------------------
void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main(){
    std::vector <int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);
    std::cout << std::endl;
    std::cout << "Insertions--------------" << std::endl;

    int value = 10;
    int k = 2;
    //---------------------
    // Node* insertedBeforeHead = insertBeforeHead(head, value);
    // print(insertedBeforeHead);
    //-----------------------
    // Node* insertedBeforeTail = insertBeforeTail(head, value);
    // print(insertedBeforeTail);
    // Node* insertedBeforeKElem = insertBeforeKElem(head, value, k);
    // print(insertedBeforeKElem);
    insertBeforeNode(head->next->next, value);
    print(head);

    return 0;
}