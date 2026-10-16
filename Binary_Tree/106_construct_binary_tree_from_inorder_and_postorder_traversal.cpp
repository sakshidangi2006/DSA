#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 

TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>postorder, int postStart, int postEnd) {

    if(postStart > postEnd || inStart > inEnd) return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootIdx = inStart;
    while(inorder[rootIdx] != rootVal) rootIdx++;

    int leftSize = rootIdx - inStart;

    root->left = build(inorder, inStart, rootIdx-1, postorder, postStart, postStart + leftSize - 1);

    root->right = build(inorder, rootIdx + 1, inEnd, postorder, postStart + leftSize, postEnd-1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    
}

void inorderTraversal(TreeNode* root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout<< root->val <<"->";
    inorderTraversal(root->right);
}

int main() {
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = buildTree(inorder, postorder);
    inorderTraversal(root);
    cout<<"NULL";
    return 0;
}