#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool ans = false;

void traverse(TreeNode* root, int sum, int targetSum) {
    if (root == nullptr) return;

    sum += root->val;

    if (root->left == nullptr && root->right == nullptr) {
        if (sum == targetSum) {
            ans = true;
        }
        return;
    }

    traverse(root->left, sum, targetSum);
    traverse(root->right, sum, targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    traverse(root, 0, targetSum);

    return ans;
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