#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool check(TreeNode* root, long long minVal, long long maxVal) {

    if(root == nullptr) return true;
    if(root->val <= minVal || root->val >= maxVal) return false;

    return check(root->left, minVal, root->val) && check(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool ans = isValidBST(root);
    cout << ans;
    return 0;
}