#include <bits/stdc++.h>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//!Understand well
class Solution {
public:
    std::vector<std::vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        std::vector<int> pre, in, post;

        // If the tree is empty,
        // return empty traversals
        if (root == NULL) {
            return {};
        }

        // Stack to maintain nodes
        // and their traversal state
        std::stack<std::pair<Node*, int>> st;

        // Start with the root node
        // and state 1 (preorder)
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        std::vector<std::vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;
    
    // Getting the pre-order, in-order,
    // and post-order traversals
    std::vector<int> pre, in, post;
    std::vector<std::vector<int>> traversals = sol.preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    std::cout << "Preorder traversal: ";
    for (int val : pre) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    for (int val : in) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    for (int val : post) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}


// Preorder Inorder Postorder Traversals in One Traversal

// Problem Statement: Given the root of a Binary Tree, return the preorder, inorder and postorder traversal sequence of the given tree by making just one traversal.

// Examples

// Input: Binary Tree: 4 2 5 3 -1 7 6 -1 9 -1 -1 8 -1 1
// ./Preorder Inorder Postorder Traversals in One Traversal1.png
// Output: Preorder: [4, 2, 3, 9, 1, 5, 7, 6, 8], Inorder: [3, 1, 9, 2, 4, 7, 5, 8, 6], Postorder: [1, 9, 3, 2, 7, 8, 6, 5, 4] 
// Explanation:
// ./Preorder Inorder Postorder Traversals in One Traversal2.png

// Input: Binary Tree: 1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 9 10

// Output: Preorder: [1, 2, 4, 5, 8, 3, 6, 7, 9, 10], Inorder: [4, 2, 8, 5, 1, 6, 3, 9, 7, 10], Postorder: [4, 8, 5, 2, 6, 9, 10, 7, 3, 1] 
// Explanation: The three traversal of the tree are given above.