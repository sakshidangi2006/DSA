#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool checkPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }

    int remaining = targetSum - root->val;

    return checkPathSum(root->left, remaining) ||
            checkPathSum(root->right, remaining);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return checkPathSum(root, targetSum);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int targetSum = 5;

    bool ans = hasPathSum(root, targetSum);
    cout << ans;
    return 0;
}