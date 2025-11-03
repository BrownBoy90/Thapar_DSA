#include <iostream>

/**
 * A simple structure for a binary tree node.
 */
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
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
 * [Task 2a] Search for an item (Recursive)
 */
bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

/**
 * [Task 2a] Search for an item (Non-Recursive)
 */
bool searchNonRecursive(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == key) return true;
        else if (key < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

/**
 * [Task 2c] Find the minimum element in the BST.
 */
Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

/**
 * [Task 2b] Find the maximum element in the BST.
 */
Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

/**
 * [Task 2d] Find the In-order successor of a given node (key).
 */
Node* inOrderSuccessor(Node* root, int key) {
    Node* successor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (key < current->data) {
            successor = current;
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            if (current->right != nullptr) {
                successor = findMin(current->right);
            }
            break;
        }
    }
    return successor;
}

/**
 * [Task 2e] Find the In-order predecessor of a given node (key).
 */
Node* inOrderPredecessor(Node* root, int key) {
    Node* predecessor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (key < current->data) {
            current = current->left;
        } else if (key > current->data) {
            predecessor = current;
            current = current->right;
        } else {
            if (current->left != nullptr) {
                predecessor = findMax(current->left);
            }
            break;
        }
    }
    return predecessor;
}

/**
 * Main function for Task 2.
 */
int main() {
    std::cout << "--- Task 2: BST Functions ---" << std::endl;
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // (a) Search
    std::cout << "Search 40 (Recursive): " << (searchRecursive(root, 40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 90 (Non-Rec):   " << (searchNonRecursive(root, 90) ? "Found" : "Not Found") << std::endl;

    // (b) Max Element
    Node* maxNode = findMax(root);
    if (maxNode) std::cout << "Max element: " << maxNode->data << std::endl;

    // (c) Min Element
    Node* minNode = findMin(root);
    if (minNode) std::cout << "Min element: " << minNode->data << std::endl;

    // (d) In-order Successor
    Node* succ = inOrderSuccessor(root, 40);
    if (succ) std::cout << "Successor of 40: " << succ->data << std::endl;
    succ = inOrderSuccessor(root, 80);
    std::cout << "Successor of 80: " << (succ ? std::to_string(succ->data) : "None") << std::endl;
    
    // (e) In-order Predecessor
    Node* pred = inOrderPredecessor(root, 40);
    if (pred) std::cout << "Predecessor of 40: " << pred->data << std::endl;
    pred = inOrderPredecessor(root, 20);
    std::cout << "Predecessor of 20: " << (pred ? std::to_string(pred->data) : "None") << std::endl;

    return 0;
}
