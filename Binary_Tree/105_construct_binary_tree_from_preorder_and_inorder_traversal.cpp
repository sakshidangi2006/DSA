#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 

TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {

    if(preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int rootIdx = inStart;
    while(inorder[rootIdx] != rootVal) rootIdx++;

    int leftSize = rootIdx - inStart;

    root->left = build(preorder, preStart+1, preStart + leftSize, inorder, inStart, rootIdx-1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootIdx + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

void inorderTraversal(TreeNode* root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout<< root->val <<"->";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = buildTree(preorder, inorder);
    inorderTraversal(root);
    cout<<"NULL";
    return 0;
}