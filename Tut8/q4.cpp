#include <bits/stdc++.h>

/**
 * A simple structure for a binary tree node.
 */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/**
 * Helper function to insert a new element correctly into a BST.
 */
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

/**
 * [Task 4] Helper function to check if a tree is a BST.
 * Uses a min/max range check.
 */
bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (root == nullptr) {
        return true; // An empty tree is a BST
    }
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

/**
 * [Task 4] Main function to check if a tree is a BST.
 */
bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

/**
 * Main function for Task 4.
 */
int main() {
    std::cout << "--- Task 4: isBST Check ---" << std::endl;

    // 1. Test a valid BST
    Node* goodTree = nullptr;
    goodTree = insert(goodTree, 50);
    insert(goodTree, 30);
    insert(goodTree, 70);
    insert(goodTree, 20);
    insert(goodTree, 40);
    
    std::cout << "Checking a valid BST: " << (isBST(goodTree) ? "Yes, it is a BST." : "No, not a BST.") << std::endl;

    // 2. Test an invalid tree
    Node* badTree = new Node(50);
    badTree->left = new Node(30);
    badTree->right = new Node(70);
    badTree->left->right = new Node(60); // Invalid! Should be < 50
    
    std::cout << "Checking an invalid BST: " << (isBST(badTree) ? "Yes, it is a BST." : "No, not a BST.") << std::endl;

    return 0;
}
