#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 

int ans = 0;

int diameter(TreeNode* root) {
    if(root == nullptr) return 0;

    int left = diameter(root->left);
    int right = diameter(root->right);

    int sum = left + right;
    ans = max(sum,ans);
    return 1 + max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
    diameter(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    int ans = diameterOfBinaryTree(root);
    cout << ans;
    return 0;
}
