#include <bits/stdc++.h>



//!Understand well
class LRUCache {
public:
    // Maintain a Doubly Linked List to track the usage order, with the most recently used node at the head and the least recently used at the tail.
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key1, int val1) {
            key = key1;
            val = val1;
        }
    };

    // Head and tail dummy nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Capacity of cache
    int cap;
    // Key <-> Node mapping
    std::unordered_map<int, Node*> m;


    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Add right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove a given node from list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        // If key exists in cache
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            // Remove old mapping
            m.erase(key);
            // Move accessed node to front
            deleteNode(resNode);
            addNode(resNode);
            // Update map
            m[key] = head->next;
            return res;
        }

        return -1;
    }


    void put(int key, int value) {
        // If key already exists
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        // If capacity reached
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // Insert new node at front
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};


int main() {
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    std::cout << cache.get(1) << std::endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    std::cout << cache.get(2) << std::endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    std::cout << cache.get(1) << std::endl; 

    // Key 3 should be present
    std::cout << cache.get(3) << std::endl; 

    // Key 4 should be present
    std::cout << cache.get(4) << std::endl; 

    return 0;
}

//*The intuition behind an LRU (Least Recently Used) Cache is that we want to store only a fixed number of items in memory and quickly evict the item that hasn’t been used for the longest time. 
//*This is useful when memory is limited and we want to keep the most relevant data available for fast retrieval. 
//*The key idea is to maintain quick lookups to check if a value exists in the cache, 
//*and also maintain the usage order so we can remove the least recently used item efficiently when the cache is full.

// 146. LRU Cache

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
// If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.