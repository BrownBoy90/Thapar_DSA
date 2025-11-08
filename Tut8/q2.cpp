#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

bool searchNonRecursive(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == key) return true;
        else if (key < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}


Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}


Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node* findNode(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == key) return current;
        else if (key < current->data) current = current->left;
        else current = current->right;
    }
    return nullptr; // Not found
}


Node* InOrderSuccessor(Node* root, int key) {
    // 1. Find the node
    Node* node = findNode(root, key);

    // 2. If node not found or has no right child, return null
    if (node == nullptr || node->right == nullptr) {
        return nullptr;
    }

    // 3. Return the minimum of the right subtree
    return findMin(node->right);
}

// i
Node* InOrderPredecessor(Node* root, int key) {
    // 1. Find the node
    Node* node = findNode(root, key);

    // 2. If node not found or has no left child, return null
    if (node == nullptr || node->left == nullptr) {
        return nullptr;
    }

    // 3. Return the maximum of the left subtree
    return findMax(node->left);
}


/**
 * Main function for Task 2 (Simplified)
 */
int main() {
    std::cout << "--- Task 2: BST Functions (Simplified Successor/Predecessor) ---" << std::endl;
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    //      50
    //    /    \
    //   30     70
    //  / \    /  \
    // 20 40  60  80

    std::cout << "--- (a) Search ---" << std::endl;
    std::cout << "Search 40 (Recursive): " << (searchRecursive(root, 40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 90 (Non-Rec):   " << (searchNonRecursive(root, 90) ? "Found" : "Not Found") << std::endl;

    std::cout << "\n--- (b, c) Min/Max ---" << std::endl;
    std::cout << "Max element: " << findMax(root)->data << std::endl;
    std::cout << "Min element: " << findMin(root)->data << std::endl;

    std::cout << "\n--- (d) Simplified In-order Successor ---" << std::endl;
    // Test Case 1: Node 30. It HAS a right subtree (40).
    Node* succ = InOrderSuccessor(root, 30);
    std::cout << "Successor of 30: " << (succ ? std::to_string(succ->data) : "None") << " (Found 40)" << std::endl;

    // Test Case 2: Node 70. It HAS a right subtree (80).
    succ = InOrderSuccessor(root, 70);
    std::cout << "Successor of 70: " << (succ ? std::to_string(succ->data) : "None") << " (Found 80)" << std::endl;
    
    // Test Case 3: Node 40. It has NO right subtree.
    succ = InOrderSuccessor(root, 40);
    std::cout << "Successor of 40: " << (succ ? std::to_string(succ->data) : "None") << " (Ignored as requested)" << std::endl;


    std::cout << "\n--- (e) Simplified In-order Predecessor ---" << std::endl;
    // Test Case 1: Node 30. It HAS a left subtree (20).
    Node* pred = InOrderPredecessor(root, 30);
    std::cout << "Predecessor of 30: " << (pred ? std::to_string(pred->data) : "None") << " (Found 20)" << std::endl;
    
    // Test Case 2: Node 70. It HAS a left subtree (60).
    pred = InOrderPredecessor(root, 70);
    std::cout << "Predecessor of 70: " << (pred ? std::to_string(pred->data) : "None") << " (Found 60)" << std::endl;

    // Test Case 3: Node 60. It has NO left subtree.
    pred = InOrderPredecessor(root, 60);
    std::cout << "Predecessor of 60: " << (pred ? std::to_string(pred->data) : "None") << " (Ignored as requested)" << std::endl;

    return 0;
}
