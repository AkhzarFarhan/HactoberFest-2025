#include <iostream>
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
        cout << root->val << " "; 
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);


    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}