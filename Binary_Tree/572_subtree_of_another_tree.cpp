#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



bool isSame(TreeNode* a, TreeNode* b) {
    if(a == nullptr && b == nullptr) return true;
    if(a == nullptr || b == nullptr) return false;

    if(a->val != b->val) return false;

    bool left = isSame(a->left, b->left);
    bool right = isSame(a->right, b->right);

    return (left && right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr) return false;

    if(subRoot == nullptr) return true;

    if(isSame(root, subRoot)) return true;

    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)); 
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    bool ans = isSubtree(root, subRoot);
    cout << ans;
    return 0;
}