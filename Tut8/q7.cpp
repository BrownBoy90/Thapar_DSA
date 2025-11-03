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
 * [Task 7] Helper to build tree from Post-order and In-order.
 */
Node* buildTreePostIn(std::vector<int>& postorder, std::map<int, int>& inMap, 
                      int& postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);
    int inIndex = inMap[rootVal];

    // IMPORTANT: Build right subtree *first*
    root->right = buildTreePostIn(postorder, inMap, postIndex, inIndex + 1, inEnd);
    root->left = buildTreePostIn(postorder, inMap, postIndex, inStart, inIndex - 1);

    return root;
}

/**
 * [Task 7] Main function: Construct Tree from Post-order and In-order.
 */
Node* constructFromPostIn(std::vector<int>& postorder, std::vector<int>& inorder) {
    std::map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }
    int postIndex = postorder.size() - 1;
    return buildTreePostIn(postorder, inMap, postIndex, 0, inorder.size() - 1);
}

/**
 * Main function for Task 7.
 */
int main() {
    std::cout << "--- Task 7: Construct from Post-order and In-order ---" << std::endl;
    
    std::vector<int> inorder   = {20, 30, 40, 50, 60, 70, 80};
    std::vector<int> postorder = {20, 40, 30, 60, 80, 70, 50};

    std::cout << "Building tree..." << std::endl;
    Node* root = constructFromPostIn(postorder, inorder);

    std::cout << "In-order of constructed tree (should match original): ";
    inOrder(root);
    std::cout << std::endl;

    return 0;
}
