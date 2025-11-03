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
 * [Task 3a] Inserts a new element into the BST.
 * Does not allow duplicates.
 */
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        std::cout << "Inserted " << key << std::endl;
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        std::cout << "Value " << key << " already exists. No duplicates allowed." << std::endl;
    }
    return root;
}

/**
 * Helper function to find the minimum node (for delete).
 */
Node* findMin(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

/**
 * [Task 3b] Deletes an existing element from the BST.
 */
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        // Case 1: Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


/**
 * [Task 3c] Find the maximum depth (height) of the BST.
 */
int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is 0
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}

/**
 * [Task 3d] Find the minimum depth of the BST.
 */
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    std::queue<std::pair<Node*, int>> q;
    q.push({root, 1}); // Push root with depth 1

    while (!q.empty()) {
        Node* current = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (current->left == nullptr && current->right == nullptr) {
            return depth; // First leaf node found
        }
        if (current->left) q.push({current->left, depth + 1});
        if (current->right) q.push({current->right, depth + 1});
    }
    return 0; // Should not be reached
}

/**
 * Helper to print in-order traversal (to verify deletes)
 */
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}


/**
 * Main function for Task 3.
 */
int main() {
    std::cout << "--- Task 3: Insert, Delete, Depth ---" << std::endl;
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    std::cout << "\nTesting duplicate insert:" << std::endl;
    insert(root, 40); // Test duplicate

    std::cout << "\n--- Depths ---" << std::endl;
    std::cout << "Max Depth: " << maxDepth(root) << std::endl;
    std::cout << "Min Depth: " << minDepth(root) << std::endl;

    std::cout << "\n--- Deletion ---" << std::endl;
    std::cout << "Tree before deletes: "; inOrder(root); std::cout << std::endl;

    // Case 1: Delete a leaf node (20)
    std::cout << "Deleting node 20 (leaf)..." << std::endl;
    root = deleteNode(root, 20);
    std::cout << "Tree state: "; inOrder(root); std::cout << std::endl;

    // Case 2: Delete a node with one child (30)
    std::cout << "Deleting node 30 (one child)..." << std::endl;
    root = deleteNode(root, 30);
    std::cout << "Tree state: "; inOrder(root); std::cout << std::endl;
    
    // Case 3: Delete a node with two children (50)
    std::cout << "Deleting node 50 (two children)..." << std::endl;
    root = deleteNode(root, 50);
    std::cout << "Tree state: "; inOrder(root); std::cout << std::endl;

    return 0;
}
