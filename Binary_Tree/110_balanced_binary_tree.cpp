#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int height(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int left = height(root->left);
    if (left == -1)
        return -1;

    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    bool ans = isBalanced(root);
    cout << ans;
    return 0;

}