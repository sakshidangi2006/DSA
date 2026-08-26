#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = postorderTraversal(root);

    for(int a : ans) {
        cout << a <<" ";
    }
    return 0;
}