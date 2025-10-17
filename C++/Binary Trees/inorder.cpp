#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left); 
        cout << root->val << " "; 
        inorderTraversal(root->right); 
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;


    return 0;
}