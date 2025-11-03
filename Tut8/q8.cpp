#include <bits/stdc++.h>

/**
 * A simple structure for a binary tree node.
 * We will re-use 'left' as 'prev' and 'right' as 'next' for the DLL.
 */
struct Node {
    int data;
    Node* left;  // Will act as 'prev'
    Node* right; // Will act as 'next'
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/**
 * Helper function to insert a new element into the BST.
 */
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

/**
 * [Task 8] Helper to get in-order traversal into a vector.
 */
void getInOrderVector(Node* root, std::vector<int>& vec) {
    if (root == nullptr) return;
    getInOrderVector(root->left, vec);
    vec.push_back(root->data);
    getInOrderVector(root->right, vec);
}

/**
 * [Task 8] Merges two BSTs into a sorted Doubly-Linked List.
 */
Node* mergeBSTsToDLL(Node* root1, Node* root2) {
    std::vector<int> v1, v2;
    getInOrderVector(root1, v1);
    getInOrderVector(root2, v2);

    std::vector<int> merged;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(merged));

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : merged) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->right = newNode; // tail->next = newNode
            newNode->left = tail;  // newNode->prev = tail
            tail = newNode;
        }
    }
    return head;
}

/**
 * Helper function to print the doubly-linked list.
 */
void printDLL(Node* head) {
    Node* current = head;
    std::cout << "null <-> ";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->right) {
            std::cout << " <-> ";
        }
        current = current->right;
    }
    std::cout << " <-> null" << std::endl;
}

/**
 * Main function for Task 8.
 */
int main() {
    std::cout << "--- Task 8: Merge BSTs to DLL ---" << std::endl;
    
    // Build T1 from example
    Node* t1 = nullptr;
    t1 = insert(t1, 20);
    insert(t1, 10);
    insert(t1, 30);
    
    // Build T2 from example
    Node* t2 = nullptr;
    t2 = insert(t2, 50);
    insert(t2, 5);
    insert(t2, 70);
    insert(t2, 25);
    insert(t2, 100);

    std::cout << "Merging T1 (10, 20, 30) and T2 (5, 25, 50, 70, 100)..." << std::endl;
    Node* dllHead = mergeBSTsToDLL(t1, t2);
    
    std::cout << "Merged Doubly-Linked List:" << std::endl;
    printDLL(dllHead);

    return 0;
}
