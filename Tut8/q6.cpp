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
 * Helper to print in-order (to verify the constructed tree)
 */
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

/**
 * [Task 6] Helper to build tree from Pre-order and In-order.
 */
Node* buildTreePreIn(std::vector<int>& preorder, std::map<int, int>& inMap, 
                     int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int inIndex = inMap[rootVal];

    root->left = buildTreePreIn(preorder, inMap, preIndex, inStart, inIndex - 1);
    root->right = buildTreePreIn(preorder, inMap, preIndex, inIndex + 1, inEnd);

    return root;
}

/**
 * [Task 6] Main function: Construct Tree from Pre-order and In-order.
 */
Node* constructFromPreIn(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }
    int preIndex = 0;
    return buildTreePreIn(preorder, inMap, preIndex, 0, inorder.size() - 1);
}

/**
 * Main function for Task 6.
 */
int main() {
    std::cout << "--- Task 6: Construct from Pre-order and In-order ---" << std::endl;
    
    std::vector<int> preorder = {50, 30, 20, 40, 70, 60, 80};
    std::vector<int> inorder  = {20, 30, 40, 50, 60, 70, 80};

    std::cout << "Building tree..." << std::endl;
    Node* root = constructFromPreIn(preorder, inorder);

    std::cout << "In-order of constructed tree (should match original): ";
    inOrder(root);
    std::cout << std::endl;

    return 0;
}
