#include <bits/stdc++.h>

class Node {
public:
    int data; // Data value
    Node* next; // pointer to next node
    
    // Constructor with data and next
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    std::vector<int> arr = {2, 5, 8, 7};

    // First Node
    Node* y = new Node(arr[0], y);

    // Print memory location of node
    std::cout << y << '\n';

    // Print data stored in the node
    std::cout << y->data << '\n';

    return 0;
}