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
 * Helper function to insert a new element into the BST.
 */
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

/**
 * [Task 5] Non-recursive in-order traversal using a stack.
 */
void inOrderIterative(Node* root) {
    std::stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // 1. Go all the way left, pushing nodes onto the stack
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // 2. Pop the last-pushed (leftmost) node
        current = s.top();
        s.pop();

        // 3. Visit the node
        std::cout << current->data << " ";

        // 4. Move to the right subtree
        current = current->right;
    }
}


/**
 * Main function for Task 5.
 */
int main() {
    std::cout << "--- Task 5: Iterative In-order ---" << std::endl;

    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Iterative In-order: ";
    inOrderIterative(root);
    std::cout << std::endl;

    return 0;
}
