#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* p, TreeNode* q) {
        
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;

    bool r1 = isMirror(p->left, q->right);
    bool r2 = isMirror(p->right, q->left);

    return (r1 == true && r2 == true) ? true : false;
}
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;

    return isMirror(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool ans = isSymmetric(root);
    cout << ans;
    return 0;
}