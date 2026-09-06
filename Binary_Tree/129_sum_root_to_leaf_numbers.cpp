#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int traverse(TreeNode* root, int sum) {
    if(root == nullptr) return 0;
    
    sum = (sum * 10 ) + root->val;

    if(root->left == nullptr && root->right == nullptr) return sum;

    int leftSum = traverse(root->left, sum);
    int rightSum = traverse(root->right, sum);

    return leftSum + rightSum;
} 

int sumNumbers(TreeNode* root) {
    int sum = 0;
    return traverse(root,sum);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int ans = sumNumbers(root);
    cout << ans;
    return 0;
}
