#include <iostream>
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->val << " "; 
        preorderTraversal(root->left); 
        preorderTraversal(root->right); 
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}