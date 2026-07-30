import java.util.*;

// Class representing a Node in the Binary Tree
class Node { 
    int data;       // Stores the value of the node
    Node left;      // Reference to the left child node
    Node right;     // Reference to the right child node

    // Constructor to initialize a node with a given key
    public Node(int key) {
        data = key;     
        left = null;    
        right = null;   
    }
}

// Class containing the logic for Binary Tree creation
class Solution {
    public Node createBinaryTree() {
        // Creates the root node with key value 1
        Node root = new Node(1);       

        // Creates a left child node for the root with key value 2
        root.left = new Node(2);       

        // Creates a right child node for the root with key value 3
        root.right = new Node(3);      

        // Creates a left child node for the right child of root with key value 5
        root.right.left = new Node(5); 

        return root;
    }
}

// Driver class
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        Node root = solution.createBinaryTree();

        // Tree created, can be used for further operations
    }
}
