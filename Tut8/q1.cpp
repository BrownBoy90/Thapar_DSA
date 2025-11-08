#include <iostream>

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
    std::cout << root->data << " ";
    preOrder(root->left);           
    preOrder(root->right);          
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);           
    std::cout << root->data << " "; 
    inOrder(root->right);          
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);           
    postOrder(root->right);          
    std::cout << root->data << " "; 
}

int main() {
    std::cout << "--- Task 1: Tree Traversals ---" << std::endl;

    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

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
