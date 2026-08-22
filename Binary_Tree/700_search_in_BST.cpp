#include <iostream>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode*  left;
    TreeNode*  right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
  

TreeNode* searchBST(TreeNode*  root, int val) {
        
    if(root == nullptr) return nullptr;

    TreeNode*  left = searchBST(root->left, val);
    TreeNode*  right = searchBST(root->right, val);

    TreeNode*  check = (root-> val > val) ? left : right;

    return(root != nullptr && root->val == val) ? root : check;
}

void preorder(TreeNode* root) {
    
    if(root == nullptr) return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* ans = searchBST(root, val);
    preorder(ans);
    return 0;
}