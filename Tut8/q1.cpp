#include <iostream>

// A simple structure for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to easily create a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " "; // Visit root
    preOrder(root->left);           // Recurse left
    preOrder(root->right);          // Recurse right
}

/**
 * [Task 1] In-order traversal (Left -> Root -> Right)
 * For a BST, this prints the nodes in sorted order.
 */
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);           // Recurse left
    std::cout << root->data << " "; // Visit root
    inOrder(root->right);          // Recurse right
}

/**
 * [Task 1] Post-order traversal (Left -> Right -> Root)
 */
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);           // Recurse left
    postOrder(root->right);          // Recurse right
    std::cout << root->data << " "; // Visit root
}

/**
 * Main function for Task 1.
 */
int main() {
    std::cout << "--- Task 1: Tree Traversals ---" << std::endl;

    // Build a sample tree
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Tree structure:
    //      50
    //    /    \
    //   30     70
    //  / \    /  \
    // 20 40  60  80

    std::cout << "Pre-order:  ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In-order:   ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postOrder(root);
    std::cout << std::endl;

    return 0;
}
